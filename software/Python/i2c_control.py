#!/usr/bin/env python

# Script for i2c control demo. 

from Spark_Control import HID_Comm, NET_ZMQ_Comm, Spark_Drive
import struct
import hid
import sys

#USB Constants
coroware_VID = 0x2bd6 #Issued by USB-IF
spark_PID = 0xff02 #Development hardware - will change when device is released

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
  X. Exit

  Please Enter a number from above menu >>"""


def main():

	comm = HID_Comm()
	try:
			comm.open()
	except IOError, ex:
			print "Spark not found:",ex
			#sys.exit()	
			
	spark = Spark_Drive(comm)
	
	print menu_header
	
	# Open the serial port
	# ************************** USER ENTERED PORT ***************************
	#port = raw_input("Enter your serial port (EX: COM14)\n>>")
	#cobs = cobs_serial(port, 115200, 1)
	
	# ************************** DEFAULT DEBUG PORT ***************************
	#print "Defaulting port to COM14. Change script if neeeded"
	#cobs = cobs_serial('COM14', 115200, 1) #apparently the port is offset by 1 (so COM14 is 13)
	
	# *************************** END PORT CONFIG ****************************

	i2c_buffer = bytearray([0x00])
		
	#Loop until user quits	
	while True:
		option = raw_input(menu)
		sel = option.strip()
		if sel == 'X':
			break
		elif sel == '1': #init
			do_init(spark, i2c_buffer)
		elif sel == '2': #setFreq
			add_setFreq(spark, i2c_buffer)
		elif sel == '3': #setPullup
			add_setPullup(spark)
		elif sel == '4': #start
			add_start(spark)
		elif sel == '5': #restart
			add_restart(spark)
		elif sel == '6': #sendBytes
			add_send(spark)
		elif sel == '7': #recieveBytes
			add_recieve(spark)
		elif sel == '8': #stop
			add_stop(spark)
		elif sel == '9': #execute
			do_execute(spark)				

def do_init(comm, i2c_buffer):
        comm.I2C_init(i2c_buffer)
        print "Updated buffer contents: " + repr(list(i2c_buffer))
        
def add_setFreq(comm, i2c_buffer):
        print "Sets the frequency of the I2C component"
        option = raw_input("Enter a new frequency value for the I2C master in kHz, 1-65535\n>>")
	try:
		freq = int(option.strip())
		if freq < 1 or freq > 65535:
			print "Number out of range"
			return
	except:
		print "Error converting number"
		return

        comm.I2C_SetFrequency(i2c_buffer, freq)
	print "Updated buffer contents: " + repr(list(i2c_buffer))

def do_execute():
        print "Final buffer contents: " + repr(list(i2c_buffer))


			
if __name__ == '__main__':
	main()

#END
