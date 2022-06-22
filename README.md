# tequ-modbus-lock
Seeed XIAO RP2040 compatible lock controlled via Modbus.

## Requirements
- [Arduino IDE](https://www.arduino.cc/en/software)
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

| Part | Part Pin | Pin to connect |
| ---- | -------- | -------------- |
| Grove RS485 | TX | XIAO RX |
| Grove RS485 | RX | XIAO TX |
| Grove Relay | - | D8 (pins 8 and 9) |
| 12v Lock | Red | Relay Green part hole|
| 12v Lock | Black | GND |
| Grove Relay | Other Green part hole | VIN +12V |
| Converter | VIN | 12v Input + |
| Converter | GND | 12v Input - |
| Converter | VOUT | XIAO 5V |
| Converter | GND | GND |

### With Grove Shield

| Part | Pin to connect on shield |
| ---- | -------------- |
| Grove RS485 | TX and RX |
| Grove Relay | D3 |
| 12v Lock | Red | Relay Green part |
| 12v Lock | Black | GND |
| Grove Relay | Other Green part hole | VIN +12V |
| Converter | VIN | 12v Input + |
| Converter | GND | 12v Input - |
| Converter | VOUT | XIAO 5V |
| Converter | GND | GND |
