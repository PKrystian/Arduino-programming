// Code wrote by PMusielak

const int pin=7;
const int pin2=8;
const int pin_but=9;
int ctime=2000;
int btime=500;
bool rule=false;
bool rule2=false;
bool rule3=false;
void setup()
{  
  pinMode(pin, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin_but, INPUT_PULLUP);
}

void loop()
{
  int time = millis();
  int but=digitalRead(pin_but);
  if(but==LOW)
  {
    btime=time;
    digitalWrite(pin2, HIGH);
    rule3=true;
  }
  if(rule3==true)
  {
    if(time-btime>5000)
    {
      digitalWrite(pin2, LOW);
      rule3=false;
    }
  }
  if(time>=ctime)
  {
    if(rule==true)
    {
      digitalWrite(pin, LOW); 
    }
    if(rule==false)
    {
      digitalWrite(pin, HIGH); 
    }
    rule=!rule;
    ctime+=2000;
  }
  }