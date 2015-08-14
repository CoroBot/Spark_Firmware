#!/usr/bin/env python

# Script for PSOC4 exercise

from cobs_serial import cobs_serial
import struct
import hid
import sys

#USB Constants
#coroware_VID = 0x2bd6 #Issued by USB-IF
#spark_PID = 0xff02 #Development hardware - will change when device is released

menu_header = """
****************************
**** PSOC4 Control Test ****
****************************
"""

motor_menu = """
Select which motor to control:
  0. (reserved, currently no function)
  1. Front
  2. Rear
  3. Both
  4. STOP ALL MOTORS
  5. Exit
  
  >>"""

option_menu = """
Option menu:
  0. Direction
  1. Speed
  2. Encoder
  3. Current
  4. Mode
  5. Power
  6. STOP ALL MOTORS
  7. Exit
  
  Please Enter a number from above menu >>"""
  
getset_menu = """
Get or Set functionality?
  0. Get
  1. Set
  
  >>"""
  
def main():
	print menu_header
	
	# Open the serial port
	# ************************** USER ENTERED PORT ***************************
	#port = raw_input("Enter your serial port (EX: COM14)\n>>")
	#cobs = cobs_serial(port, 115200, 1)
	
	# ************************** DEFAULT DEBUG PORT ***************************
	print "Defaulting port to COM17. Change script if neeeded"
	cobs = cobs_serial('COM17', 115200, 1)
	
	# *************************** END PORT CONFIG ****************************
	
	#User Menu
	#Loop until user quits	
	
	while True:
		#sys.stderr.write("\x1b[2J\x1b[H")
		#print("\033c");
		#clear()
		
		print menu_header

		# ask the user for the motor and command type
		motornum = getNumInRange(0, 5, motor_menu);
		if motornum == -1 or motornum == 0:
			continue
		if motornum == 4:
			stopMotors(cobs)
			continue
		if motornum == 5:
			break		

		type = getNumInRange(0, 7, option_menu)
		if type == -1: 
			continue
		
		# decide how to handle user input
		if type == 7:
			break
		elif type == 0: #DIRECTION
			do_direction(motornum, type, cobs)
		elif type == 1: #SPEED
			do_speed(motornum, type, cobs)
		elif type == 2: #ENCODER
			do_encoder(motornum, type, cobs)
		elif type == 3: #CURRENT
			do_current(motornum, type, cobs)
		elif type == 4: #MODE
			do_mode(motornum, type, cobs)
		elif type == 5: #POWER
			do_power(motornum, type, cobs);
		elif type == 6: #STOP MOTORS
			stopMotors(cobs)

def stopMotors(cobs):
	cmd = bytearray([0x3, 0x1, 0x1, 0x0, 0x0])
	writeToSerial(cmd, cobs)
	
# Returns a number after prompting the user for a number (or the custom prompt 
# provided in the argument). Returns -1 if the number is out of the range or 
# not a number format. The default range is 16bits (0, 65535).	
def getNumInRange(min = 0, max = 65535, prompt="Please enter a number >>"):
	try:
		returnMe = int(raw_input(prompt))
	except:
		print "Error: The input cannot be converted to an integer."
		return -1
	if (returnMe < min or returnMe > max): 
		print "Error: The input is out of range: " + repr(min) + ", " + repr(max)
		return -1
	return returnMe
	
def writeToSerial(buf, cobs):
	try:
		cobs.encode_and_send(buf)
	except:
		print "Error: Could not write to serial. Try power cycling board."
		print "Additional Info: Buffer contents " + repr(list(buf))

def getResponse(cobs, debug = False):
	retarray = cobs.block_and_return()
	if debug:
		print "Cobs decode result array: "
		print repr(retarray)
	
	try:
		decoded_data = struct.unpack('>H', retarray)
		return decoded_data[0]
		#print "Direction of motor #" + repr(motornum) + ": " + repr(int(direction_returned[0]))
	except:
		print "Error converting incoming value to an int."	
		return -1

def prepareCommand(motornum, getset, option):
	returnMe = bytearray()
	returnMe += struct.pack('B', motornum)
	returnMe += struct.pack('B', getset)
	returnMe += struct.pack('B', option)
	return returnMe
		
