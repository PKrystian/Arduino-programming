// Arduino Board Layout:
//                   +5V
//                    |
// Pin 4 ------------ LED 1 (with resistor)
//                    |
// Pin 8 ------------ LED 2 (with resistor)
//                    |
//                   GND

// Tool for online arduino board layout:
// https://www.tinkercad.com/

const int ledPin1 = 4;   // Pin 4 is connected to LED 1 with a resistor
const int ledPin2 = 8;   // Pin 8 is connected to LED 2 with a resistor
long premillis1 = 0;     // Variable to store the previous time for LED 1
long premillis2 = 0;     // Variable to store the previous time for LED 2
int state1 = LOW;        // Variable to store the state of LED 1 (LOW = off, HIGH = on)
int state2 = LOW;        // Variable to store the state of LED 2 (LOW = off, HIGH = on)

void setup()
{
  pinMode(ledPin1, OUTPUT);  // Set Pin 4 as an output pin for LED 1
  pinMode(ledPin2, OUTPUT);  // Set Pin 8 as an output pin for LED 2
}

void loop()
{
  unsigned long curmillis = millis();   // Get the current time in milliseconds
  // If the time elapsed since the last change is greater than or equal to 2000 ms (2 seconds)
  if (curmillis - premillis1 >= 2000)
  {
    premillis1 = curmillis;   // Update the previous time for LED 1 to the current time
    // Toggle the state of LED 1
    if (state1 == LOW)
    {
      state1 = HIGH;
    }
    else
    {
      state1 = LOW;
    }
    digitalWrite(ledPin1, state1);   // Set the output of Pin 4 to the new state for LED 1
  }
  // If the time elapsed since the last change is greater than or equal to 500 ms
  if (curmillis - premillis2 >= 500)
  {
    premillis2 = curmillis;   // Update the previous time for LED 2 to the current time
    // Toggle the state of LED 2
    if (state2 == LOW)
    {
      state2 = HIGH;
    }
    else
    {
      state2 = LOW;
    }
    digitalWrite(ledPin2, state2);   // Set the output of Pin 8 to the new state for LED 2
  }
}