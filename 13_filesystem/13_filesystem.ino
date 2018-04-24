#include <ESP8266WiFi.h>
#include <FS.h>
#include <ArduinoJson.h>

char ssid[32];
char password[32];

#define SW D3

File configFile;

void setup() {
  Serial.begin(115200);
  pinMode(SW, INPUT);
  delay(10);
  Serial.println();
  Serial.println();

  if (!SPIFFS.begin()) {
    Serial.println("Failed to mount file system");
    return;
  }

  loadConfig();
  Serial.print("Press key for reset config");
  for(int i=5; i>0; i--) {
    delay(1000); 
    Serial.print(".");  
  }  
  Serial.println(); 
  if(!digitalRead(SW)) {
    resetConfig();  
  }   

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.printf("%s, %s", ssid ,password);

  WiFi.mode(WIFI_STA);
  WiFi.begin((const char*)ssid, (const char*)password);
  Serial.println();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  Serial.print("Press key for update config");
  for(int i=5; i>0; i--) {
    delay(1000); 
    Serial.print(".");  
  }  
  Serial.println(); 
  if(!digitalRead(SW)) {
    updateConfig();  
  } 
}

bool resetConfig() {
  Serial.println();
  Serial.println("Reset config..");
  configFile = SPIFFS.open("/config_reset.json", "r");
  if (!configFile) {
    Serial.println("Failed to open config_reset file");
    return false;
  }

  size_t size = configFile.size();
  if (size > 1024) {
    Serial.println("config_reset file size is too large");
    return false;
  }

  // Allocate a buffer to store contents of the file.
  std::unique_ptr<char[]> buf(new char[size]);

  // We don't use String here because ArduinoJson library requires the input
  // buffer to be mutable. If you don't use ArduinoJson, you may as well
  // use configFile.readString instead.
  configFile.readBytes(buf.get(), size);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());

  if (!json.success()) {
    Serial.println("Failed to parse config_reset file");
    return false;
  }

  Serial.println("config.json data:");
  json.printTo(Serial);
  configFile.close();

  configFile = SPIFFS.open("/config.json", "w");
  if (!configFile) {
    Serial.println("Failed to open config file");
    return false;
  }
  String newData;
  Serial.println();
  json.printTo(newData);
  Serial.println("Reset newData ==========");
  Serial.println(newData);
  json.printTo(configFile);
//  configFile.print(newData); 
  configFile.close();
  Serial.println(); 
  
  return true;
}

bool loadConfig() {
  Serial.println();
  Serial.println("Load config..");
  configFile = SPIFFS.open("/config.json", "r");
  if (!configFile) {
    Serial.println("Failed to open config file");
    return false;
  }

  size_t size = configFile.size();
  if (size > 1024) {
    Serial.println("Config file size is too large");
    return false;
  }

  // Allocate a buffer to store contents of the file.
  std::unique_ptr<char[]> buf(new char[size]);

  // We don't use String here because ArduinoJson library requires the input
  // buffer to be mutable. If you don't use ArduinoJson, you may as well
  // use configFile.readString instead.
  configFile.readBytes(buf.get(), size);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());

  if (!json.success()) {
    Serial.println("Failed to parse config file");
    return false;
  }
  String ap_name = json["ap_name"];
  String ap_pass = json["ap_pass"];
  ap_name.toCharArray(ssid, ap_name.length()+1);
  ap_pass.toCharArray(password, ap_pass.length()+1);
  
  Serial.printf("config.json data: %s, %s \r\n", ssid, password);
  json.printTo(Serial);
  configFile.close();
  Serial.println(); 

  return true;
}

bool updateConfig() {
  Serial.println();
  Serial.println("Update config..");
  
  configFile = SPIFFS.open("/config.json", "w");
  if (!configFile) {
    Serial.println("Failed to open config file");
    return false;
  }

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();

  json["ap_name"] = "new_name";
  json["ap_pass"] = "new_password";

  String newData;
  Serial.println();
  json.printTo(newData);
  Serial.println("newData ==========");
  Serial.println(newData);
  json.printTo(configFile);
//  configFile.print(newData); 
  configFile.close();
  Serial.println(); 
  
  return true;
}
