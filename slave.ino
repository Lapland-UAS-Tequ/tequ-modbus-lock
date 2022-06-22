#include <ModbusRtu.h>
#include <EEPROM.h>

Modbus slave;

// data array for modbus network sharing
uint16_t au8data[] = {0,1};

const int Relay = D3;

int addr = 0;

void changeID(uint8_t val) {
  EEPROM.write(addr, val);
  EEPROM.commit();
  slave = Modbus(EEPROM.read(addr), Serial1, 0);
}

void setup() {
  Serial1.begin( 115200 ); // baud-rate at 19200
  EEPROM.begin(512);
  slave = Modbus(EEPROM.read(addr), Serial1, 0);
  slave.start();
  pinMode(Relay, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  au8data[1] = EEPROM.read(addr);
}

void loop() {
  slave.poll( au8data, 2 );

  if (au8data[0] == 0) {
    digitalWrite(Relay, LOW);
  } else {
    digitalWrite(Relay, HIGH);
  }

  if (au8data[1] != EEPROM.read(addr)) {
    
    if (au8data[1] > 0 && au8data[1] <= 247) {
      changeID(au8data[1]);
    }
    else {
      au8data[1] = EEPROM.read(addr);
    }
    
  }

}
