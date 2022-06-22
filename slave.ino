#include <ModbusRtu.h>
#include <EEPROM.h>

// Initiate Modbus library
Modbus slave;

// Create data array
uint16_t au8data[] = {0,1};

// Relay PIN
const int Relay = D3;

// EEPROM address the read/write Slave ID
int addr = 0;

void changeID(uint8_t val) {
  EEPROM.write(addr, val);
  EEPROM.commit();
  slave = Modbus(EEPROM.read(addr), Serial1, 0);
}

void setup() {
  Serial1.begin( 115200 ); // Baud-rate at 115200
  EEPROM.begin(512); // How many bytes
  slave = Modbus(EEPROM.read(addr), Serial1, 0); // Serial1 is for RX and TX pins on XIAO RP2040, may differ in different microcontrollers (eg. Serial)
  slave.start();
  pinMode(Relay, OUTPUT); 
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  au8data[1] = EEPROM.read(addr); // Set registery address 1 to Slave ID in EEPROM
}

void loop() {
  slave.poll( au8data, 2 );

  // If registery address 0 data is 0, the lock is unpowerd, else powered.
  if (au8data[0] == 0) {
    digitalWrite(Relay, LOW);
  } else {
    digitalWrite(Relay, HIGH);
  }


  // If address 1 data doesn't match Slave ID saved in EEPROM, then update EEPROM data with address 1 data only if address 1 data is between 1 and 247.
  if (au8data[1] != EEPROM.read(addr)) {
    
    if (au8data[1] > 0 && au8data[1] <= 247) {
      changeID(au8data[1]);
    }
    else {
      au8data[1] = EEPROM.read(addr);
    }
    
  }

}
