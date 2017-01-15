#!/usr/bin/python

import serial

ser = serial.Serial('/dev/ttyACM1', 9600, 8, 'N', 1, timeout=5)

while True:
    print(ser.readline())