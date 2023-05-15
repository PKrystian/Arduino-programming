const int buttonPin1 = 3;
const int buttonPin2 = 4;
const int buttonPin3 = 5;
const int buttonPin4 = 6;
const int buttonPin5 = 2;
const int ledPin = 10;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  int votesForHigh = 0;
  int votesForLow = 0;
  if (buttonState1 == HIGH) {
    votesForHigh++;
  } else {
    votesForLow++;
  }

  if (buttonState2 == HIGH) {
    votesForHigh++;
  } else {
    votesForLow++;
  }
    if (buttonState3 == HIGH) {
    votesForHigh++;
  } else {
    votesForLow++;
  }

  if (buttonState4 == HIGH) {
    votesForHigh++;
  } else {
    votesForLow++;
  }

  if (buttonState5 == HIGH) {
    votesForHigh++;
  } else {
    votesForLow++;
  }
  if (votesForHigh > votesForLow) {
    digitalWrite(ledPin, HIGH);
    Serial.println("More on yes");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("More on no");
  }
  Serial.print("How much on yes: ");
  Serial.println(votesForHigh);
  Serial.print("HOW much on no: ");
  Serial.println(votesForLow);
  delay(2000);
}