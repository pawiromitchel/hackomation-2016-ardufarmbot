# Ardufarmbot

####The basics:
This device will water your plants for you. 

####The details:
- The brains of the irrigation system is an Arduino Uno with sensors (see parts list)
- At first it will measure the air temperature. If that is at least 5°C, the program will continue, otherwise it will stop, because it's too cold for watering.
- Then it will check if there's enough water in the reservoir (e.g. a simple bucket) using an ultrasonic sensor. If there isn't, the pump won't switch on, because dry-running would damage it. If there is:
- Next it will check if watering is even necessary using a soil moisture sensor. If watering isn't required, nothing will happen obviously and the measuring cycle will repeat after a few minutes. If the soil is too dry:
- The RF transmitter will switch on the remote control power socket for 10 seconds which will supply power to the pump, thus watering your plants.
- The measuring cycle will repeat after a minute until soil moisture exceeds the given threshold value. This intermittent watering (10 seconds every minute) has proven to be better than continuous watering, because the water needs some time to sink down to the bottom of the planter, where the soil moisture sensor is positioned. With continuous watering, there would be already too much water in the planter before the sensor can detect it.
- A timer switch between mains power and the device is recommended. A setting that provides power twice a day (mornings and evenings) will prevent watering around noon, which may cause damage to your plants and is a waste of water anyway.
