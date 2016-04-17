#!/usr/bin/env python

# Script for i2c control demo. 

from cobs_serial import cobs_serial
import struct
import hid

#USB Constants
coroware_VID = 0x2bd6 #Issued by USB-IF
spark_PID = 0xff02 #Development hardware - will change when device is released

#Servo Constants, for TowerPro MG995
servo_period = 2000 #period of PWM component (ie servo duty cycle) = 20ms
maxpulse = 214 # 10.7% of period
minpulse = 54 # 2.7% of period

menu_header = """
*******************************
**** Spark Control Test v2 ****
*******************************
"""

menu = """
Option Menu:
  1. init
  2. setFreq
  3. SetPullup
  4. Start
  5. restart
  6. sendBytes
  7. recieveBytes
  8. stop
  9. Execute Buffer
  x. Exit

  Please Enter a number from above menu >>"""


def main():
	print menu_header
	
	# Open the serial port
	# ************************** USER ENTERED PORT ***************************
	#port = raw_input("Enter your serial port (EX: COM14)\n>>")
	#cobs = cobs_serial(port, 115200, 1)
	
	# ************************** DEFAULT DEBUG PORT ***************************
	#print "Defaulting port to COM14. Change script if neeeded"
	#cobs = cobs_serial('COM14', 115200, 1) #apparently the port is offset by 1 (so COM14 is 13)
	
	# *************************** END PORT CONFIG ****************************
	
	#User Menu
		
	#Loop until user quits	
	while True:
		option = raw_input(menu)
		sel = option.strip()
		if sel == 'x':
			break
		elif sel == '1': #init
			add_init()
		elif sel == '2': #setFreq
			add_setFreq()
		elif sel == '3': #setPullup
			add_setPullup()
		elif sel == '4': #start
			add_start()
		elif sel == '5': #restart
			add_restart()
		elif sel == '6': #sendBytes
			add_send()
		elif sel == '7': #recieveBytes
			add_recieve()
		elif sel == '8': #stop
			add_stop()
		elif sel == '9': #execute
			do_execute()				
				
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
