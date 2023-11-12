/*********
 * Code by SaiPanneerselvam on GitHub part of "ESPBoard" Project/
*********/

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

MDNSResponder mdns;

// Replace with your network credentials
const char* ssid = "RT-N";
const char* password = "WiFiPa55word";

ESP8266WebServer server(80);
String webSite="";
int sensorPin=12;
int led0=13;
int led1= 4;
int led2 = 5;
int ledSensor=16;

  
void setup(void){
  
  webSite +="<!DOCTYPE html>";
  webSite +="<html><head><script src='https://raw.githubusercontent.com/SaiPanneerselvam/ESPBoard/main/static/stac/y/app-update.js'></script><style>\n";
  webSite +="@import url('https://fonts.googleapis.com/css2?family=Poppins&display=swap'); body { background-color:black; color:aliceblue; font-family: Poppins; } .center { text-align: center; }\n";
  webSite+="</style></head><body>\n";
  webSite+="    <h1 class='center'>ESPBoard</h1><h5 class='center'>By SaiPanneerselvam</h5>\n";
  webSite +="<div id='update'></div>\n";
  webSite += "<div id='appsmenu'></div>\n";
  webSite +="</body></html>\n";
  
  // preparing GPIOs
  pinMode(led0, OUTPUT);
  digitalWrite(led0, LOW);
  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
  pinMode(led2, OUTPUT);
  digitalWrite(led2, LOW);
  pinMode(sensorPin,INPUT);
  pinMode(ledSensor,OUTPUT);
  
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  digitalWrite(led0,HIGH);
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
 if (mdns.begin("esp8266", WiFi.localIP())) {
   Serial.println("MDNS responder started");
  }
    server.on("/", [](){
    server.send(200, "text/html", webSite);
    });
  server.on("/socket1On", [](){
    server.send(200, "text/html", webSite);
    digitalWrite(led1, HIGH);
  });
  server.on("/socket1Off", [](){
    server.send(200, "text/html", webSite);
    digitalWrite(led1, LOW);
  });
  server.on("/socket2On", [](){
    server.send(200, "text/html", webSite);
    digitalWrite(led2, HIGH); 
  });
  server.on("/socket2Off", [](){
    server.send(200, "text/html", webSite);
    digitalWrite(led2, LOW);
  });
    
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void){
  server.handleClient();
  String sentences="<p>Flame is detected!!!</p>";
  if(WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(led0, LOW);
    Serial.println("");
    Serial.print("Wifi is disconnected!");
    Serial.println("");
    Serial.print("Reconnecting");
    Serial.println("");
    //WiFi.begin(ssid,password);
    
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }
    digitalWrite(led0,HIGH);
  }
 
  if(digitalRead(sensorPin) ==LOW) 
  {
   Serial.print("Flame is detected");
   Serial.println("");
   webSite+=sentences;
   digitalWrite(ledSensor,HIGH);
   delay(300);
   
  }
  else                            //if no detect
  {
   digitalWrite(ledSensor,LOW);
  }

} 

