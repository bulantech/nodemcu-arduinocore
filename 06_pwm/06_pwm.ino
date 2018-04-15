#define LED D0  
#define BUZZER D8  
#define analogPin A0                      

void setup()
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  int val = analogRead(analogPin);
  Serial.println(val);
  if(val == 1024) val = 1023;
  analogWrite(LED, 1023 - val);
  analogWrite(BUZZER, val);       
  delay(1000);
}
