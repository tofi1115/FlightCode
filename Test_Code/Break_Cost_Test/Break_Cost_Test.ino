/* Motor Hardware Test Code */
/* Test Motor Off vs Break Mode */

  int motor_pin1 = ;
  int motor_pin2 = ;

void setup() {
  //
  pinMode(motor_pin1, OUTPUT);
  pinMode(motor_pin2,OUTPUT);

  analogWrite(motor_pin1, 0);
  analogWrite(motor_pin2, 0);

}

void loop() {

  //put motor into Break Mode
  analogWrite(motor_pin1, 255);
  analogWrite(motor_pin2,255);
  delay(1000);

  //put motor into Coast Mode
  analogWrite(motor_pin1, 255);
  analogWrite(motor_pin2,255);
  delay(1000);  


}
