// Arduino Board Layout:
//                   +5V
//                    |
//                   Resistor 1 (Reference Resistor)
//                    |
// Pin A0 ----------- Resistor 2 (Variable Resistor)
//                    |
//                   GND

// Tool for online arduino board layout:
// https://www.tinkercad.com/

const int Pin = A0;   // Pin A0 is connected to Resistor 2
int raw_value = 0;    // Variable to store the raw analog value read from Pin A0
int V = 5;            // Supply voltage (5V)
float Res1 = 100;     // Resistance value of Resistor 1 (Reference Resistor)
float Res2 = 0;       // Resistance value of Resistor 2 (Variable Resistor)

void setup()
{
  Serial.begin(9600);   // Initialize the serial communication at 9600 bps
}

void loop()
{
  raw_value = analogRead(Pin);   // Read the analog value from Pin A0
  if(raw_value)
  {
    float buffer = raw_value * V;   // Convert the raw value to voltage
    float Vol = (buffer) / 1024.0;  // Calculate the voltage
    buffer = (V/Vol) - 1;           // Calculate the ratio of V/Vol - 1
    Res2 = Res1 * buffer;           // Calculate the resistance of Resistor 2
    // Print the voltage and resistance values to the serial monitor
    Serial.print("Voltage: ");
    Serial.println(Vol);
    Serial.print("Resistance of reference resistor: ");
    Serial.println(Res2);
    delay(1000);
  }
}