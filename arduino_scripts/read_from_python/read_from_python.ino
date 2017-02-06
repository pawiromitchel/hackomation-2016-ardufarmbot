#include <dht.h>

// FOR RELAY CONTROL
String command;
int pomp = 13;

// TEMPERATURE + HUMIDITY LEVEL METER CONTROL
dht DHT;
#define DHT11_PIN 12

//Photocell
int photocellPin = 1;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider

void setup() {
  // serial port -> 9600
  Serial.begin(9600);
  pinMode(pomp, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  // PHOTOCELL CONTROL
  photocellReading = analogRead(photocellPin);
  Serial.print("[");
  Serial.print(photocellReading);
  
  // TEMPERATURE + HUMIDITY LEVEL METER CONTROL
  int chk = DHT.read11(DHT11_PIN);
  Serial.print(",");
  Serial.print(DHT.temperature);
  Serial.print(",");
  Serial.print(DHT.humidity);
  
  // HUMIDITY CONTROL
  int SensorValue = analogRead(A0); //take a sample
  Serial.print(",");
  Serial.print(SensorValue);
  Serial.println("]");
  
  digitalWrite(pomp, HIGH);
  
  // POMP CONTROL
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
  
  // stop for x sec
  delay(2000);
}
