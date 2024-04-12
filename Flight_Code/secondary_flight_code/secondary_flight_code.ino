/* Secondary Flight Code */

# include "Hbridge.h"
# include "Photoresistor.h"

//Constants

      //Right Motor
  int rightMotor_pin1 = 6 ;
  int rightMotor_pin2 = 9 ;

      //Left Motor
  int leftMotor_pin1 = 3 ;
  int leftMotor_pin2 = 5 ;

      //Photoresistor Pins
  byte rightPhoto_pin = A1;
  byte leftPhoto_pin = A0;

  int DelayStart= 120000; //Delay before turning Motors on
  byte Photoresistor_Resistance=50; //Photoresistor associated resistance|Not used, but required for class defenitions

  float RightBrightness; //Brightness read by Right Photoresistor
  float LeftBrightness;  //Brightness read by left Photoresistor
  float RightOverLeftRatio; //Ratio of right brightness over left
  float fudgeFactor = .1; //
  float MinBrightness = 15; //Minimum required brightness to trigger control loop
  int loopDelay = 100;

  uint32_t timeStamp = 0;

  Hbridge rightMotor(rightMotor_pin1, rightMotor_pin2);
  Hbridge leftMotor(leftMotor_pin1, leftMotor_pin2);

  Photoresistor leftPhoto(leftPhoto_pin, Photoresistor_Resistance);
  Photoresistor rightPhoto(rightPhoto_pin,Photoresistor_Resistance);

void setup() {
  // put your setup code here, to run once:

  rightMotor.off();
  leftMotor.off();

  Serial.begin(9600);
  //delay(DelayStart);

}

void loop() {

RightBrightness= rightPhoto.CheckValue()+1;
LeftBrightness=leftPhoto.CheckValue()+1;

RightOverLeftRatio=RightBrightness/LeftBrightness;

if (RightBrightness>MinBrightness){
  if (RightOverLeftRatio>1+fudgeFactor) {
    //Motors to turn Right
    rightMotor.forward();
    leftMotor.backward();

  } else if(RightOverLeftRatio<1-fudgeFactor) {
    //Motors to turn Left
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
  
  delay(loopDelay);

  //Log Data
  timeStamp = millis();
  
  Serial.print(timeStamp);
  Serial.print(",");
  Serial.print(RightBrightness);
  Serial.print(",");
  Serial.print(LeftBrightness);
  Serial.println();
}
