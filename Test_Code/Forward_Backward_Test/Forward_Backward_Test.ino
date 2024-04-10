/* Motor Hardware Test Code */
/* Test Directions Motors Turn*/

  int motor_pin1 = ;
  int motor_pin2 = ;

//When Testing, Indicate the Directions of Motor Rotation In this Code

void setup() {

  //
  pinMode(motor_pin1, OUTPUT);
  pinMode(motor_pin2,OUTPUT);

  analogWrite(motor_pin1, 0);
  analogWrite(motor_pin2, 0);


}

void loop() {
  //Go Direction 1
  analogWrite(motor_pin1, 255);
  analogWrite(motor_pin2, 0);
  delay(1000);

  //Stop
  analogWrite(motor_pin1, 0);
  analogWrite(motor_pin2, 0);
  delay(1000);

  //Go Directionl 2
  analogWrite(motor_pin1, 0);
  analogWrite(motor_pin2, 255);
  delay(1000);

  //Stop
  analogWrite(motor_pin1, 0);
  analogWrite(motor_pin2, 0);
  delay(1000);
}
