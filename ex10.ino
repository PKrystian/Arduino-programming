// Code wrote by PMusielak
const int btn1 = 7;
const int btn2 = 6;
int btn1_time = 0;
int btn2_time = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
}

void loop() 
{
  if (digitalRead(btn1) == HIGH) 
  {
    btn1_time = millis();
    int buffer = btn1_time - btn2_time;
    Serial.println(buffer / 1000);
    btn2_time = 0;
    delay(500);
  }
  if (digitalRead(btn2) == HIGH) 
  {
    btn2_time = millis();
    int buffer = btn2_time - btn1_time;
    Serial.println(buffer / 1000);
    btn1_time = 0;
    delay(500);
  }
}