
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("start.."); 
}

void loop() {
  // put your main code here, to run repeatedly:
  String text;
  while(Serial.available()) {
    text += (char)Serial.read();
  }
  if(text.length())
    Serial.println(text); 
  delay(1000);
}


