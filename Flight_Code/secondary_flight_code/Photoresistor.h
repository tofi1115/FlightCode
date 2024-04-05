/* Photoresistor header file */

// prevents class from being defined multiple times
#ifndef MY_PHOTORESISTOR
#define MY_PHOTOERSISTOR

#include <Arduino.h>

// defines Hbridge class
class Photoresistor {

private:
  byte pin;
  byte resistor;

public:
  Photoresistor(byte pin, byte resistor);
  float CheckValue();
};

#endif