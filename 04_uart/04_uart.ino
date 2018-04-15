int count;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  count = 15;
  Serial.println(count, DEC); // 15
  Serial.println(count, HEX); // F
  Serial.println(count, OCT); // 17
  Serial.println(count, BIN); // 1111
  Serial.println(1.234, 0); // 1
  Serial.println(1.234, 2); // 1.23
  Serial.println("-------------------");
  delay(2000);
}
