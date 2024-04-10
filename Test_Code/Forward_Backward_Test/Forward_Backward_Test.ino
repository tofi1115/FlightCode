/* Motor Hardware Test Code */

void setup() {
  // Motor Pin Variables
  int motor_pin1 = ;
  int motor_pin2 = ;

  //
  pinMode(motor_pin1, OUTPUT);
  pinMode(motor_pin2,OUTPUT);

}

void loop() {

  digitalWrite(motor_pin1, HIGH); //Go Direction 1
  delay(1000);

  digitalWrite(motor_pin2, HIGH); //Go Direction 2
  delay(1000);

}
