const int pin = A0;

void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
  int readfoto = analogRead(pin);
  int brightness = map(readfoto, 0, 1023, 0, 70);
  Serial.print("\n Level of brightness: ");
  Serial.print(brightness);
  Serial.println("%");
  delay(1000);
}