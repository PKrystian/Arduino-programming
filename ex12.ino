// Arduino Board Layout:
//                  +5V
//                   |
// Pin 4 ----------- Button 1
//                   |
// Pin 7 ----------- Button 2
//                   |
// Pin 11 ---------- LED (AND output)
//                   |
// Pin 12 ---------- LED (OR output)
//                   |
//                  GND

// Tool for online arduino board layout:
// https://www.tinkercad.com/

const int buttonPin1 = 4;    // Pin 4 is connected to Button 1
const int buttonPin2 = 7;    // Pin 7 is connected to Button 2
const int ledPinAND = 11;    // Pin 11 is connected to LED (AND output)
const int ledPinOR = 12;     // Pin 12 is connected to LED (OR output)

void setup() 
{
  pinMode(buttonPin1, INPUT_PULLUP);    // Set Pin 4 as input with internal pull-up resistor
  pinMode(buttonPin2, INPUT_PULLUP);    // Set Pin 7 as input with internal pull-up resistor
  pinMode(ledPinAND, OUTPUT);            // Set Pin 11 as output for AND LED
  pinMode(ledPinOR, OUTPUT);             // Set Pin 12 as output for OR LED
}

void loop() 
{
  int button1 = digitalRead(buttonPin1);    // Read the state of Button 1
  int button2 = digitalRead(buttonPin2);    // Read the state of Button 2
  int resultAND = button1 && button2;       // Perform AND logic
  int resultOR = button1 || button2;        // Perform OR logic
  digitalWrite(ledPinAND, !resultAND);      // Set AND LED based on the AND result
  digitalWrite(ledPinOR, !resultOR);        // Set OR LED based on the OR result
}