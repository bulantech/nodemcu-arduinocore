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
  root.printTo(Serial);
  Serial.println();
  root.prettyPrintTo(Serial);
}

void loop() {}
