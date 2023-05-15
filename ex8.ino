#include <math.h>

float amp = 50;
float amp2 = 25;
float hz1 = 25;
float pii = 3.14;
float hz2 = 50;
float move_by = pii/2;
float time = 0;
float value;
float value2;

void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
  value = amp * (sin(2 * pii * hz1 * time)) + 5;
  value2 = amp2 * (sin(2 * pii * hz2 * time + move_by)) + 5;
  Serial.print(value);
  Serial.print(",");
  Serial.println(value2);
  time += 0.001;
  delay(60);
}