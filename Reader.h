#ifndef Reader_H
#define Reader_H

#include<Arduino.h>

class Reader {
  public:
    Reader();
    ~Reader();
    int getEdaData();
    int getEcgData();
};

#endif
