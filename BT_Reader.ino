// EDA Tutorial: https://www.instructables.com/id/Arduino-Lie-Detector/
// ECG Tutorial: https://learn.sparkfun.com/tutorials/ad8232-heart-rate-monitor-hookup-guide/all

// SLAVE : 00:18:E4:40:00:06

#include <SoftwareSerial.h>
#include "Reader.h"
#include "Time.h"

#define RXPin 10
#define TXPin 11

#define SENSOR true

#define frameDelay 0
#define edaFrequency 2 // in Hertz
#define ecgThreshold 50

SoftwareSerial BTserial(RXPin, TXPin);
 
const long baudRate = 9600; // baudRate to change Settings in the Bluetooth Module = 38400

int lastEDA = 0;
int currentEDA = 0;
int currentECG;

int currentStep = 0;

Reader reader;
Time time;
 
void setup() {
    Serial.begin(9600);
    BTserial.begin(baudRate); 
}

void loop() {
  checkSerial();
  checkBluetooth();
  
  if (!SENSOR) {return;}

  time.update();
  
  String out = (String) millis();
  currentStep += time.deltaTime;

  // meassure skin conductivity n time per second
  if (currentStep >= (1000 / edaFrequency)) {
    currentStep -= (1000 / edaFrequency);
    lastEDA = currentEDA;
    currentEDA = reader.getEdaData();
  } else {
    // get ecg data
    int ecg = reader.getEcgData();

    if (ecg > ecgThreshold) {
      currentECG = ecg;
    }
  }
  
  // lerp eda data to account for the meassurement frequency
  int edaData = floor(lastEDA + (currentStep / (1000.0f / edaFrequency) * (currentEDA - lastEDA)));
  
  out += " " + String(edaData) + " " + String(currentECG) + " " + String(time.deltaTime) + ";";
  
  // send out data
  Serial.print(out + "\n");
  BTserial.print(out + "\n");

  delay(frameDelay);
}

// Read from the Serial Monitor and send to the Bluetooth module
void checkSerial() {
  if (Serial.available()) {
    char in = Serial.read();
    Serial.write(in);  // echo serial input
    BTserial.write(in);
  }
}

// Read from the Bluetooth module and send to the Arduino Serial Monitor
void checkBluetooth() {
  if (BTserial.available()) {
    char in = BTserial.read();
    Serial.write(in);
  }
}
