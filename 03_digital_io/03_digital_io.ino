
void setup() {
  // put your setup code here, to run once:
  pinMode(D0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(D0, 0); //led on
  delay(1000);
  digitalWrite(D0, 1); //led off
  delay(1000);
}
