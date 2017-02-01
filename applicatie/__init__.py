from flask import Flask, render_template

# for reading from the usb serial
import serial

app = Flask(__name__)

# route to read from arduino
@app.route("/read_from_arduino")
def read_from_arduino():
	# init serial, open arduino to check the port that the arduino is using
	ser = serial.Serial('/dev/ttyACM0', 9600, 8, 'N', 1, timeout=5)

	# output what the serial is saying
	output = ser.readline()

	# return the values
	return output

# render the dashboard
@app.route("/")
def hello():
	return render_template('home.html')

# run the app
if __name__ == "__main__":
    app.run()