#include "AdvTone.h"
#include "cmath"

// Constructor
AdvTone::AdvTone(int pin, byte LEDC_CHANNEL) {
    _pin = pin;
    _ledc_channel = LEDC_CHANNEL;

    //Ledc channels ranges from 0-7;
    if(_ledc_channel > 7){
        _ledc_channel = 0;
    }

    ledcSetup(_ledc_channel, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
    ledcAttachPin(_pin, _ledc_channel);
}

// Tone function
void AdvTone::tone(unsigned int Frequency, byte Volume) {
    if (Volume > 100) {
        Volume = 100;
    }

    //Applies Stevens' power law for a seemingly more linear change in sound perception.
    double k = 30.14268; //Value where if volume == 100, volumeSetting == 100
    double volumeSetting = pow((Volume + 20) / k, 1/0.3);
    int dutyCycle = (8191 / 100) * volumeSetting;

    ledcSetup(_ledc_channel, Frequency, LEDC_TIMER_13_BIT);
    ledcWrite(_ledc_channel, dutyCycle);
}

// NoTone function
void AdvTone::noTone() {
    ledcWrite(_ledc_channel, 0);
}

// Tone function with duration
void AdvTone::tone(unsigned int Frequency, byte Volume, unsigned long Duration) {
    this->tone(Frequency, Volume);

    delay(Duration);

    this->noTone();
}
