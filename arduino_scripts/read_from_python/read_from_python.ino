// de command dat de python aan de arduino geeft
String command;

// de pin van de pomp
int pomp = 13;

void setup() {
  // serial port -> 9600
  Serial.begin(9600);
  pinMode(pomp, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    command = Serial.readString();
    Serial.println(command);
    
    if (command == "pomp_aan"){
      // control de pomp
      if(digitalRead(pomp) == LOW){
        delay(200);
        digitalWrite(pomp, HIGH);
      }
    }
    
    if (command == "pomp_uit"){
      // control de pomp
      if(digitalRead(pomp) == HIGH){
        delay(200);
        digitalWrite(pomp, LOW);
      }
    }
  }
}
