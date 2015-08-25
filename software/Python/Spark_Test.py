#!/usr/bin/env python

from cobs_serial import cobs_serial
import sys
from Spark_Control import HID_Comm, NET_ZMQ_Comm, Spark_Drive


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
  3. Set motor speeds
  4. Set servo duty cycle
  5. Request ultrasonic distance
  6. Test HID Loopback
  X. Exit

  Please Enter a number from above menu >>"""

def main():
	print menu_header
	
	addr = raw_input("Address of target (tcp://its.ip.add.ress:port) or hit enter for local USB:")
	if addr == "":
		comm = HID_Comm()
		try:
			comm.open()
		except IOError, ex:
			print "Spark not found:",ex
			sys.exit()
	else:
		comm = NET_ZMQ_Comm()
		try:
			comm.open(addr)
		except:
			print "Error connecting to Spark"
			sys.exit()
	
	spark = Spark_Drive(comm)
	
	#Loop until user quits	
	while True:
		option = raw_input(menu)
		sel = option.strip()
		if sel == 'X':
			break
		elif sel == '1': #CONTROL LEDS
			do_led(spark)
		elif sel == '2': #READ ADC VALUE
			do_adc(spark)
		elif sel == '3': #TEST MOTORS
			do_motor(spark)
		elif sel == '4': #CONTROL SERVOS
			do_servo(spark)
		elif sel == '5': #READ ULTRASONIC SENSOR
			do_ultrasonic(spark)
		elif sel == '6': #TEST LOOPBACK
			do_echo(spark)

				
def do_led(comm):
	print "LED Control"
	option = raw_input("Enter an LED to control, 1-3\n>>")
	try:
		lednum = int(option.strip())
		if lednum < 1 or lednum > 3:
			print "Number out of range"
			return
	except:
		print "Error converting number"
		return
	
	option = raw_input("Enter a new compare value for the LED duty cycle, 0-65535\n>>")
	try:
		ledval = int(option.strip())
	except:
		print "Error converting value"
		return
	comm.set_led_brightness(lednum, ledval)

	
def do_adc(comm):
	print "ADC Channel 0:", comm.get_adc(0)

	
def do_motor(comm):
	#motor speed
	raw_motor_num = raw_input("Which motor? (Special values: 0 = Both, 6 = Left, 5 = Right)\n>>")
	try:
		motornum = int(raw_motor_num.strip())
	except:
		print "Error converting motornum"
		return
	
	try:
		raw_option = raw_input("Enter 0 for direction, 1 for speed\n>>")
		option = int(raw_option.strip())
	except:
		print "Error converting value"
		return	
	
	if option == 1:
		#do_speed(comm)
		try:
			raw_val = raw_input("Enter a new compare value for the motor duty cycle, 0-65535\n>>")
			val = int(raw_val.strip())
		except:
			print "Error converting speed value"
			return
		comm.set_motor_speed(motornum, val)		
	elif option == 0:
		#do_direction(comm)
		try:
			raw_val = raw_input("Enter 0 for forward, 1 for reverse\n>>")
			val = int(raw_val.strip())
		except:
			print "Error converting direction value"
			return
		comm.set_motor_direction(motornum, val)		

		
def do_servo(comm):
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
	except:
		print "Error converting number"
		return
	comm.set_servo_width(1, pwmcompare)
	
	
def do_ultrasonic(comm):	
	print "Ultrasonic 1: ", comm.get_ultrasonic(1)

	
def do_echo(comm):
	hid = comm.comm
	hid.send([0,1,2,3,4,5,6,7])
	print repr(hid.receive());

		
if __name__ == '__main__':
	main()

	
#END