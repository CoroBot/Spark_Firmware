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

	i2c_buffer = bytearray([])
		
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
			add_setPullup(spark, i2c_buffer)
		elif sel == '4': #start
			add_start(spark, i2c_buffer)
		elif sel == '5': #restart
			add_restart(spark, i2c_buffer)
		elif sel == '6': #sendBytes
			add_send(spark, i2c_buffer)
		elif sel == '7': #recieveBytes
			add_recieve(spark, i2c_buffer)
		elif sel == '8': #stop
			add_stop(spark, i2c_buffer)
		elif sel == '9': #execute
			do_execute(spark, i2c_buffer)				

def do_init(comm, i2c_buffer):
        comm.I2C_init(i2c_buffer)
        print "Updated buffer contents: " + repr(list(i2c_buffer))
def add_start(comm, i2c_buffer):
        comm.I2C_addStart(i2c_buffer)
        print "Updated buffer contents: " + repr(list(i2c_buffer))
def add_stop(comm, i2c_buffer):
        comm.I2C_addStop(i2c_buffer)
        print "Updated buffer contents: " + repr(list(i2c_buffer))
def add_restart(comm, i2c_buffer):
        comm.I2C_addRestart(i2c_buffer)
        print "Updated buffer contents: " + repr(list(i2c_buffer))	

def add_send(comm, i2c_buffer):
	bytes = bytearray()
	
	while True:
		option = raw_input("Enter a single byte in decimal, 0-255. Enter X when done.\n>>")
		if option == 'X':
			break
		try:
			bytes+= struct.pack('B', int(option))
			#print "current byte string: " + repr(list(bytes))
		except:
			print "Error converting input to bytes"
	
	comm.I2C_addSend(i2c_buffer, bytes)
	print "Updated buffer contents: " + repr(list(i2c_buffer))	

def add_recieve(comm, i2c_buffer):
	option = raw_input("Enter the number of bytes to request, 1-255\n>>")
	try:
		num = int(option.strip())
		if num < 1 or num > 255:
			print "Number out of range"
			return
	except:
		print "Error converting number"
		return

	comm.I2C_addRecieve(i2c_buffer, num)
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

def add_setPullup(comm, i2c_buffer):
	print "Sets the internal pullup. 1 for on, otherwise off."
	option = raw_input("Enter a new state for the internal pullup resistor, 1-0\n>>")
	try:
		state = int(option.strip())
		if state < 0 or state > 1:
			print "Number out of range"
			return
	except:
		print "Error converting number"
		return
	comm.I2C_SetPullup(i2c_buffer, state)
	print "Updated buffer contents: " +repr(list(i2c_buffer))

def do_execute(comm, i2c_buffer): 
	#take user input on slave address
	option = raw_input("Enter the slave address byte for all commands, 1-255\n>>")
	try:
		num = int(option.strip())
		if num < 0 or num > 127:
			print "Number out of range"
			return
		slave_address = struct.pack('B', num)
		#from i2c data sheet: Right-justified 7-bit slave address (valid range 0 to 127).
		#does that match what the above line does?
	except:
		print "Error converting number"
		return	
    print "DEBUG: buffer contents: " + repr(list(i2c_buffer))
	
	retbuffer = bytearray()
	#comm.I2C_execute(i2c_buffer, retbuffer, 64, slave_address)
			
if __name__ == '__main__':
	main()

#END
