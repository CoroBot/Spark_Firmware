#!/usr/bin/env python

from cobs_serial import cobs_serial
import sys
import struct
import platform
import hid
import zmq


#USB Constants
coroware_VID = 0x2bd6 #Issued by USB-IF
spark_PID = 0xff02 #Development hardware - will change when device is released

#Servo Constants, for TowerPro MG995
servo_period = 2000 #period of PWM component (ie servo duty cycle) = 20ms
maxpulse = 214 # 10.7% of period
minpulse = 54 # 2.7% of period

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


class NET_ZMQ_Comm(object):
	def __init__(self):
		self.context = zmq.Context()
		self.prefix = []
		self.isopen=False

	def open(self, addr):
		if self.isopen:
			raise ValueError, "Already Open"
		self.socket = self.context.socket(zmq.XREQ)
		self.socket.connect(addr)
		self.isopen = True

	def close(self):
		if not self.isopen:
			raise ValueError, "Not Open"
		self.socket.close()
		self.isopen = False

	def send(self, data, recv=False):
		if not self.isopen:
			raise IOError, "Not Open"
		recvflag = "0"
		if recv == True:
			recvflag = "1"
		base = self.prefix[:]
		base.extend(ordlist(data))
		out = bytearray(base)
		self.socket.send_multipart([out, recvflag])

	def receive(self):
		if not self.isopen:
			raise IOError, "Not Open"
		data = self.socket.recv_multipart()
		return data[0]

	def send_frame(self, unit, subunit, command, data, recv = False):
		if not self.isopen:
			raise IOError, "Not Open"
		out = ordlist(struct.pack("BBB", unit, subunit, command))
		out.extend(ordlist(data))
		if len(out)>64:
			raise ValueError
		self.send(out, recv = recv)
		
	def set_value(self, unit, subunit, setting, value):
		command_set_value = 1 
		additional = struct.pack(">HH", setting, value)
		self.send_frame(unit, subunit, command_set_value, additional)
		
	def receive_frame(self):
		if not self.isopen:
			raise IOError, "Not Open"
		data = self.receive()
		if len(data) < 3:
			raise IOError, "Invalid Frame: Too short"
		unit = ord(data[0]) - 0x80
		if unit < 0:
			raise IOError, "Invalid Frame: Invalid Unit #"
		subunit = ord(data[1])
		additional = ordlist(data[2:])
		return (unit, subunit, additional)
		
	def get_value(self, unit, subunit, setting):
		command_get_value = 0 
		additional = struct.pack(">H", setting)
		self.send_frame(unit, subunit, command_get_value, additional, recv = True)
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
