const int ledPin1 = 4;
const int ledPin2 = 8;
long premillis1 = 0;
long premillis2 = 0;
int state1 = LOW;
int state2 = LOW;

void setup() 
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() 
{
  unsigned long curmillis = millis();
  if (curmillis - premillis1 >= 2000) 
  {
    premillis1 = curmillis;
    if (state1 == LOW) 
    {
      state1 = HIGH;
    } 
    else{
      state1 = LOW;
    }
    digitalWrite(ledPin1, state1);
  }
  if (curmillis - premillis2 >= 500) 
  {
    premillis2 = curmillis;
    if (state2 == LOW) 
    {
      state2 = HIGH;
    } 
    else{
      state2 = LOW;
    }
    digitalWrite(ledPin2, state2);
  }
}