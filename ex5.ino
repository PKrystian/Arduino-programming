// Arduino Board Layout:
//                   +5V
//                    |
// Pin 4 ------------ LED 1 (with resistor)
//                    |
// Pin 2 ------------ Button (with pull-up resistor)
//                    |
// Pin 8 ------------ LED 2 (with resistor)
//                    |
//                   GND

// Tool for online arduino board layout:
// https://www.tinkercad.com/

const int pin1 = 4;        // Pin 4 is connected to LED 1 with a resistor
const int pin2 = 8;        // Pin 8 is connected to LED 2 with a resistor
const int pin_but = 2;     // Pin 2 is connected to the button with a pull-up resistor
int ledstate = LOW;        // Variable to store the state of LED 1 (LOW = off, HIGH = on)
int butstate = HIGH;       // Variable to store the state of the button (HIGH = not pressed, LOW = pressed)
long premillis = 0;        // Variable to store the previous time for LED 1
long butmillis = 0;        // Variable to store the time when the button was pressed
long time = 1000;          // Interval time for LED 1 to toggle (in milliseconds)
long duration = 5000;      // Duration of LED 2 being on after the button is pressed (in milliseconds)

void setup()
{
  pinMode(pin1, OUTPUT);              // Set Pin 4 as an output pin for LED 1
  pinMode(pin_but, INPUT_PULLUP);     // Set Pin 2 as an input pin with internal pull-up resistor for the button
  pinMode(pin2, OUTPUT);              // Set Pin 8 as an output pin for LED 2
}

void loop()
{
  long curmilis = millis();   // Get the current time in milliseconds
  // If the time elapsed since the last change is greater than or equal to 'time' value
  if (curmilis - premillis >= time)
  {
    premillis = curmilis;   // Update the previous time to the current time
    ledstate = !ledstate;   // Toggle the state of LED 1
    digitalWrite(pin1, ledstate);   // Set the output of Pin 4 to the new state for LED 1
  }
  int curbut = digitalRead(pin_but);   // Read the current state of the button
  // If the button is pressed and it was in the unpressed state
  if (curbut == LOW && butstate == HIGH)
  {
    butmillis = curmilis;   // Update the button press time to the current time
    digitalWrite(pin2, HIGH);   // Turn on LED 2 by setting the output of Pin 8 to HIGH
  }
  // If the duration of LED 2 being on has passed since the button was pressed
  else if (curmilis - butmillis >= duration)
  {
    digitalWrite(pin2, LOW);   // Turn off LED 2 by setting the output of Pin 8 to LOW
  }
  butstate = curbut;   // Update the previous button state to the current button state
}