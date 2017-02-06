#include <dht.h>

//DHT11
dht DHT;
#define DHT11_PIN 3

//Photocell
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider

//Soil sensor
byte humidity_sensor_pin = A1;
byte humidity_sensor_vcc = 6;


void setup(void) {
  // We'll send debugging information via the Serial monitor
  while (!Serial);
  delay(1000);
  Serial.begin(9600);  
}

 int read_humidity_sensor() {
  digitalWrite(humidity_sensor_vcc, HIGH);
  delay(500);
  int value = analogRead(humidity_sensor_pin);
  digitalWrite(humidity_sensor_vcc, LOW);
  return 1023 - value;
  }
void loop(void) {
  
  int chk = DHT.read11(DHT11_PIN);

  
  photocellReading = analogRead(photocellPin);  


  
  Serial.print("Light reading = ");
  Serial.print(photocellReading);    
  Serial.print(" Temperature = ");
  Serial.print(DHT.temperature);
  Serial.print(" Humidity = ");
  Serial.print(DHT.humidity);
  Serial.print(" Humidity Level (0-1023): ");
  Serial.println(read_humidity_sensor());
  
  
 
 
  delay(1000);
}
