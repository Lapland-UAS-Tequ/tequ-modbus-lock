# tequ-modbus-lock
Seeed XIAO RP2040 compatible lock controlled via Modbus.

## NOTE! This code stores data to the onboard EEPROM, to store the devices Slave ID. If your device does not have EEPROM, you may need to use Flash EEPROM or other alternatives.

## Requirements
- [Arduino IDE](https://www.arduino.cc/en/software)
- [Node-Red](https://nodered.org/docs/getting-started/)
- [Seeed XIAO RP2040](https://www.seeedstudio.com/XIAO-RP2040-v1-0-p-5026.html) (you can use other microcontrollers, but you may have to modify the code and connections)
- [12v Solenoid lock](https://www.sparkfun.com/products/15324), or similar
- [Grove Relay](https://www.seeedstudio.com/Grove-Relay.html)
- [Grove RS485](https://www.seeedstudio.com/Grove-RS485-p-2924.html)
- [12v to 5v converter](https://www.sparkfun.com/products/15208) (other converters can be used)
- 12v power supply
- (Optional: [Grove Shield](https://www.seeedstudio.com/Grove-Shield-for-Seeeduino-XIAO-p-4621.html))

## Connecting the parts

This table shows the data pin connections, some power connections have been left out. If you want to use the Grove Shield, see the table below the current one.

## NOTE! Make sure to set the 12v to 5v converter to output 5V with the onboard switch.

### Without Grove Shield

![XIAO Pinout](https://files.seeedstudio.com/wiki/XIAO-RP2040/img/xinpin.jpg)

| Part | Part Pin | Pin to connect |
| ---- | -------- | -------------- |
| Grove RS485 | TX | XIAO RX |
| Grove RS485 | RX | XIAO TX |
| Grove Relay | NC | D2 |
| Grove Relay | SIG | D3 |
| 12v Lock | Red | Relay Green part hole|
| 12v Lock | Black | GND |
| Grove Relay | Other Green part hole | VIN +12V |
| Converter | VIN | 12v Input + |
| Converter | GND | 12v Input - |
| Converter | VOUT | XIAO 5V |
| Converter | GND | GND |

### With Grove Shield

![XIAO Pinout](https://files.seeedstudio.com/wiki/Grove-Shield-for-Seeeduino-XIAO/img/pinout.png)

| Part | Pin to connect on shield |
| ---- | -------------- |
| Grove RS485 | TX and RX |
| Grove Relay | D2 |
| 12v Lock | Red | Relay Green part |
| 12v Lock | Black | GND |
| Grove Relay | Other Green part hole | VIN +12V |
| Converter | VIN | 12v Input + |
| Converter | GND | 12v Input - |
| Converter | VOUT | XIAO 5V |
| Converter | GND | GND |

## Uploading code

You'll need to install the required Modbus libraries and the XIAO board to upload the code.

### Installing board libraries
1. Open the Arduino IDE
2. From the tool menu select Tools --> Board --> Boards Manager
3. In the new windows search for "XIAO RP2040" and install version 1.9.3 (At the time of writing, the latest version were not working properly)

### Installing a Modbus library
You'll need the Modbus library that you can download from [here](https://github.com/smarmengol/Modbus-Master-Slave-for-Arduino), install it via the instructions there and once installed goto next step.

### Uploading Code
If everything has worked so far, you should just be able to upload the code, if you are experiencing errors, check these:
- What XIAO RP2040 Board version do you have? (Recommended: v1.9.1)
- Is the XIAO connected to USB?
- Is the XIAO getting power? (Red LED should be on)
- Is the device in Bootloader mode? (Press and hold the B button and the press the R button, you should see RP1-RP2 in file manager)

## Communication
To control the lock, you'll need to modify the internal registery.
| Address | Purpose |
| ------- | ------- |
| 0 | 0 = Lock unpowered, Not 0 = Lock Powered |
| 1 | Slave ID (accepts number between 1-247) |

The provided node-red flow can Lock, Unlock and Unlock for x seconds.

### To use the flow, you'll need to install a Modbus module. You can either download it via CLI:

```
cd .node-red
npm install node-red-contrib-modbus
node-red-restart
```
### Or you can install it via the node-red interface:
1. Select the hamburger (3 horizontal lines) in the top right corner
2. Click on Manage palette
3. Select Install
4. Search for "node-red-contrib-modbus"
5. Click on install

### Importing the flow
1. Download the provided flows.json and goto your Node-Red interface.
2. Press CTRL + I and "select a file to import"
3. Then just open the flows.json file.
