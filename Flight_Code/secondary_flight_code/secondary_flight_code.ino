/* Secondary Flight Code */

# include "Hbridge.h"
# include "Photoresistor.h"

//Constants

      //Right Motor
  int const rightMotor_pin1 = 6 ;
  int const rightMotor_pin2 = 9 ;

      //Left Motor
  int const leftMotor_pin1 = 3 ;
  int const leftMotor_pin2 = 5 ;

  //LED indicating Arduino is on
  int const LED_pin = 11;

      //Photoresistor Pins
  byte const rightPhoto_pin = A1;
  byte const leftPhoto_pin = A0;

  int DelayStart= 200000; //Delay before turning Motors on
  int TurnDelay=10000; //Delay while module turns around
  byte const Photoresistor_Resistance=50; //Photoresistor associated resistance|Not used, but required for class defenitions

  //Constant throughout Flight
  float RightBrightness; //Brightness read by Right Photoresistor
  float LeftBrightness;  //Brightness read by left Photoresistor
  float RightOverLeftRatio; //Ratio of right brightness over left
  float const fudgeFactor = .2; //
  int const loopDelay = 15;

  //Variable Through Flight
  float MinBrightness = 0; //Minimum required brightness found in tuning initially 0
  float MaxBrightness = 0; //Maximum brightness found in tuning initially 0
  float MinTriggerBrightness; //Brightness under which the module will turn to oe direction until brightness values are higher

  uint32_t timeStamp = 0;

  //Define Motors
  Hbridge rightMotor(rightMotor_pin1, rightMotor_pin2);
  Hbridge leftMotor(leftMotor_pin1, leftMotor_pin2);
  
  //Define Photoresistors
  Photoresistor leftPhoto(leftPhoto_pin, Photoresistor_Resistance);
  Photoresistor rightPhoto(rightPhoto_pin,Photoresistor_Resistance);

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_pin, OUTPUT);

  digitalWrite(LED_pin, HIGH);

  Serial.begin(9600);
  //delay(DelayStart);
  int preSpinMilis=millis();
  while(TurnDelay+preSpinMilis>millis()){

    //Spin Arround for 10 seconds  
    rightMotor.forward();
    leftMotor.backward();
    delay(loopDelay);

    if (MinBrightness > (((rightPhoto.CheckValue()+1)+leftPhoto.CheckValue()+1)/2)){

      MinBrightness = ((rightPhoto.CheckValue()+1)+leftPhoto.CheckValue()+1)/2;

    }
    if (MaxBrightness < (((rightPhoto.CheckValue()+1)+leftPhoto.CheckValue()+1)/2)){

      MaxBrightness = ((rightPhoto.CheckValue()+1)+leftPhoto.CheckValue()+1)/2;
    }
  }

  MinTriggerBrightness=(MinBrightness+(MaxBrightness-MinBrightness)*.2);
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
