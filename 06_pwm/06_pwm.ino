
#define LED D0  
#define BUZZER D8                        

void setup()
{
  Serial.begin(115200);              //  setup serial
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  analogWrite(LED,500);
  analogWrite(BUZZER,500);   
  delay(1000);
  analogWrite(LED,1000); 
  analogWrite(BUZZER,1000);  
  delay(1000);
}
