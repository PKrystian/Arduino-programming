// Arduino Board Layout:
//                   +5V
//                    |
// Pin 7 ------------ Button 1
//                    |
// Pin 6 ------------ Button 2
//                    |
//                   GND

// Tool for online arduino board layout:
// https://www.tinkercad.com/

const int btn1 = 7;       // Pin 7 is connected to Button 1
const int btn2 = 6;       // Pin 6 is connected to Button 2
int btn1_time = 0;        // Variable to store the time when Button 1 was pressed
int btn2_time = 0;        // Variable to store the time when Button 2 was pressed

void setup() 
{
  Serial.begin(9600);     // Initialize the serial communication at a baud rate of 9600
  pinMode(btn1, INPUT_PULLUP);   // Set Pin 7 as an input pin for Button 1 with internal pull-up resistor enabled
  pinMode(btn2, INPUT_PULLUP);   // Set Pin 6 as an input pin for Button 2 with internal pull-up resistor enabled
}

void loop() 
{
  if (digitalRead(btn1) == HIGH)   // Check if Button 1 is pressed
  {
    btn1_time = millis();          // Record the current time in milliseconds when Button 1 was pressed
    int buffer = btn1_time - btn2_time;   // Calculate the time difference between Button 1 and Button 2 presses
    Serial.println(buffer / 1000);   // Print the time difference in seconds
    btn2_time = 0;                  // Reset the Button 2 time variable
    delay(500);                     // Delay for 500 milliseconds
  }
  if (digitalRead(btn2) == HIGH)   // Check if Button 2 is pressed
  {
    btn2_time = millis();          // Record the current time in milliseconds when Button 2 was pressed
    int buffer = btn2_time - btn1_time;   // Calculate the time difference between Button 2 and Button 1 presses
    Serial.println(buffer / 1000);   // Print the time difference in seconds
    btn1_time = 0;                  // Reset the Button 1 time variable
    delay(500);                     // Delay for 500 milliseconds
  }
}