#!/usr/bin/env python

# Script for LED control demo. 

from cobs_serial import cobs_serial
import sys
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
  3. Set motor speeds
  4. Set servo duty cycle
  5. Request ultrasonic distance
  6. Test HID Loopback
  X. Exit

  Please Enter a number from above menu >>"""

def ordlist(x):
	return [ord(l) if type(l) == str else l for l in x]
  
  
class HID_Comm(object):
	def __init__(self):
		self.hiddev = hid.device()
		self.prefix = []
		if platform.system() == 'Windows':
			self.prefix=[0x80]
		self.isopen=False

	def open(self, vid=coroware_VID, pid=spark_PID):
		if self.isopen:
			raise ValueError, "Already Open"
		self.hiddev.open(vid,pid)
		self.isopen = True

	def close(self):
		if not self.isopen:
			raise ValueError, "Not Open"
		self.hiddev.close()
		self.isopen = False

	def send(self, data):
		if not self.isopen:
			raise IOError, "Not Open"
		prefix = self.prefix[:]
		prefix.extend(ordlist(data))
		self.hiddev.write(prefix)

	def receive(self, numbytes=64, blocking=True):
		if not self.isopen:
			raise IOError, "Not Open"
		if not blocking:
			self.hiddev.set_nonblocking(1)
		data = self.hiddev.read(numbytes)
		if not blocking:
			self.hiddev.set_nonblocking(0)
		return data

	def send_frame(self, unit, subunit, command, data):
		if not self.isopen:
			raise IOError, "Not Open"
		out = ordlist(struct.pack("BBB", unit, subunit, command))
		out.extend(ordlist(data))
		if len(out)>64:
			raise ValueError
		self.send(out)
		
	def set_value(self, unit, subunit, setting, value):
		command_set_value = 1 
		additional = struct.pack(">HH", setting, value)
		self.send_frame(unit, subunit, command_set_value, additional)
		

	def receive_frame(self, blocking=True):
		if not self.isopen:
			raise IOError, "Not Open"
		data = self.receive(64, blocking)
		if len(data) < 3:
			raise IOError, "Invalid Frame: Too short"
		unit = data[0] - 0x80
		if unit < 0:
			raise IOError, "Invalid Frame: Invalid Unit #"
		subunit = data[1]
		additional = data[2:]
		return (unit, subunit, additional)
		
	def get_value(self, unit, subunit, setting):
		command_get_value = 0 
		additional = struct.pack(">H", setting)
		self.send_frame(unit, subunit, command_get_value, additional)
		runit, rsubunit, radditional = self.receive_frame()
		rsetting, rvalue = struct.unpack(">HH", bytearray(radditional[:4]))
		if unit <> runit or subunit <> rsubunit or setting <> rsetting:		
			raise IOError, "Invalid Frame: data mismatch"			
		return rvalue

		
class Spark_Drive(object):
	def __init__(self, comm):
		self.comm = comm
		self.unit_loopback = 0
		self.unit_motor = 1
		self.unit_led = 2
		self.unit_servo = 3
		self.unit_adc = 4
		self.unit_ultrasonic = 5
		
		self.setting_pwm = 1
		self.setting_direction = 2
		self.setting_ADC = 3 
		self.setting_USonic = 4 

		self.value_stopped = 0
		self.value_forward = 1
		self.value_reverse = 2
		
		self.command_set = 1
		self.command_read = 0
		
	def set_motor_speed(self, motornum, speed):
		self.comm.set_value(self.unit_motor, motornum, self.setting_pwm, speed) #unit, subu, sett, value
	
	def set_motor_direction(self, motornum, direction):
		self.comm.set_value(self.unit_motor, motornum, self.setting_direction, direction)

	def set_led_brightness(self, lednum, brightness):
		self.comm.set_value(self.unit_led, lednum, self.setting_pwm, brightness)
		
	def set_servo_width(self, servonum, width):
		self.comm.set_value(self.unit_servo, servonum, self.setting_pwm, width)
	
	def get_adc(self, adcnum):
		return self.comm.get_value(self.unit_adc, adcnum, self.setting_ADC)
	
	def get_ultrasonic(self, ultrasonic_num):
		return self.comm.get_value(self.unit_ultrasonic, ultrasonic_num, self.setting_USonic)



def main():
	hidcomm = HID_Comm()
	try:
		hidcomm.open()
	except IOError, ex:
		print "Spark not found:",ex
		sys.exit()

	spark = Spark_Drive(hidcomm)
	
	print menu_header
	
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
	raw_motor_num = raw_input("Which motor? 0 = Both, 6 = Left, 5 = Right \n>>")
	try:
		motornum = int(raw_motor_num.strip())
	except:
		print "Error converting motornum"
		return
		
	option = raw_input("Enter a new compare value for the motor duty cycle, 0-65535\n>>")
	try:
		val = int(option.strip())
	except:
		print "Error converting value"
		return
	comm.set_motor_speed(motornum, val)
	
		
def do_servo(comm):
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