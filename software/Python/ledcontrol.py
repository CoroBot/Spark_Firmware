#ledcontrol.py

# Script for LED control demo. 

from cobs_serial import cobs_serial
import struct

if __name__ == '__main__':
	print "\n**************************"
	print "**** Spark Control Test ****"
	print "**************************\n"
	
	#Servo Constants, for TowerPro MG995
	servo_period = 2000 #period of PWM component (ie servo duty cycle) = 20ms
	maxpulse = 214 # 10.7% of period
	minpulse = 54 # 2.7% of period
	
	# ************************** USER ENTERED PORT ***************************
	port = raw_input("Enter your serial port (EX: COM14)\n>>")
	cobs = cobs_serial(port, 115200, 1)
	
	# ************************** DEFAULT DEBUG PORT ***************************
	#print "Defaulting port to COM14. Change script if neeeded"
	#cobs = cobs_serial('COM14', 115200, 1) #apparently the port is offset by 1 (so COM14 is 13)
	
	# *************************** END PORT CONFIG ****************************
	
	
	menu = "\nOption Menu:\n"
	menu += "1. Control LEDs\n"
	menu += "2. Request the ADC value\n"
	menu += "3. Set the first/front motor speed\n"
	menu += "4. Set servo duty cycle\n"
	#menu += "5. Request ultrasonic distance\n"
	menu += "5. Exit\n"
	menu += "\nPlease Enter a number from above menu >>"
		
	while True:
		option = raw_input(menu)
		sel = option.strip()
		if sel == '5':
			break
		elif sel == '1': # LED CONTROL
			print "LED Control"
			option = raw_input("Enter an LED to control, 1-3\n>>")
			try:
				lednum = int(option.strip())
				if lednum < 1 or lednum > 3:
					print "Number out of range"
					continue
				numbytes = struct.pack('>H', lednum) #H is for unsigned short
			except:
				print "Error converting number"
				continue
			
			option = raw_input("Enter a new compare value for the LED duty cycle, 0-65535\n>>")
			try:
				ledval = int(option.strip())
				valbytes = struct.pack('>H', ledval)
			except:
				print "Error converting value"
				continue
						
			bob = bytearray([0x01, 0x01, 0x04])
			bob += numbytes
			bob += valbytes
			print "Sending bytes to encode and send: " + repr(list(bob)) #for debugging
			cobs.encode_and_send(bob) #confirm baud rate and com port
		elif sel == '2': # READING ADC
			#adc req
			print "Setting LED1 to the result of ADC Read"
			sam = bytearray([0x01, 0x08, 0x00])
			cobs.encode_and_send(sam)
			print "Reading raw bytes from serial response"
			retarray = cobs.block_and_return()
			print "Cobs decode result array: "
			print repr(retarray)
			try:
				adcval = struct.unpack('H', retarray)
				print "ADC val :"
				print int(adcval[0])
			except:
				print "Error converting adc value"
			#print cobs.read_and_build() #cant call directly, requires serial object
			#pause and read what comes next
		elif sel == '3': #MOTOR TEST
			#motor speed
			
			option = raw_input("Enter a new compare value for the motor duty cycle, 0-65535\n>>")
			try:
				val = int(option.strip())
				valbytes = struct.pack('>H', val)
			except:
				print "Error converting value"
				continue
								
			print "Sending command to the psoc5, commanding it to talk to the psoc4"
			cmd = bytearray([0x01, 0x01, 0x04])
			cmd += struct.pack('>H', 5)
			cmd += valbytes
			print "debug: array to encode: " + repr(cmd)
			print "debug: sending array to encode and send routine"
			cobs.encode_and_send(cmd)
		elif sel == '4': # SERVO CONTROL
			#
			print "Servo Control \n(see script to change min and max pulse widths. Currently defaulted to a TowerPro MG995 Servo)"
			option = raw_input("Enter a percentage >>")
			try:
				percent = float(option.strip())
				if percent < 0 or percent > 100:
					print "Error, Value not between 0 and 100."
					continue
				pwmcompare = ((percent/100) * (maxpulse - minpulse)) + minpulse
				pwmcompare = servo_period - pwmcompare #left align the positive pulse
				print "debug pwmcompare final value before conversion:" + repr(pwmcompare)
				comparebytes = struct.pack('>H', pwmcompare) #H is for unsigned short
			except:
				print "Error converting number"
				continue
			
			numbytes = struct.pack('>H', 4) #H is for unsigned short
			
			bytestosend = bytearray([0x01, 0x01, 0x04])
			bytestosend += numbytes
			bytestosend += comparebytes
			print "Sending bytes to encode and send: " + repr(list(bytestosend)) #for debugging
			cobs.encode_and_send(bytestosend) #confirm baud rate and com port
		elif sel == '5': #ultrasonic read
			