
#define LED D0                         

void setup()
{
  Serial.begin(115200);              //  setup serial
  pinMode(LED, OUTPUT);
}

void loop()
{
  analogWrite(LED,500);  
  delay(1000);
  analogWrite(LED,1000);  
  delay(1000);
}
