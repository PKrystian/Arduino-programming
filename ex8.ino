// Tool for online arduino board layout:
// https://www.tinkercad.com/

#include <math.h>

float amp = 50;             // Amplitude of the first sine wave
float amp2 = 25;            // Amplitude of the second sine wave
float hz1 = 25;             // Frequency of the first sine wave in hertz
float pii = 3.14;           // Value of pi (π)
float hz2 = 50;             // Frequency of the second sine wave in hertz
float move_by = pii / 2;    // Phase shift for the second sine wave
float time = 0;             // Time variable to track the progression of time
float value;                // Variable to store the calculated value of the first sine wave
float value2;               // Variable to store the calculated value of the second sine wave

void setup()
{
  Serial.begin(9600);       // Initialize the serial communication at a baud rate of 9600
}

void loop()
{
  value = amp * sin(2 * pii * hz1 * time) + 5;                // Calculate the value of the first sine wave
  value2 = amp2 * sin(2 * pii * hz2 * time + move_by) + 5;   // Calculate the value of the second sine wave
  Serial.print(value);                                      // Print the value of the first sine wave
  Serial.print(",");                                        // Print a comma as a separator
  Serial.println(value2);                                   // Print the value of the second sine wave on a new line
  time += 0.001;                                             // Increment the time variable by 0.001 (representing a small time step)
  delay(60);                                                 // Delay for 60 milliseconds to control the rate of output
}