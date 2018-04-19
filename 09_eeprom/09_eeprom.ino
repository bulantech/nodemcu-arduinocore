// Deserialization 

// Step 1
#include <ArduinoJson.h>

void setup() {
  Serial.begin(9600);
  while (!Serial) continue;

  // Step 2
  char json[] =
      "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";

  // Step 3
  StaticJsonBuffer<200> jsonBuffer;

  // Step 4
  JsonObject& root = jsonBuffer.parseObject(json);

  // Step 5
  if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
  }

  // Step 6
  const char* sensor = root["sensor"];
  long time = root["time"];
  double latitude = root["data"][0];
  double longitude = root["data"][1];
  Serial.println();
  Serial.print("sensor: ");
  Serial.println(sensor);
  Serial.print("time: ");
  Serial.println(time);
  Serial.print("latitude: ");
  Serial.println(latitude, 6);
  Serial.print("longitude: ");
  Serial.println(longitude, 6);
}

void loop() {}
