// Arduino Board Layout:
//                  +5V
//                   |
// Pin 4 ----------- Button 1
//                   |
// Pin 7 ----------- Button 2
//                   |
// Pin 11 ---------- LED (XOR output)
//                   |
// Pin 12 ---------- LED (XNOR output)
//                   |
//                  GND

// Tool for online arduino board layout:
// https://www.tinkercad.com/

const int buttonPin1 = 4;    // Pin 4 is connected to Button 1
const int buttonPin2 = 7;    // Pin 7 is connected to Button 2
const int ledPinXOR = 11;    // Pin 11 is connected to LED (XOR output)
const int ledPinXNOR = 12;   // Pin 12 is connected to LED (XNOR output)

void setup() 
{
  pinMode(buttonPin1, INPUT_PULLUP);    // Set Pin 4 as input with internal pull-up resistor
  pinMode(buttonPin2, INPUT_PULLUP);    // Set Pin 7 as input with internal pull-up resistor
  pinMode(ledPinXOR, OUTPUT);            // Set Pin 11 as output for XOR LED
  pinMode(ledPinXNOR, OUTPUT);           // Set Pin 12 as output for XNOR LED
}

void loop() 
{
  int button1 = digitalRead(buttonPin1);    // Read the state of Button 1
  int button2 = digitalRead(buttonPin2);    // Read the state of Button 2
  int resultXOR = button1 == button2;       // Perform XOR logic
  int resultXNOR = !(button1 == button2);   // Perform XNOR logic
  digitalWrite(ledPinXOR, !resultXOR);      // Set XOR LED based on the XOR result
  digitalWrite(ledPinXNOR, !resultXNOR);    // Set XNOR LED based on the XNOR result
}