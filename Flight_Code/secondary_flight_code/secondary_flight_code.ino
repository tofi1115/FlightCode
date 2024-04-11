/* Secondary Flight Code */

# include "Hbridge.h"
# include "Photoresistor.h"

  // Pin Constants
      // potentially change to data type byte if this doesn't work

      //Right Motor
  int rightMotor_pin1 = 6 ;
  int rightMotor_pin2 = 9 ;

      //Left Motor
  int leftMotor_pin1 = 3 ;
  int leftMotor_pin2 = 5 ;

  byte rightPhoto_pin = A1;
  byte leftPhoto_pin = A0;

  int Photoresistor_Resistance = 50; // Used for calculating actual Photoresistor value
  int DelayStart= 120000;

  float RightBrightness;
  float LeftBrightness;
  float RightOverLeftRatio;
  float fudgeFactor = .1;

  Hbridge rightMotor(rightMotor_pin1, rightMotor_pin2);
  Hbridge leftMotor(leftMotor_pin1, leftMotor_pin2);

  Photoresistor leftPhoto(leftPhoto_pin, Photoresistor_Resistance);
  Photoresistor rightPhoto(rightPhoto_pin,Photoresistor_Resistance);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {

RightBrightness= rightPhoto.CheckValue()+1;
LeftBrightness=leftPhoto.CheckValue()+1;

RightOverLeftRatio=RightBrightness/LeftBrightness;
if (RightBrightness>100){
if (RightOverLeftRatio>1+fudgeFactor) {
  //Motors to turn Right
  Serial.print("Right");
  rightMotor.forward();
  leftMotor.backward();

} else if(RightOverLeftRatio<1-fudgeFactor) {
  //Motors to turn Left
  Serial.print("Left");
  rightMotor.backward();
  leftMotor.forward();

} else {
  rightMotor.hold();
  leftMotor.hold();
}
} else {
  rightMotor.forward();
  leftMotor.backward();
}


}
