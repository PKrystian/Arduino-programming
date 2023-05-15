// Arduino Board Layout:
//                   +5V
//                    |
// Pin 7 ------------ LED
//                    |
// Pin 8 ------------ LED2
//                    |
// Pin 9 ------------ Button
//                    |
//                   GND

// Tool for online arduino board layout:
// https://www.tinkercad.com/

const int pin = 7;         // Pin 7 is connected to the LED
const int pin2 = 8;        // Pin 8 is connected to LED2
const int pin_but = 9;     // Pin 9 is connected to the button
int ctime = 2000;          // Time interval for LED state change (in milliseconds)
int btime = 500;           // Time interval for button press duration (in milliseconds)
bool rule = false;         // Boolean variable to control the LED state
bool rule2 = false;        // Placeholder boolean variable
bool rule3 = false;        // Boolean variable to control the button press behavior

void setup()
{
  pinMode(pin, OUTPUT);           // Set Pin 7 as an output pin for the LED
  pinMode(pin2, OUTPUT);          // Set Pin 8 as an output pin for LED2
  pinMode(pin_but, INPUT_PULLUP); // Set Pin 9 as an input pin with internal pull-up resistor for the button
}

void loop()
{
  int time = millis();             // Get the current time in milliseconds
  int but = digitalRead(pin_but);  // Read the state of the button (LOW when pressed)
  if (but == LOW)
  {
    btime = time;                  // Update the button press time
    digitalWrite(pin2, HIGH);      // Turn on LED2
    rule3 = true;                  // Set rule3 to true to indicate button press
  }
  if (rule3 == true)
  {
    if (time - btime > 5000)       // Check if button press duration exceeds 5000 milliseconds (5 seconds)
    {
      digitalWrite(pin2, LOW);     // Turn off LED2
      rule3 = false;               // Reset rule3
    }
  }
  if (time >= ctime)
  {
    if (rule == true)
    {
      digitalWrite(pin, LOW);      // Turn off the LED
    }
    if (rule == false)
    {
      digitalWrite(pin, HIGH);     // Turn on the LED
    }
    rule = !rule;                  // Invert the value of rule
    ctime += 2000;                 // Increment ctime by 2000 milliseconds (2 seconds)
  }
}