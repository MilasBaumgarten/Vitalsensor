#include "Time.h"

unsigned long lastMillis = 0;

// delta Time in milli seconds
int deltaTime;

void Time::update() {
  deltaTime = millis() - lastMillis;
  lastMillis = millis();
}
