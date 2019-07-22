#ifndef Time_H
#define Time_H

#include<Arduino.h>

class Time {
  public:
    void update();
    int deltaTime;
};

#endif
