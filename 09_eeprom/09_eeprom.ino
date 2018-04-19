// Reset eeprom

#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:
  EEPROM.begin(512);
  EEPROM.write(0, 0);
  EEPROM.commit();
  
  Serial.begin(9600);
  Serial.println();
  Serial.println("Reset eeprom OK");
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
