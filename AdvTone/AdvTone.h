#ifndef ADVTONE_H
#define ADVTONE_H

#include "Arduino.h"

class AdvTone{
  public:
    AdvTone(int pin, byte LEDC_CHANNEL);

    void tone(unsigned int Frequency, byte Volume);
    void tone(unsigned int Frequency, byte Volume, unsigned long Duration);

    void noTone();

  private:
    int _pin;
    byte _ledc_channel;

    static const int LEDC_TIMER_13_BIT = 13;
    static const int LEDC_BASE_FREQ = 0;
};

#endif