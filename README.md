# About

This is a very simple library I made for one of my projects, so that i could have a volume control on my buzzer to not annoy my parents (as much) with the sound.

The volume percentage changes the buzzer volume based on perceptible sound

Library's only purpose right now is to give the buzzer a volume control through a pwm signal

## Volume control example:

``` C++
#include "AdvTone.h"

#define BuzzerPin 2
// Create an instance of AdvTone for the buzzer on pin 2 and channel 0
AdvTone buzzer = AdvTone(BuzzerPin, 0);

void setup() {}

void loop() {
  //loops through volume in steps of 5 (0,5,10,...,95,100);

  for(int i = 0; i <= 20; i++){
    //Plays 200hz frequency with i*5 volume for 50ms and awaits 50ms after
    buzzer.tone(200, i*5, 50);
    delay(50);
  }
}
```
