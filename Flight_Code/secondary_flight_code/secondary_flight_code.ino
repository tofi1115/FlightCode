/* Secondary Flight Code */

# include "Hbridge.h"

  // Pin Constants
      // potentially change to data type byte if this doesn't work
      // Also maybe make a seperate constants piece at some point...
  int dig1 = ;
  int dig2 = ;
  int dig3 = ;
  int dig4 = ;
  byte An0 = ;
  byte An1 = ;
  int Photoresistor_Resistance = ;
  int DelayStart= 12000 ;

  float RightBrightness;
  float LeftBrightness;
  float RightRatio;
  float LeftRatio;
  float MinValue; //minimum triggering value

  Photoresistor RightPhotoresistor(An0, Photoresistor_Resistance);
  Photoresistor LeftPhotoresistor(An1, Photoresistor_Resistance);

  Hbridge motor1();
  Hbridge motor2();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(DelayStart);
}

void loop() {
  // put your main code here, to run repeatedly:
  RightBrightness = RightPhotoresistor.CheckValue();
  LeftBrightness=LeftPhotoresistor.CheckValue(); 

  RightRatio=RightBrightness/(RightBrightness/LeftBrightness);
  LeftRatio=LeftBrightness/(RightBrightness/LeftBrightness);

  if ()

}
