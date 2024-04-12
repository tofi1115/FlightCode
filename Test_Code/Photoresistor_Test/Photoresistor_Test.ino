/* Photoresistor Hardware Test Code */

  //Photoresistor Input Values
  int photoresistor1 = A0; //Left
  int photoresistor2 = A1; //Right

  //Values of Photoresistors
  int value1;
  int value2;

void setup() {

  // set pin modes
  pinMode(photoresistor1, INPUT);
  pinMode(photoresistor2, INPUT);

  Serial.begin(9600);
  Serial.println("Value1  Value2");

}

void loop() {
  
  // read photoresistor values
  value1 = analogRead(photoresistor1);
  value2 = analogRead(photoresistor2);

  //Print results to Serial Monitor
  Serial.print(value1); 
  Serial.print("  ");
  Serial.print(value2); 
  Serial.println("  ");

}
