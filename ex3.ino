// Arduino Board Layout:
//                   +5V
//                    |
// Pin 8 ------------ LED (with resistor)
//                    |
//                   GND

// Tool for online arduino board layout:
// https://www.tinkercad.com/

const int pin = 8;   // Pin 8 is connected to the LED with a resistor
long premillis = 0;  // Variable to store the previous time
int state = LOW;     // Variable to store the state of the LED (LOW = off, HIGH = on)

void setup()
{
  pinMode(pin, OUTPUT);  // Set Pin 8 as an output pin
}

void loop()
{
  long curmillis = millis();   // Get the current time in milliseconds
  // If the time elapsed since the last change is greater than 500 ms
  if (curmillis - premillis > 500)
  {
    premillis = curmillis;   // Update the previous time to the current time
    // Toggle the state of the LED
    if (state == LOW)
    {
      state = HIGH;
    }
    else
    {
      state = LOW;
    }
    digitalWrite(pin, state);   // Set the output of Pin 8 to the new state
  }
}