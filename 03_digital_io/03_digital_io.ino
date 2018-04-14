
#define LED D0
#define SW D3
#define LED_ON 0
#define LED_OFF 1
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(SW)) digitalWrite(LED, LED_ON);  
  else digitalWrite(LED, LED_OFF); 
}