def do_direction(motornum, type, cobs, debug = False):
	getset = getNumInRange(0,1, getset_menu)
	cmd = prepareCommand(motornum, getset, 0) #0 for option direction
	
	if getset == 1:
		input = getNumInRange(0,1, "\nChoose direction:\n  0. Forward\n  1. Reverse\n  >>")
		if input == -1:
			return
		cmd += struct.pack('>H', input)
	else:
		cmd += struct.pack('>H', 0)
		
	if debug:
		print "Debug: Sending bytes to encode and send: " + repr(list(cmd)) 
		
	#cobs.encode_and_send(cmd) 
	writeToSerial(cmd, cobs)

	#If a return value is expected, recieve and print it.
	if getset == 0:
		response = getResponse(cobs, debug) 
		if response != -1:
			print "Direction of motor #" + repr(motornum) + ": " + repr(response)
			
	raw_input("\nPress enter to continue...")
		
def do_speed(motornum, type, cobs, debug = False):
	getset = getNumInRange(0,1, getset_menu)
	cmd = prepareCommand(motornum, getset, 1) 
	
	if getset == 1:
		input = getNumInRange(0,65535, "\nEnter a 16bit integer for new speed (0-65535) >>")
		if input == -1:
			return
		cmd += struct.pack('>H', input)
	else:
		cmd += struct.pack('>H', 0)
		
	if debug:
		print "Debug: Sending bytes to encode and send: " + repr(list(cmd)) 
		
	writeToSerial(cmd, cobs)

	#If a return value is expected, recieve and print it.
	if getset == 0:
		response = getResponse(cobs, debug) 
		if response != -1:
			print "Speed of motor #" + repr(motornum) + ": " + repr(response)
			
	raw_input("\nPress enter to continue...")
	
	
def do_encoder(motornum, type, cobs, debug = False):
	getset = 0
	cmd = prepareCommand(motornum, getset, 2) 
	cmd += struct.pack('>H', 0)
		
	if debug:
		print "Debug: Sending bytes to encode and send: " + repr(list(cmd)) 
		
	writeToSerial(cmd, cobs) 

	#If a return value is expected, recieve and print it.
	response = getResponse(cobs, debug) 
	if response != -1:
		print "Encoder return value of motor #" + repr(motornum) + ": " + repr(response)
			
	raw_input("\nPress enter to continue...")
	
	
def do_current(motornum, type, cobs, debug = False):
	getset = 0
	cmd = prepareCommand(motornum, getset, 3) 
	cmd += struct.pack('>H', 0)
		
	if debug:
		print "Debug: Sending bytes to encode and send: " + repr(list(cmd)) 
		
	writeToSerial(cmd, cobs)

	#If a return value is expected, recieve and print it.
	response = getResponse(cobs, debug) 
	if response != -1:
		print "Current value of motor #" + repr(motornum) + ": " + repr(response)
			
	raw_input("\nPress enter to continue...")
	
def do_mode(motornum, type, cobs, debug = False):
	getset = getNumInRange(0,1, getset_menu)
	cmd = prepareCommand(motornum, getset, 4) 
	
	if getset == 1:
		input = getNumInRange(0,1, "\nChoose mode: (0 or 1) >>")
		if input == -1:
			return
		cmd += struct.pack('>H', input)
	else:
		cmd += struct.pack('>H', 0)
		
	if debug:
		print "Debug: Sending bytes to encode and send: " + repr(list(cmd)) 
		
	writeToSerial(cmd, cobs)

	#If a return value is expected, recieve and print it.
	if getset == 0:
		response = getResponse(cobs, debug) 
		if response != -1:
			print "Mode of motor #" + repr(motornum) + ": " + repr(response)
			
	raw_input("\nPress enter to continue...")

