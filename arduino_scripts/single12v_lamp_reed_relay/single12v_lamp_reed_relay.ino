/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
String command;
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int pomp = 13;

// the setup routine runs once when you press reset:
void setup() {        
  Serial.begin(9600);  
  // initialize the digital pin as an output.
  pinMode(pomp, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available()) {
    command = Serial.readString();
    if (command == "pomp_aan"){
      // control de pomp
      if(digitalRead(pomp) == LOW){
        digitalWrite(pomp, HIGH);
      }
    }
    if (command == "pomp_uit"){
      // control de pomp
      if(digitalRead(pomp) == HIGH){
        digitalWrite(pomp, LOW);
      }
    }
  } 
}
