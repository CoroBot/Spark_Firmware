import pygame
import sys
import math
from Spark_Control import HID_Comm, NET_ZMQ_Comm, Spark_Drive

pygame.init()


pygame.joystick.init()


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
	
        while True:
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
            if leftpwm < 300:
                leftpwm = 0
            if rightpwm < 300:
                rightpwm = 0
            spark.set_motor_speed(6, rightpwm)
            spark.set_motor_speed(5, leftpwm)
            
    

if __name__ == '__main__':
    main()