def do_power(motornum, type, cobs, debug = False):
	getset = getNumInRange(0,1, getset_menu)
	cmd = prepareCommand(motornum, getset, 5)
	
	if getset == 1:
		input = getNumInRange(0,1, "\nChoose power setting: (0 or 1) >>")
		if input == -1:
			return
		cmd += struct.pack('>H', input)
	else:
		cmd += struct.pack('>H', 0)
		
	if debug:
		print "Debug: Sending bytes to encode and send: " + repr(list(cmd)) 
		
	writeToSerial(cmd, cobs)

	#If a return value is expected, recieve and print it.
	if getset == 0:
		response = getResponse(cobs, debug) 
		if response != -1:
			print "Power state of motor #" + repr(motornum) + ": " + repr(response)
			
	raw_input("\nPress enter to continue...")
		
		
		

#################### OLD FUNCTIONS #########################		
		
def do_led(cobs):
	print "LED Control"
	option = raw_input("Enter an LED to control, 1-3\n>>")
	try:
		lednum = int(option.strip())
		if lednum < 1 or lednum > 3:
			print "Number out of range"
			return
		numbytes = struct.pack('>H', lednum) #H is for unsigned short
	except:
		print "Error converting number"
		return
	
	option = raw_input("Enter a new compare value for the LED duty cycle, 0-65535\n>>")
	try:
		ledval = int(option.strip())
		valbytes = struct.pack('>H', ledval)
	except:
		print "Error converting value"
		return
				
	bob = bytearray([0x01, 0x01, 0x04])
	bob += numbytes
	bob += valbytes
	print "Sending bytes to encode and send: " + repr(list(bob)) #for debugging
	cobs.encode_and_send(bob) #confirm baud rate and com port

def do_adc(cobs):
	#adc req
	#print "Setting LED1 to the result of ADC Read"
	sam = bytearray([0x01, 0x08, 0x00])
	cobs.encode_and_send(sam)
	#print "Reading raw bytes from serial response"
	retarray = cobs.block_and_return()
	#print "Cobs decode result array: "
	#print repr(retarray)
	try:
		adcval = struct.unpack('H', retarray)
		print "ADC val :"
		print int(adcval[0])
	except:
		print "Error converting adc value"

def do_motor(cobs):
	#motor speed
	
	option = raw_input("Enter a new compare value for the motor duty cycle, 0-65535\n>>")
	try:
		val = int(option.strip())
		valbytes = struct.pack('>H', val)
	except:
		print "Error converting value"
		return
						
	print "Sending command to the psoc5, commanding it to talk to the psoc4"
	cmd = bytearray([0x01, 0x01, 0x04])
	cmd += struct.pack('>H', 5)
	cmd += valbytes
	#print "debug: array to encode: " + repr(cmd)
	print "debug: sending array to encode and send routine"
	cobs.encode_and_send(cmd)
		
def do_servo(cobs):
	#
	print "Servo Control \n(see script to change min and max pulse widths. Currently defaulted to a TowerPro MG995 Servo)"
	option = raw_input("Enter a percentage >>")
	try:
		percent = float(option.strip())
		if percent < 0 or percent > 100:
			print "Error, Value not between 0 and 100."
			return
		pwmcompare = ((percent/100) * (maxpulse - minpulse)) + minpulse
		pwmcompare = servo_period - pwmcompare #left align the positive pulse
		#print "debug pwmcompare final value before conversion:" + repr(pwmcompare)
		comparebytes = struct.pack('>H', pwmcompare) #H is for unsigned short
	except:
		print "Error converting number"
		return
	
	numbytes = struct.pack('>H', 4) #H is for unsigned short
	
	bytestosend = bytearray([0x01, 0x01, 0x04])
	bytestosend += numbytes
	bytestosend += comparebytes
	print "Sending bytes to encode and send: " + repr(list(bytestosend)) #for debugging
	cobs.encode_and_send(bytestosend) #confirm baud rate and com port

def do_ultrasonic(cobs):	
	#timer req
	#print "Setting LED1 to the result of ADC Read"
	sam = bytearray([0x01, 0x09, 0x00])
	cobs.encode_and_send(sam)
	#print "Reading raw bytes from serial response"
	retarray = cobs.block_and_return()
	print "Cobs decode result array: "
	#print repr(retarray)
	try:
		timerval = struct.unpack('H', retarray)
		print "Timer val :"
		print int(timerval[0])
	except:
		print "Error converting timer value"
		
if __name__ == '__main__':
	main()

#END
