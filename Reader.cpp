#include "Reader.h"

#define LO_PlusPin 6
#define LO_MinusPin 7
#define EDA_PlusPin 3

int values[5];

// constructor
Reader::Reader() {
  // ECG Setup
  pinMode(LO_PlusPin, INPUT);
  pinMode(LO_MinusPin, INPUT);

  // EDA Setup
  pinMode(EDA_PlusPin, OUTPUT);
}

// deconstructor
Reader::~Reader() {}

int Reader::getEdaData() {
  digitalWrite(EDA_PlusPin, HIGH);
  delay(10);

  int value = analogRead(A0);

  digitalWrite(EDA_PlusPin, LOW);

  delay(10);
  
  return value;
}

int Reader::getEcgData() {
  if ((digitalRead(LO_PlusPin) == 1) || (digitalRead(LO_MinusPin) == 1)) {
    Serial.println('!');
    //BTserial.println('!');
    //delay(100);
    return -1;
  } else {
    return analogRead(A1);
  }
}
