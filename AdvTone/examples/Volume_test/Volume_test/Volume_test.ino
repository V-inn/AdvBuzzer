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