int count;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("start.."); 
}

void loop() {
  // put your main code here, to run repeatedly:
  char incomingByte;
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("get > ");
    Serial.println(incomingByte);
  }
}
