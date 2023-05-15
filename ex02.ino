// Arduino Board Layout:
//                   +5V
//                    |
// Pin A0 ----------- Photoresistor
//                    |
//                   GND

// Tool for online arduino board layout:
// https://www.tinkercad.com/

const int pin = A0;   // Pin A0 is connected to the photoresistor

void setup()
{
  Serial.begin(9600);   // Initialize the serial communication at 9600 bps
}

void loop()
{
  int readfoto = analogRead(pin);   // Read the analog value from the photoresistor
  int brightness = map(readfoto, 0, 1023, 0, 70);   // Map the analog value to a brightness percentage
  // Print the level of brightness to the serial monitor
  Serial.print("\n Level of brightness: ");
  Serial.print(brightness);
  Serial.println("%");
  delay(1000);  // Wait for 1 second
}