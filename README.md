# Hackomation 2016

## Stap 0 Setting up your Rasberry

`sudo gpasswd --add ${USER} dialout`

De packages die nodig zijn voor python zijn: 
- python
- flask (renderen van de html pagina's)
- pyserial (communiceren met de USB module)
- ino (uploaden van arduino scripts)

```
sudo apt-get -y install python python-pip
sudo pip install flask pyserial ino
```

## Stap 1 Testen als je Rasberry uit de arduino kan uitlezen (Arduino ~> Rasberry Pi)
### Arduino
Upload dit naar je arduino ~> https://github.com/pawiromitchel/ardufarmbot/blob/master/arduino_scripts/simple_serial_output/simple_serial_output.ino

```
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello mitchel!");
  delay(2000);
}
```
### Python script op de Rasberry Pi
Lezen uit de arduino script ~> https://github.com/pawiromitchel/ardufarmbot/blob/master/python_scripts/read_from_arduino.py

Om te weten wat de port is, maak de Arduino IDE open en check port in de menu

Bij mij is de port `/dev/ttyACM0`

```

#!/usr/bin/python

import serial

# init serial, open arduino to check the port that the arduino is using
ser = serial.Serial('/dev/ttyACM0', 9600, 8, 'N', 1, timeout=5)

# loop the script
while True:
    print(ser.readline())
    
```

Om dit te runnen doe je `python read_from_arduino.py`

## Stap 2 Testen als je data kan versturen naar de arduino (Rasberry Pi ~> Arduino)
### Arduino
Uploaden van de script naar de Arduino ~> https://github.com/pawiromitchel/ardufarmbot/blob/master/arduino_scripts/read_from_python/read_from_python.ino
```
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
```


### Python script op de Rasberry Pi

Versturen van data naar de Arduin ~> https://github.com/pawiromitchel/ardufarmbot/blob/master/python_scripts/send_to_arduino.py
```
#!/usr/bin/python

import sys
import serial
import time

# init serial, open arduino to check the port that the arduino is using
ser = serial.Serial('/dev/ttyACM0')

# let the arduino rest
time.sleep(1.5)

# write stuff to it!
ser.write('pomp_aan')
time.sleep(1.5)
ser.write('pomp_uit')
ser.close()
```

## Stap 3 Maken van een webapplicatie
Als stap 1 en 2 hebben gewerkt dan is het nu tijd om een webapplicatie te bouwen


In de https://github.com/pawiromitchel/ardufarmbot/tree/master/applicatie folder bestaat er een __init__.py. 

Bij mij is de port `/dev/ttyACM0`

### De Server
Om de python server te runnen is deze command nodig:
```
python __init__.py
```

### Static
https://github.com/pawiromitchel/ardufarmbot/tree/master/applicatie/static

Hierin zitten libraries van de applicatie. Die MAG je veranderen, maar het is niet aangeraden!
### Templates
https://github.com/pawiromitchel/ardufarmbot/tree/master/applicatie/templates

Hierin zitten de templates van de applicatie. Wanneer dat aangepast wordt, MOET de server opnieuw gestart worden voordat het effect heeft op de applicatie. 

<img src="https://raw.githubusercontent.com/pawiromitchel/ardufarmbot/master/img/De%20applicatie%20met%20buttons.jpg">
