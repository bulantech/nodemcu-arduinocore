
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
//#include <ESP8266mDNS.h>

#define SSID_NAME "******"
#define SSID_PASS "******"

ESP8266WebServer server(80);

const int led = D0;

String homePage = " \
<!DOCTYPE html> \
<head> \
  <script src='https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js'></script>    \
</head> \
<body> \
  <button >LED ON</button> \
  <script>  \
    $( document ).ready(function() { \
      $( 'button' ).click(function() {  \        
        if($( 'button' ).text() == 'LED ON') {  \
          $.post( '/on', function( data ) {  \
            $( 'button' ).text(data);  \
          });  \                  
        } else {  \          
          $.post( '/off', function( data ) {  \
            $( 'button' ).text(data); \
          });  \     
        }  \      
      });  \    
    });  \   
  </script>  \
</body> \
<html> \
";

void handleRoot() {
  server.send(200, "text/html", homePage);
}

void handleNotFound() {
//  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
//  digitalWrite(led, 0);
}

void setup(void) {
  pinMode(led, OUTPUT);
//  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID_NAME, SSID_PASS);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(SSID_NAME);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

//  if (MDNS.begin("esp8266")) {
//    Serial.println("MDNS responder started");
//  }

  server.on("/", handleRoot);

  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });

  server.on("/on", []() {
    digitalWrite(led, 0);
    String homePage = "<h2><a href='/off' class='btn btn-default'>LED OFF</a></h2>";
    if(server.method() == HTTP_GET) server.send(200, "text/html", homePage);
    else server.send(200, "text/plain", "LED OFF");
  });

  server.on("/off", []() {
    digitalWrite(led, 1);
    String homePage = "<h2><a href='/on' class='btn btn-default'>LED ON</a></h2>";
    if(server.method() == HTTP_GET) server.send(200, "text/html", homePage);
    else server.send(200, "text/plain", "LED ON");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");

  digitalWrite(led, 1);
}

void loop(void) {
  server.handleClient();
}
