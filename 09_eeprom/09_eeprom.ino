// Serialization

//  {
//    "sensor":"gps",
//    "time":1351824120,
//    "data":[
//      48.756080,
//      2.302038
//    ], 
//    "object":{
//      "a":1,
//      "b":2
//    }
//  }

// Step 1
#include <ArduinoJson.h>
#include <EEPROM.h>

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

void setup() {
  Serial.begin(9600);
  while (!Serial) continue;

  // Step 2
  StaticJsonBuffer<200> jsonBuffer;
  
  // Step 3
  JsonObject& root = jsonBuffer.createObject();
  root["sensor"] = "gps";
  root["time"] = 1351824120;
  JsonArray& data = root.createNestedArray("data");
  data.add(48.756080);
  data.add(2.302038);
  JsonObject& object = root.createNestedObject("object");
  object["a"] = 1;
  object["b"] = 2;

  // Step 4
  Serial.println();
  Serial.println("Json data");
  root.prettyPrintTo(Serial);
  String json;  
  EEPROM.begin(512);
  char c = EEPROM.read(0);
  if(c != '{') {
    Serial.println();
    Serial.println("write json to eeprom");
    root.prettyPrintTo(json);
    eepromStringWrite(json);
    json = "";
  }
  Serial.println();
  Serial.println("Read json to eeprom");
  json = eepromStringRead();
  Serial.println(json);
}

void loop() {}
