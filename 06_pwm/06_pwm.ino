
#define LED D0  
#define BUZZER D8                        
int count;
void setup()
{
  Serial.begin(115200);              //  setup serial
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  analogWrite(LED,500);
  if(count < 5) analogWrite(BUZZER,500);
  else analogWrite(BUZZER,0);     
  delay(1000);
  analogWrite(LED,1000); 
  if(count < 5) analogWrite(BUZZER,1000);
  else analogWrite(BUZZER,0);   
  delay(1000);
  count++;
}
