#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
byte value;

void setup() {
  // initialize serial and wait for port to open:
  Serial.begin(115200);  
  EEPROM.begin(512);
}

void loop() {
  // read a byte from the current address of the EEPROM
  EEPROM.write(address, address+1);
  value = EEPROM.read(address);

  Serial.print("address=");
  Serial.print(address);
  Serial.print(", data=");
  Serial.print(value, DEC);
  Serial.println();

  address++;

  if (address == 512) {
    address = 0;
  }
  
  delay(1000);
}


