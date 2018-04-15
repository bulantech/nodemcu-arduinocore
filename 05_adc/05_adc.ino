int analogPin = A0;                           
int val = 0;          

void setup()
{
  Serial.begin(115200);              //  setup serial
}

void loop()
{
  val = analogRead(analogPin);     // read the input pin
  Serial.printf("adc = %u \r\n",val);   
  delay(2000);
}
