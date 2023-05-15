const int buttonPin1 = 4;
const int buttonPin2 = 7;
const int ledPinXOR = 11;
const int ledPinXNOR = 12;

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(ledPinXOR, OUTPUT);
  pinMode(ledPinXNOR, OUTPUT);
}

void loop() {
  int button1 = digitalRead(buttonPin1);
  int button2 = digitalRead(buttonPin2);
  int resultXOR = button1 == button2;
  int resultXNOR = !(button1 == button2);
  digitalWrite(ledPinXOR, !resultXOR);
  digitalWrite(ledPinXNOR, !resultXNOR);
}