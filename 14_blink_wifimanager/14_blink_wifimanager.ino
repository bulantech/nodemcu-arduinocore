#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space

//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <BlynkSimpleEsp8266.h>

char auth[] = "34c0acad7fee4dc2b2d37d555e110eb9";
char blynk_token[] = "";

#define SW_PIN 0

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(SW_PIN, INPUT_PULLUP);  
    
    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;

    Serial.println("Reset wifi config?:");
    for(int i=5; i>0; i--){
      Serial.print(String(i)+" "); 
      delay(1000);
    }
    
    //reset saved settings
    if(digitalRead(SW_PIN) == LOW) // Press button
    {
      Serial.println();
      Serial.println("Reset wifi config");
      wifiManager.resetSettings(); 
    }    
    
    //set custom ip for portal
    //wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

    //fetches ssid and pass from eeprom and tries to connect
    //if it does not connect it starts an access point with the specified name
    //here  "AutoConnectAP"
    //and goes into a blocking loop awaiting configuration
    WiFiManagerParameter custom_blynk_token("Blynk", "blynk token", blynk_token, 34);
    wifiManager.addParameter(&custom_blynk_token);
  
    wifiManager.autoConnect("AutoConnectAP");
    //or use this for auto generated name ESP + ChipID
    //wifiManager.autoConnect();

    
    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");

    //Blynk.begin(auth);
    Blynk.config(custom_blynk_token.getValue());
}

void loop() {
    // put your main code here, to run repeatedly:
    Blynk.run();
    
}
