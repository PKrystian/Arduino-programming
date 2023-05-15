const int pin1 = 4;
const int pin2 = 8;
const int pin_but = 2;
int ledstate = LOW;
int butstate = HIGH;
long premillis = 0;
long butmillis = 0;
long time = 1000;
long duration = 5000;
void setup() 
{
  pinMode(pin1, OUTPUT);
  pinMode(pin_but, INPUT_PULLUP);
  pinMode(pin2,  OUTPUT);
}

void loop() 
{
  long curmilis = millis();
  if (curmilis - premillis >= time) 
  {
    premillis = curmilis;
    ledstate = !ledstate;
    digitalWrite(pin1, ledstate);
  }
  int curbut = digitalRead(pin_but);
  if (curbut == LOW && butstate == HIGH) 
  {
    butmillis = curmilis;
    digitalWrite(pin2, HIGH);
  } else if (curmilis - butmillis >= duration) 
  {
    digitalWrite(pin2, LOW);
  }
  butstate = curbut;
}