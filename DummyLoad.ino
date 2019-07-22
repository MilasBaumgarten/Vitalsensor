/*
#define dummyPin 3
#define interval 2000
#define onTime 20
long lastMillis = 0;

void setup() {
  ...
  // Power Bank Setup
  pinMode(dummyPin, OUTPUT);
}

void loop() {
  PowerBankDummyLoad();
  ...
}

void PowerBankDummyLoad() {
  int timer = (millis() - lastMillis);
  if (timer > interval) {
    lastMillis = millis();
    digitalWrite(dummyPin, HIGH);
  } else if (timer > onTime) {
    digitalWrite(dummyPin, LOW);
  }
}
*/
