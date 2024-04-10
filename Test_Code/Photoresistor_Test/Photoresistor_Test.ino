/* Photoresistor Hardware Test Code */

  //Photoresistor Input Values
  const int A0 = ;
  const int A1 = ;

  //Values of Photoresistors
  int value1;
  int value2;

void setup() {

  // set pin modes
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.println("Value1  Value2");

}

void loop() {
  
  // read photoresistor values
  value1 = analogRead(A0);
  value2 = analogRead(A1);

  //Print results to Serial Monitor
  Serial.println(Value1, "  ", Value2);



  


}
