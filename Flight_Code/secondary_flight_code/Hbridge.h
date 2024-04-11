/* H-Bridge header file */

// prevents class from being defined multiple times
#ifndef MY_HBRIDGE_H
#define MY_HBRIDGE_H

#include <Arduino.h>

// defines Hbridge class
class Hbridge {

private:
  byte pwm1;  // IN1
  byte pwm2;  // IN2

public:
  Hbridge(byte pwm1, byte pwm2);
  void init();
  void forward();
  void backward();
  void off();
  void hold();
};

#endif