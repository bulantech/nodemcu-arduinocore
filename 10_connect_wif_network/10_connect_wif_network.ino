#include <ESP8266WiFi.h>

#define SSID_NAME "true_home2G_350"
#define SSID_PASS "88f02350"

IPAddress staticIP(192,168,1,2);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println();

  WiFi.begin(SSID_NAME, SSID_PASS);
  WiFi.config(staticIP, gateway, subnet);

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
