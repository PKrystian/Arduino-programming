const int pin1 = 2;
const int pin2 = 3;
const int pin3 = 4;
const int pin4 = 5;
const int frequency = 50;
int state1 = LOW;
int state2 = LOW;
int state3 = LOW;
int state4 = LOW;
long prevmillis = 0;
int step = 0;
bool stateBool = true;

void setup() 
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}
void loop() 
{
  long curmillis = millis();
  if (step == 4) 
  {
    stateBool = false;
  }
  if (curmillis - prevmillis >= frequency && stateBool)
  {
    prevmillis = curmillis;
    step++;
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
  }
  if (curmillis - prevmillis >= frequency && !stateBool)
  {
    prevmillis = curmillis;
    step--;
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    if (step == 1) 
    {
      stateBool = true;
    }
  }
  switch(step) 
  {
    case 1:
      digitalWrite(pin1, HIGH);
      break;
    case 2:
      digitalWrite(pin2, HIGH);
      break;
    case 3:
      digitalWrite(pin3, HIGH);
      break;
    case 4:
      digitalWrite(pin4, HIGH);
      break;        
    default:
      step = 0;
      break;
  }
}