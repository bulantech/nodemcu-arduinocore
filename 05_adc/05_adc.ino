int analogPin = A0;                           

void setup()
{
  Serial.begin(115200);              //  setup serial
}

void loop()
{
  int val = analogRead(analogPin);     // read the input pin
  float vin = 3.3*(float)val / 1024;
  Serial.printf("adc = %u, vin =  %.2f \r\n", val, vin);   
  delay(2000);
}
