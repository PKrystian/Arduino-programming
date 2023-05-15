// Arduino Board Layout:
//                   +5V
//                    |
// Pin 2 ------------ LED 1
//                    |
// Pin 3 ------------ LED 2
//                    |
// Pin 4 ------------ LED 3
//                    |
// Pin 5 ------------ LED 4
//                    |
//                   GND

// Tool for online arduino board layout:
// https://www.tinkercad.com/

const int pin1 = 2;        // Pin 2 is connected to LED 1
const int pin2 = 3;        // Pin 3 is connected to LED 2
const int pin3 = 4;        // Pin 4 is connected to LED 3
const int pin4 = 5;        // Pin 5 is connected to LED 4
const int frequency = 50;  // Frequency of LED state change (in milliseconds)
int state1 = LOW;          // Variable to store the state of LED 1 (LOW = off, HIGH = on)
int state2 = LOW;          // Variable to store the state of LED 2 (LOW = off, HIGH = on)
int state3 = LOW;          // Variable to store the state of LED 3 (LOW = off, HIGH = on)
int state4 = LOW;          // Variable to store the state of LED 4 (LOW = off, HIGH = on)
long prevmillis = 0;       // Variable to store the previous time
int step = 0;              // Variable to track the current step
bool stateBool = true;     // Boolean variable to control the direction of steps

void setup()
{
  pinMode(pin1, OUTPUT);   // Set Pin 2 as an output pin for LED 1
  pinMode(pin2, OUTPUT);   // Set Pin 3 as an output pin for LED 2
  pinMode(pin3, OUTPUT);   // Set Pin 4 as an output pin for LED 3
  pinMode(pin4, OUTPUT);   // Set Pin 5 as an output pin for LED 4
}

void loop()
{
  long curmillis = millis();   // Get the current time in milliseconds
  if (step == 4)
  {
    stateBool = false;   // If the maximum step is reached, change the state boolean to false
  }
  // If the elapsed time since the last change is greater than or equal to the frequency and state boolean is true
  if (curmillis - prevmillis >= frequency && stateBool)
  {
    prevmillis = curmillis;   // Update the previous time to the current time
    step++;                   // Increment the step variable
    digitalWrite(pin1, LOW);  // Turn off LED 1
    digitalWrite(pin2, LOW);  // Turn off LED 2
    digitalWrite(pin3, LOW);  // Turn off LED 3
    digitalWrite(pin4, LOW);  // Turn off LED 4
  }
  // If the elapsed time since the last change is greater than or equal to the frequency and state boolean is false
  if (curmillis - prevmillis >= frequency && !stateBool)
  {
    prevmillis = curmillis;   // Update the previous time to the current time
    step--;                   // Decrement the step variable
    digitalWrite(pin1, LOW);  // Turn off LED 1
    digitalWrite(pin2, LOW);  // Turn off LED 2
    digitalWrite(pin3, LOW);  // Turn off LED 3
    digitalWrite(pin4, LOW);  // Turn off LED 4
    // If the step is 1, change the state boolean back to true
    if (step == 1)
    {
      stateBool = true;   // Change the state boolean back to true to reverse the direction
    }
  }
  // Switch statement to control the LEDs based on the current step
  switch (step)
  {
    case 1:
      digitalWrite(pin1, HIGH);  // Turn on LED 1
      break;
    case 2:
      digitalWrite(pin2, HIGH);  // Turn on LED 2
      break;
    case 3:
      digitalWrite(pin3, HIGH);  // Turn on LED 3
      break;
    case 4:
      digitalWrite(pin4, HIGH);  // Turn on LED 4
      break;
    default:
      step = 0;                  // Reset the step to 0 if it goes beyond the defined steps
      break;
  }
}