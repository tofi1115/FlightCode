/* Heater header file */

// prevents class from being defined multiple times
#ifndef MY_HEATER
#define MY_HEATER

#include <Arduino.h>

// defines Hbridge class
class Heater {

private:
  byte pin;

public:
void Heater(byte pin);
void On();
void Off();
};

#endif