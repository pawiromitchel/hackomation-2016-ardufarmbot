#!/usr/bin/python

import serial

# init serial, open arduino to check the port that the arduino is using
ser = serial.Serial('/dev/ttyACM0', 9600, 8, 'N', 1, timeout=5)

# loop the script
while True:
    print(ser.readline())