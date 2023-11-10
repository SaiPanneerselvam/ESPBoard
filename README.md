# ESPBoard
###### A simple ESP8266 (ESP8265) Board made in Arduino (.ino) code with a simple user interface.
ESPBoard is an open-source project that makes a simple UI for the ESP8266 WiFi Board.
### What is the ESP8266?
The ESP8266 is a small microprocessor-like board that has a WiFi Chip in it. Even though its a tiny board, the circuits around the chip can do a lot, even working as a low voltage Web Server! It also can be a standalone device!
### How to use ESPBoard
#### Setting up your Arduino interface
To do this ESPBoard project, you need the Arduino Interface. Download the Arduino IDE, if not done so already. It can be downloaded at https://arduino.cc. Then you need to setup the Arduino IDE for your board, because the ESP8266 board is not directly an Arduino-supported board by default. To add the ability to connect to an unofficial ESP board, you have to first open the IDE and go to File > Preferences. Then scroll down to Additional Boards Manager, and write the url as "http://arduino.esp8266.com/stable/package_esp8266com_index.json". Click OK and close it. Next go to Tools > Board > Board Manager. Go to the search box and type "esp8266", and a file called esp8266 by esp8266 community will appear. Install this software, and then connect your ESP8266 via MicroUSB wire to your computer. Now that the board is connected, go to select board and Unknown (with the serial port you connected the board to). The IDE will ask you for the Board name, search Generic ESP8266 Module, and choose it. Press OK and close the dialogue. Now the interface is set up.
#### Writing the code
This probably will be the easiest part. Copy the code below and paste it into the .ino file.
```
sdx.micro.soft
```
