from flask import Flask, render_template, make_response, request, current_app
from functools import update_wrapper

# for reading from the usb serial
import sys
import serial
import time
from datetime import timedelta

app = Flask(__name__)

# set crossdomain to true
def crossdomain(origin=None, methods=None, headers=None,
                max_age=21600, attach_to_all=True,
                automatic_options=True):
    if methods is not None:
        methods = ', '.join(sorted(x.upper() for x in methods))
    if headers is not None and not isinstance(headers, basestring):
        headers = ', '.join(x.upper() for x in headers)
    if not isinstance(origin, basestring):
        origin = ', '.join(origin)
    if isinstance(max_age, timedelta):
        max_age = max_age.total_seconds()

    def get_methods():
        if methods is not None:
            return methods

        options_resp = current_app.make_default_options_response()
        return options_resp.headers['allow']

    def decorator(f):
        def wrapped_function(*args, **kwargs):
            if automatic_options and request.method == 'OPTIONS':
                resp = current_app.make_default_options_response()
            else:
                resp = make_response(f(*args, **kwargs))
            if not attach_to_all and request.method != 'OPTIONS':
                return resp

            h = resp.headers
            h['Access-Control-Allow-Origin'] = origin
            h['Access-Control-Allow-Methods'] = get_methods()
            h['Access-Control-Max-Age'] = str(max_age)
            h['Access-Control-Allow-Credentials'] = 'true'
            h['Access-Control-Allow-Headers'] = \
                "Origin, X-Requested-With, Content-Type, Accept, Authorization"
            if headers is not None:
                h['Access-Control-Allow-Headers'] = headers
            return resp

        f.provide_automatic_options = False
        return update_wrapper(wrapped_function, f)
    return decorator

# init serial, open arduino to check the port that the arduino is using
ser = serial.Serial('/dev/ttyACM0')

# route to read from arduino
@app.route("/read_from_arduino", methods=['GET', 'OPTIONS'])
@crossdomain(origin='*')
def read_from_arduino():
	
	# output what the serial is saying
	output = ser.readline()

	# return the values
	return output

# route to turn on the water pomp
@app.route('/pomp/aan')
def pomp_state_on():

	ser.write('pomp_aan')

	return 'pomp_aan'

# route to turn off the water pomp
@app.route('/pomp/uit')
def pomp_state_off():

	ser.write('pomp_uit')

	return 'pomp_uit'

# render the dashboard
@app.route("/")
def hello():
	return render_template('home.html')

# run the app
if __name__ == "__main__":
    app.run(host='0.0.0.0')