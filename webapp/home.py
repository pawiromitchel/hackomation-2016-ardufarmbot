# using Python Flask Framework
# arch users : sudo pip install flask

from flask import Flask

# for reading from the usb serial
import serial

app = Flask(__name__)

# init serial, open arduino to check the port that the arduino is using
ser = serial.Serial('/dev/ttyACM0', 9600, 8, 'N', 1, timeout=5)

# a simple route
@app.route("/")
def hello():
	# output what the serial is saying
    return ser.readline()

# run the app
if __name__ == "__main__":
    app.run()