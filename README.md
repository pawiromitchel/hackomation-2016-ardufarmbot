# Hackomation 2016

## Stap 1 Uploaden naar de Arduino
Upload dit naar je arduino ~> https://github.com/pawiromitchel/ardufarmbot/blob/master/simple_serial_output/simple_serial_output.ino

## Stap 2 Testen als python de Arduino outputs kan uitlezen

De packages die nodig zijn voor python zijn: 
- python
- flask (renderen van de html pagina's)
- pyserial (communiceren met de USB module)
- ino (uploaden van arduino scripts)

```
sudo apt-get -y install python
sudo pip install flask pyserial ino
```

Lezen uit de arduino script ~> https://github.com/pawiromitchel/ardufarmbot/blob/master/read_from_arduino.py

Hier is de port `/dev/ttyACM0`

Om te weten wat de port is, maar de Arduino IDE open en check port in de menu

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

## Stap 4 Runnen van de server
In de webapp/ folder bestaat er een __init__.py. Om de python server te runnen is deze command nodig:

```
python __init__.py
```

Als het niet werkt, moet je je port checken in de source code van de __init__.py


