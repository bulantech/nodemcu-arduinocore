#define LED 16
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, 0); //led on
  delay(1000);
  digitalWrite(LED, 1); //led off
  delay(1000);
}
