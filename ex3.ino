const int pin = 8;
long premillis = 0;
int state = LOW;

void setup() 
{
  pinMode(pin, OUTPUT);
}
void loop() 
{
  long curmillis = millis();
  if (curmillis - premillis > 500) 
  {
    premillis = curmillis;
    if (state == LOW) 
    {
      state = HIGH;
    } 
    else{
      state = LOW;
    }
    digitalWrite(pin, state);
  }
}