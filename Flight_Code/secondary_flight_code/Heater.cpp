#include "Heater.h"

Heater::Heater(byte pin) {
  this->pin = pin;
  init();
}

// set up thermistor pins
void Heater::init() {
  pinMode(pin, OUTPUT);
}

void Heater::On(){
  analogWrite(pin, 255); //Turn On

}
void Heater::Off(){
  analogWrite(pwm1, 0); //Turn Off

}