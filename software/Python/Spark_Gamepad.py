import pygame
import sys
import math
from Spark_Control import HID_Comm, NET_ZMQ_Comm, Spark_Drive


class Spark_Gamepad():
	spark = 0 #this gets turned into the object required to control the spark during initialization
	deadzone = 0.05
	servoCenter = 18525
	servoRange = 900
	holdPosition = True
	tilt = servoCenter
	pan = servoCenter 
	holdModes = True
	mode = False #false is one-stick mode, true is two-stick mode
	leftStickAxis = [0,1]
	rightStickAxis=[3,4]
	numAxis=6
	info = """
this is the gamepad control script for spark
this scripts defaults to one-stick drive mode in this mode:

        left stick:-------------drives robot around
        right stick:------------camera control
        b button:---------------changes camera mode
        left shoulder button:---changes camera speed
        y button:---------------switches control schemes
        
in two stick mode the spark will drive like a tank:

        left stick:-------------left set of wheels
        right stick:------------right set of wheels
        d-pad:------------------camera control
        b buton:----------------changes camera mode
        left shoulder button:---changes camera speed
        y button:---------------switches control schemes

at any time press start and back at the same time to exit the script"""
	def __init__(self, sparkIn):
		self.spark = sparkIn
		pygame.init()

	def create_joystick(self):
		joystick_count = pygame.joystick.get_count()
		if joystick_count < 1:
			print "no joystick found, exiting"
			pygame.quit()
			sys.exit()
		elif joystick_count == 1:
			joystick = pygame.joystick.Joystick(0)
		else:
			print "I have detected multiple gamepads: "
			for i in range(0,joystick_count):
				joystick = pygame.joystick.Joystick(i)
				print joystick.get_name(),
				print "------device number: ",
				print i
				joystick.quit()
			jsNumber = raw_input("what device would you like to use (device number)?: ")
			joystick = pygame.joystick.Joystick(int(jsNumber))
		joystick.init()
		self.numAxis = joystick.get_numaxes()
		if self.numAxis == 5:
			self.rightStickAxis=[4,3];
		return joystick
			
	def control_loop(self,joystick):
		print self.info
		self.clock = pygame.time.Clock()
		while True:
			if self.mode:
				while self.holdModes:
					self.two_stick(joystick)
					self.clock.tick(60)
			else:
				while self.holdModes:
					self.one_stick(joystick)
					self.clock.tick(60)
				self.holdModes = True
				
	def two_stick(self, joystick):
		panRate = 15
		tiltRate = 15
		driveRate = 1
		
		for event in pygame.event.get():
			if joystick.get_button(1) == 1 and event.type == pygame.JOYBUTTONDOWN:
				self.holdPosition = not self.holdPosition
				self.tilt = self.servoCenter
				self.pan = self.servoCenter
			elif joystick.get_button(3) == 1 and event.type == pygame.JOYBUTTONDOWN:
				self.mode = False
				self.holdModes = False
				
		axis = self.handle_deadzone(joystick)
				
		dpad = joystick.get_hat(0)
		lookrate = joystick.get_button(4)
		drivescale = joystick.get_button(5)

		self.handle_LEDS(joystick,self.numAxis)
		
		if drivescale == 1:
			driveRate = 0.2
				
		if lookrate == 1:
			tiltRate = 2
			panRate = 2
				
		self.handle_camera(dpad[1],dpad[0],tiltRate,panRate)
		self.handle_motors(axis[1], axis[3], driveRate)
				
		if joystick.get_button(6) == 1 and joystick.get_button(7) == 1:
			pygame.quit()
			sys.exit()

	def one_stick(self, joystick):
		panRate = 20
		tiltRate = 20
		driveRate = 1
		for event in pygame.event.get():
			if joystick.get_button(1) == 1 and event.type == pygame.JOYBUTTONDOWN:
				self.holdPosition = not self.holdPosition
				self.tilt = self.servoCenter
				self.pan = self.servoCenter
			elif joystick.get_button(3) == 1 and event.type == pygame.JOYBUTTONDOWN:
				self.mode = True
				self.holdModes = False
		axis = self.handle_deadzone(joystick)                
				
		leftval = axis[1]-axis[0]
		rightval = axis[1]+axis[0]
		lookrate = joystick.get_button(4)
		drivescale = joystick.get_button(5)

		self.handle_LEDS(joystick,self.numAxis)
		
		if lookrate == 1:
			panRate = 2
			tiltRate = 2
				
		if drivescale == 1:
			driveRate = 0.2
		
		self.handle_motors(leftval, rightval,driveRate)
		self.handle_camera(axis[3],axis[2],tiltRate,panRate)
		
		if joystick.get_button(6) == 1 and joystick.get_button(7) == 1:
			pygame.quit()
			sys.exit()

	def handle_deadzone(self,joystick):
		axis = [0,0,0,0]
		axis[0] = joystick.get_axis(self.leftStickAxis[0])
		if abs(axis[0]) < self.deadzone:
			axis[0] = 0
				
		axis[1] = joystick.get_axis(self.leftStickAxis[1])
		if abs(axis[1]) < self.deadzone:
			axis[1] = 0
				
		axis[2] = joystick.get_axis(self.rightStickAxis[0])
		if abs(axis[2]) < self.deadzone:
			axis[2] = 0
				
		axis[3] = joystick.get_axis(self.rightStickAxis[1])
		if abs(axis[3]) < self.deadzone:
			axis[3] = 0
		return axis

	def handle_camera(self, cameraTilt, cameraPan, tiltRate, panRate):
		if self.holdPosition == False:
			self.spark.set_servo_width(1,self.servoCenter+(self.servoRange*cameraTilt))
			self.spark.set_servo_width(2,self.servoCenter+(self.servoRange*cameraPan))
				
		else:
			self.tilt = self.tilt+(cameraTilt*tiltRate)
			self.pan = self.pan+(cameraPan*panRate)
			
			if self.tilt >= (self.servoCenter-self.servoRange) and self.tilt <= (self.servoCenter+self.servoRange):
				self.spark.set_servo_width(1,self.tilt)
					
			elif self.tilt < (self.servoCenter-self.servoRange):
				self.tilt = (self.servoCenter-self.servoRange)
					
			elif self.tilt > (self.servoCenter+self.servoRange):
				self.tilt = (self.servoCenter+self.servoRange)
					
			if self.pan >= (self.servoCenter-self.servoRange) and self.pan <= (self.servoCenter+self.servoRange):
				self.spark.set_servo_width(2,self.pan)
					
			elif self.pan < (self.servoCenter-self.servoRange):
				self.pan = (self.servoCenter-self.servoRange)
					
			elif self.pan > (self.servoCenter+self.servoRange):
				self.pan = (self.servoCenter+self.servoRange)

	def handle_motors(self, leftval, rightval, driveRate):
		driveMult = int(65535*driveRate)
		if leftval < 0:
			self.spark.set_motor_direction(5,0)
				
		else:
			self.spark.set_motor_direction(5,1)
				
		if rightval < 0:
			self.spark.set_motor_direction(6,0)
				
		else:
			self.spark.set_motor_direction(6,1)
				
		leftpwm = abs(leftval)*driveMult
		rightpwm = abs(rightval)*driveMult
		if leftpwm > 65535:
			leftpwm = 65535
				
		if rightpwm > 65535:
			rightpwm = 65535
				
		self.spark.set_motor_speed(5, leftpwm)
		self.spark.set_motor_speed(6, rightpwm)

	def handle_LEDS(self, joystick,numAxis):
		LED1PWM=0
		LED2PWM=0
		if numAxis == 5:
			triggersVal = joystick.get_axis(2)
			if triggersVal > 0:
				LED1PWM = abs(triggersVal)*65535
			else:
				LED2PWM = abs(triggersVal)*65535
				
		else:
			LED1 = joystick.get_axis(2)
			LED2 = joystick.get_axis(5)
			LED1PWM = (1+LED1)*32768
			LED2PWM = (1+LED2)*32768
			
		self.spark.set_led_brightness(1,LED1PWM)
		self.spark.set_led_brightness(2,LED2PWM)

if __name__ == '__main__':
	addr = ""
	try:
			if not sys.argv[1] == "-q":
					addr = raw_input("Address of target (its.ip.add.ress:port) or hit enter for local USB:")
	except:
			addr = raw_input("Address of target (its.ip.add.ress:port) or hit enter for local USB:")
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
				comm.open("tcp://"+addr)
			except:
					print "Error connecting to Spark"
					sys.exit()
	
	sparkout = Spark_Drive(comm)
	gamepad = Spark_Gamepad(sparkout)
	js = gamepad.create_joystick()
	gamepad.control_loop(js)
