// Arduino Board Layout:
//                   +5V
//                    |   
// Pin 7 ------------ LED1
//                    |
// Pin 9 ------------ LED2
//                    |
// Pin 8 ------------ LED3
//                    |
//                   GND

// Tool for online arduino board layout:
// https://www.tinkercad.com/

const int led1 = 7;    // Pin 7 is connected to LED1
const int led2 = 9;    // Pin 9 is connected to LED2
const int led3 = 8;    // Pin 8 is connected to LED3
int rule = 1;          // Rule variable to control the LED sequence
bool rule2 = true;     // Boolean variable to control the LED sequence

void setup()
{
  pinMode(led1, OUTPUT);    // Set Pin 7 as an output pin for LED1
  pinMode(led2, OUTPUT);    // Set Pin 9 as an output pin for LED2
  pinMode(led3, OUTPUT);    // Set Pin 8 as an output pin for LED3
}

void loop()
{
  switch (rule)
  {
    case 1:
      rule = 2;
      digitalWrite(led3, LOW);   // Turn off LED3
      digitalWrite(led2, LOW);   // Turn off LED2
      digitalWrite(led1, HIGH);  // Turn on LED1
      rule2 = true;
      break;
    case 2:
      if (rule2 == true)
      {
        rule = 3;
        digitalWrite(led1, LOW);  // Turn off LED1
        digitalWrite(led2, HIGH); // Turn on LED2
      }
      if (rule2 == false)
      {
        rule = 1;
        digitalWrite(led3, LOW);  // Turn off LED3
        digitalWrite(led2, HIGH); // Turn on LED2
      }
      break;
    case 3:
      rule = 2;
      digitalWrite(led2, LOW);   // Turn off LED2
      digitalWrite(led3, HIGH);  // Turn on LED3
      rule2 = false;
      break;
  }
  delay(500);                   // Delay for 500 milliseconds
}