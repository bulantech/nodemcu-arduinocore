#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
byte value;

void setup() {
  // initialize serial and wait for port to open:
  Serial.begin(115200);  
  EEPROM.begin(512);
}

void eepromStringWrite(String str) {
  for(int i=0; i<str.length(); i++) {
    EEPROM.write(i, str[i]);
  }
  EEPROM.write(str.length(), 0);
  EEPROM.commit();
}

String eepromStringRead() {
  String str = "";
  int i=0;
  while(1) {
    char c = EEPROM.read(i++);    
    str.concat(c);;
    if(c == 0) return str;
  } 
}

void loop() {
  String stringData = "Hello "+(String)address;
  Serial.println(stringData);
  eepromStringWrite(stringData);

  address++;
  
  String text = eepromStringRead();
  Serial.println(text);
  Serial.println();
  
  delay(3000);
}


