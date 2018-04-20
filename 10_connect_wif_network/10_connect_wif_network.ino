#include <ESP8266WiFi.h>

#define SSID_NAME "wifi-name"
#define SSID_PASS "wifi-password"

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println();

  WiFi.begin(SSID_NAME, SSID_PASS);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  delay(1000);  
}
