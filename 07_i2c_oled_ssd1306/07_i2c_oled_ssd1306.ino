#include <SPI.h> 
#include <Wire.h> 
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h> 

#define RESET_PIN D0

Adafruit_SSD1306 display(RESET_PIN); 

void setup() {   
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);   
  display.clearDisplay();   
  display.display();  
  display.setTextSize(1);   
  display.setTextColor(WHITE,BLACK); 
} 

void loop() {   
  display.setCursor(0,0);   
  display.println("Hello line1");   
  display.println("line 2");   
  display.display(); 
  delay(2000);
}
