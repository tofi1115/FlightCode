#include "Photoresistor.h"

Photoresistor::Photoresistor(byte pin, byte resistor) {
  this->resistor = resistor;
  this->pin = pin;
  init();
}

// set up thermistor pins
void Photoresistor::init() {
  pinMode(pin, INPUT);
}

int Photoresistor::CheckValue(){
  float reading = analogeRead(pin);
  return reading;
}