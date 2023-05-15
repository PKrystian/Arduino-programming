const int Pin = A0;
int raw_value = 0;
int V = 5;
float Res1 = 100;
float Res2 = 0;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  raw_value = analogRead(Pin);
  if(raw_value)
  {
    float buffer = raw_value * V;
    float Vol = (buffer) / 1024.0;
    buffer = (V/Vol) - 1;
    Res2= Res1 * buffer;
    Serial.print("Voltage: ");
    Serial.println(Vol);
    Serial.print("Resistance of reference resistor: ");
    Serial.println(Res2);
    delay(1000);
  }
}