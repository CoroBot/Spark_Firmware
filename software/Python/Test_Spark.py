#!/usr/bin/env python

# Script for LED control demo. 

from cobs_serial import cobs_serial
import struct
import platform
import hid

#USB Constants
coroware_VID = 0x2bd6 #Issued by USB-IF
spark_PID = 0xff02 #Development hardware - will change when device is released

#Servo Constants, for TowerPro MG995
servo_period = 2000 #period of PWM component (ie servo duty cycle) = 20ms
maxpulse = 214 # 10.7% of period
minpulse = 54 # 2.7% of period

menu_header = """
****************************
**** Spark Control Test ****
****************************
"""

menu = """
Option Menu:
  1. Control LEDs
  2. Request the ADC value
  3. Set the first/front motor speed
  4. Set servo duty cycle
  5. Request ultrasonic distance
  6. Test HID Loopback
  X. Exit

  Please Enter a number from above menu >>"""

class Spark(object):
	def __init__(self):
		self.hid = hid.device()
		self.prefix = []
		if platform.system() == 'Windows':
			self.prefix=[0x80]
	def open(self):
		try:
			return hid.open(coroware_VID, spark_PID)
		except:
			return None

  
  
  
  
  
  
 def main():
	print menu_header
	
	comm = Spark()
	
	#User Menu
		
	#Loop until user quits	
	while True:
		option = raw_input(menu)
		sel = option.strip()
		if sel == 'X':
			break
		elif sel == '1': #CONTROL LEDS
			do_led(cobs)
		elif sel == '2': #READ ADC VALUE
			do_adc(cobs)
		elif sel == '3': #TEST MOTORS
			do_motor(cobs)
		elif sel == '4': #CONTROL SERVOS
			do_servo(cobs)
		elif sel == '5': #READ ULTRASONIC SENSOR
			do_ultrasonic(cobs)

				
				
def do_led(cobs):
	print "LED Control"
	option = raw_input("Enter an LED to control, 1-3\n>>")
	try:
		lednum = int(option.strip())
		if lednum < 1 or lednum > 3:
			print "Number out of range"
			continue
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
			continue
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