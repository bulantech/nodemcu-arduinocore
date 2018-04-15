int count;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  count++;
  Serial.println(count, DEC); 
  Serial.write(count);
  delay(2000);
}
