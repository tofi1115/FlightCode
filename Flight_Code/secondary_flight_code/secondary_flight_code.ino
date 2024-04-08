/* Secondary Flight Code */

# include "Hbridge.h"
# include "Photoresistor.h"
# include "Heater.h"

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
  float MaxDifference; //maximum differebnce between brightnesses

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

  RightBrightness = RightPhotoresistor.CheckValue();
  LeftBrightness=LeftPhotoresistor.CheckValue(); 

if (LeftBrightness-RightBrightness>MaxDifference){ // Move Left
  motor1.forward();
  motor2.backward();
}
else if (RightBrighrtness-LeftBrightness<-MaxDifference){ //Move Right
  motor1.backward();
  motor2.forward()
}
Heater.On();
delay(100);
  
  RightBrightness = RightPhotoresistor.CheckValue();
  LeftBrightness=LeftPhotoresistor.CheckValue(); 

if (LeftBrightness-RightBrightness>MaxDifference){ // Move Left
  motor1.forward();
  motor2.backward();
}
else if (RightBrighrtness-LeftBrightness<-MaxDifference){ //Move Right
  motor1.backward();
  motor2.forward()
}
Heater.Off();
delay(100);



}
