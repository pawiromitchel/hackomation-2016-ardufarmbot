#!/usr/bin/python

import serial

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=2.5)

while True:
	ser.write('give_results')
	print(ser.read(100))