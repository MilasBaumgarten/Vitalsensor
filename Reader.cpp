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
  delay(1);

  int value = analogRead(A0);

  digitalWrite(EDA_PlusPin, LOW);

  delay(1);
  
  return value;
}

int Reader::getEcgData() {
  return ((digitalRead(LO_PlusPin) == 1) || (digitalRead(LO_MinusPin) == 1)) ? -1 : analogRead(A1);
}
