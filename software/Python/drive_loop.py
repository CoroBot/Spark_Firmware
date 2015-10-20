#!/usr/bin/env python

import sys
from Spark_Control import HID_Comm, NET_ZMQ_Comm, Spark_Drive
import time

'''
		spark.set_motor_speed(6, lmotor)
		spark.set_motor_speed(5, rmotor)
		spark.set_motor_direction(6, dir_l)
		spark.set_motor_direction(5, dir_r)
'''

def main():
	addr = raw_input("Address of target (tcp://its.ip.add.ress:port) or hit enter for local USB:")
	if addr == "-":
		addr = "tcp://raspberrypi.local:4567"
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
	drive_loop(spark)
	
def drive_loop(spark):
	while(1):
		print("Driving forward")
		spark.set_motor_speed(6, .5)
		spark.set_motor_speed(5, .5)
		time.sleep(3)
	
		#turn around #or for now, stop.
		print("stopping for 2")
		spark.set_motor_speed(6, 0)
		spark.set_motor_speed(5, 0)	
		time.sleep(2)
	
if __name__ == '__main__':
	main()

	
#END
