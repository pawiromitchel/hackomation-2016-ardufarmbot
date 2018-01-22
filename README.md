# Hackomation 2016

## Stap 0 Setting up

`sudo gpasswd --add ${USER} dialout`

De packages die nodig zijn voor python zijn: 
- python
- flask (renderen van de html pagina's)
- pyserial (communiceren met de USB module)
- ino (uploaden van arduino scripts)

```
sudo apt-get -y install python
sudo pip install flask pyserial ino
```

## Stap 1 Uploaden naar de Arduino
Upload dit naar je arduino ~> https://github.com/pawiromitchel/hackomation-2016-ardufarmbot/blob/master/arduino_scripts/simple_serial_output/simple_serial_output.ino

## Stap 2 Testen als python de Arduino outputs kan uitlezen

Lezen uit de arduino script ~> https://github.com/pawiromitchel/hackomation-2016-ardufarmbot/blob/master/python_scripts/read_from_arduino.py

Hier is de port `/dev/ttyACM0`

Om te weten wat de port is, maar de Arduino IDE open en check port in de menu

```
