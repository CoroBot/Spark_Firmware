import pygame
import sys
import math
from Spark_Control import HID_Comm, NET_ZMQ_Comm, Spark_Drive

pygame.init()

deadzone = 0.05
servoCenter = 18700
servoRange = 1000
holdPosition = True
tilt = servoCenter
pan = servoCenter
holdModes = True
mode = False #false is one-stick mode, true is two-stick mode

pygame.joystick.init()

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

def main():
        global holdModes
        global mode
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
	joystick_count = pygame.joystick.get_count()
        joystick = pygame.joystick.Joystick(0)
        joystick.init()
        print info
        while True:
                if mode:
                        while holdModes:
                                two_stick(spark, joystick)
                else:
                        while holdModes:
                                one_stick(spark, joystick)
                holdModes = True
            
def two_stick(spark, joystick):
        global deadzone
        global servoCenter
        global holdPosition
        global mode
        global holdModes
        panRate = 15
        tiltRate = 15
        driveRate = 1
        for event in pygame.event.get():
                if joystick.get_button(1) == 1 and event.type == pygame.JOYBUTTONDOWN:
                        holdPosition = not holdPosition
                        tilt = servoCenter
                        pan = servoCenter
                elif joystick.get_button(3) == 1 and event.type == pygame.JOYBUTTONDOWN:
                        mode = False
                        holdModes = False
                
        leftJoystick = joystick.get_axis(1)
        if abs(leftJoystick) < deadzone:
                leftJoystick = 0
                
        rightJoystick = joystick.get_axis(4)
        if abs(rightJoystick) < deadzone:
                rightJoystick = 0
                
        dpad = joystick.get_hat(0)
        lookrate = joystick.get_button(4)
        drivescale = joystick.get_button(5)
        
        if drivescale == 1:
                driveRate = 0.2
                
        if lookrate == 1:
                tiltRate = 2
                panRate = 2
                
        handle_camera(spark, dpad[1],dpad[0],tiltRate,panRate)
        handle_motors(spark, leftJoystick, rightJoystick, driveRate)
                
        if joystick.get_button(6) == 1 and joystick.get_button(7) == 1:
                pygame.quit()
                sys.exit()

def one_stick(spark, joystick):
        global deadzone
        global servoCenter
        global servoRange
        global holdPosition
        global mode
        global holdModes
        panRate = 20
        tiltRate = 20
        driveRate = 1
        for event in pygame.event.get():
                if joystick.get_button(1) == 1 and event.type == pygame.JOYBUTTONDOWN:
                        holdPosition = not holdPosition
                        tilt = servoCenter
                        pan = servoCenter
                elif joystick.get_button(3) == 1 and event.type == pygame.JOYBUTTONDOWN:
                        mode = True
                        holdModes = False
                        
        LRjoystick = joystick.get_axis(0)
        if abs(LRjoystick) < deadzone:
                LRjoystick = 0
                
        FBjoystick = joystick.get_axis(1)
        if abs(FBjoystick) < deadzone:
                FBjoystick = 0
                
        cameraPan = joystick.get_axis(3)
        if abs(cameraPan) < deadzone:
                cameraPan = 0
                
        cameraTilt = joystick.get_axis(4)
        if abs(cameraTilt) < deadzone:
                cameraTilt = 0
                
        leftval = FBjoystick-LRjoystick
        rightval = FBjoystick+LRjoystick
        lookrate = joystick.get_button(4)
        drivescale = joystick.get_button(5)
        
        if lookrate == 1:
                panRate = 2
                tiltRate = 2
                
        if drivescale == 1:
                driveRate = 0.2
        
        handle_motors(spark, leftval, rightval,driveRate)
        handle_camera(spark,cameraTilt,cameraPan,tiltRate,panRate)
                        
        if joystick.get_button(6) == 1 and joystick.get_button(7) == 1:
                pygame.quit()
                sys.exit()

def handle_camera(spark, cameraTilt, cameraPan, tiltRate, panRate):
        global servoCenter
        global servoRange
        global holdPosition
        global pan
        global tilt
        if holdPosition == False:
                spark.set_servo_width(1,servoCenter+(servoRange*cameraTilt))
                spark.set_servo_width(2,servoCenter+(servoRange*cameraPan))
                
        else:
                tilt = tilt+(cameraTilt*tiltRate)
                pan = pan+(cameraPan*panRate)
                if tilt >= (servoCenter-servoRange) and tilt <= (servoCenter+servoRange):
                        spark.set_servo_width(1,tilt)
                        
                elif tilt < (servoCenter-servoRange):
                        tilt = (servoCenter-servoRange)
                        
                elif tilt > (servoCenter+servoRange):
                        tilt = (servoCenter+servoRange)
                        
                if pan >= (servoCenter-servoRange) and pan <= (servoCenter+servoRange):
                        spark.set_servo_width(2,pan)
                        
                elif pan < (servoCenter-servoRange):
                        pan = (servoCenter-servoRange)
                        
                elif pan > (servoCenter+servoRange):
                        pan = (servoCenter+servoRange)

def handle_motors(spark, leftval, rightval, driveRate):
        driveMult = int(65535*driveRate)
        if leftval < 0:
                spark.set_motor_direction(5,0)
                
        else:
                spark.set_motor_direction(5,1)
                
        if rightval < 0:
                spark.set_motor_direction(6,0)
                
        else:
                spark.set_motor_direction(6,1)
                
        leftpwm = abs(leftval)*driveMult
        rightpwm = abs(rightval)*driveMult
        if leftpwm > 65535:
                leftpwm = 65535
                
        if rightpwm > 65535:
                rightpwm = 65535
                
        spark.set_motor_speed(5, leftpwm)
        spark.set_motor_speed(6, rightpwm)

if __name__ == '__main__':
    main()
