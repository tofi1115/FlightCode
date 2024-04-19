/* H-Bridge code */
#include "Hbridge.h"

Hbridge::Hbridge(byte pwm1, byte pwm2) {
  this->pwm1 = pwm1;
  this->pwm2 = pwm2;
  init();
}

// Set up Hbridge pinns
void Hbridge::init() {
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  off();
}

// heat build surface
void Hbridge::forward() {
  analogWrite(pwm1, 0);    // Low
  analogWrite(pwm2, 255);  // High
}

//cool build surface
void Hbridge::backward() {
  analogWrite(pwm1, 255);  // High
  analogWrite(pwm2, 0);    // Low
}

//stop or standby mode
void Hbridge::off() {
  analogWrite(pwm1, 0);  // Low
  analogWrite(pwm2, 0);  // Low
}
void Hbridge::hold(){
  analogWrite(pwm1, 255);  // Low
  analogWrite(pwm2, 255);
}