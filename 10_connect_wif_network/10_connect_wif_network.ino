#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

#define SW_PIN 0

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(SW_PIN, INPUT_PULLUP);  

    //start-block2
    IPAddress _ip = IPAddress(10, 0, 1, 78);
    IPAddress _gw = IPAddress(10, 0, 1, 1);
    IPAddress _sn = IPAddress(255, 255, 255, 0);
    
    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;

    Serial.println();
    Serial.print("Reset wifi config?:");
    for(int i=5; i>0; i--){
      Serial.print(String(i)+" "); 
      delay(1000);
    }
        
    if(digitalRead(SW_PIN) == LOW) // Press button
    {
      Serial.println();
      Serial.println("Reset wifi config");
      //reset saved settings
      wifiManager.resetSettings(); 
      //set custom ip for portal
      wifiManager.setAPStaticIPConfig(_ip, _gw, _sn);
    }    
    
    //fetches ssid and pass from eeprom and tries to connect
    //if it does not connect it starts an access point with the specified name
    //here  "AutoConnectAP"
    //and goes into a blocking loop awaiting configuration
    wifiManager.autoConnect("AutoConnectAP");
    //or use this for auto generated name ESP + ChipID
    //wifiManager.autoConnect();

    
    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
}

void loop() {
    // put your main code here, to run repeatedly:
    
}
