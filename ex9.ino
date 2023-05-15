// Code wrote by PMusielak
const int led1 = 7;
const int led2 = 9;
const int led3 = 8;
int rule = 1;
bool rule2=true;

void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() 
{
  switch(rule)
  {
    case 1:
      rule=2;
      digitalWrite(led3, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led1, HIGH);
      rule2=true;
      break;
    case 2:
      if(rule2==true)
      {
        rule=3;
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
      }
      if(rule2==false)
      {
        rule=1;
        digitalWrite(led3, LOW);
        digitalWrite(led2, HIGH);
      }
      break;
    case 3:
      rule=2;
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      rule2=false;
      break;
  }
  delay(500);
}