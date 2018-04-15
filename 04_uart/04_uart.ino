
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Serial.print"); 
  Serial.print("Serial.print");
  Serial.println("Serial.println"); 
  Serial.println("Serial.println");
  delay(2000);
}
