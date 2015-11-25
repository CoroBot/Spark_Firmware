import pygame
import sys
import math
from Spark_Control import HID_Comm, NET_ZMQ_Comm, Spark_Drive

pygame.init()

deadzone = 300
servoCenter = 18700
servoRange = 1000

pygame.joystick.init()

menu = """
drive style:
    1. 1 stick drive
    2. 2 stick tank drive

    please enter a selection:"""

def main():	
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
        sel = raw_input(menu)
        option = sel.strip()
        if option == '2' or option == '':
                while True:
                        two_stick(spark, joystick)
        elif option == '1':
                while True:
                        one_stick(spark, joystick)
            
def two_stick(spark, joystick):
        global deadzone
        global servoCenter
        for event in pygame.event.get():
                if event.type == pygame.QUIT:
                        done=True
                
        leftstick = joystick.get_axis(1)
        rightstick = joystick.get_axis(4)
        leftpwm = abs(leftstick)*65535
        rightpwm = abs(rightstick)*65535
        if leftstick < 0:
                spark.set_motor_direction(5,0)
        else:
                spark.set_motor_direction(5,1)
        if rightstick < 0:
                spark.set_motor_direction(6,0)
        else:
                spark.set_motor_direction(6,1)
        if leftpwm < deadzone:
                leftpwm = 0
        if rightpwm < deadzone:
                rightpwm = 0
        if leftpwm > 65535:
                leftpwm = 65535
        if rightpwm > 65535:
                rightpwm = 65535
        spark.set_motor_speed(6, rightpwm)
        spark.set_motor_speed(5, leftpwm)
        if joystick.get_button(6) == 1 and joystick.get_button(7) == 1:
                pygame.quit()
                sys.exit()

def one_stick(spark, joystick):
        global deadzone
        global servoCenter
        global servoRange
        for event in pygame.event.get():
                if event.type == pygame.QUIT:
                        done=True
        LRjoystick = joystick.get_axis(0)
        FBjoystick = joystick.get_axis(1)
        cameraPan = joystick.get_axis(3)
        cameraTilt = joystick.get_axis(4)
        leftval = FBjoystick-LRjoystick
        rightval = FBjoystick+LRjoystick
        if leftval < 0:
                spark.set_motor_direction(5,0)
        else:
                spark.set_motor_direction(5,1)
        if rightval < 0:
                spark.set_motor_direction(6,0)
        else:
                spark.set_motor_direction(6,1)
        leftpwm = abs(leftval)*65535
        rightpwm = abs(rightval)*65535
        if leftpwm < deadzone:
                leftpwm = 0
        if rightpwm < deadzone:
                rightpwm = 0
        if leftpwm > 65535:
                leftpwm = 65535
        if rightpwm > 65535:
                rightpwm = 65535
        spark.set_motor_speed(5, leftpwm)
        spark.set_motor_speed(6, rightpwm)
        spark.set_servo_width(1,servoCenter+(servoRange*cameraTilt))
        spark.set_servo_width(2,servoCenter+(servoRange*cameraPan))
        if joystick.get_button(6) == 1 and joystick.get_button(7) == 1:
                pygame.quit()
                sys.exit()

if __name__ == '__main__':
    main()
