#ledcontrol.py

# Script for LED control demo. 

import cobs
import struct

if __name__ == '__main__':
	print "\n**************************"
	print "**** led control Test ****"
	print "**************************\n"
	
	port = raw_input("Enter your serial port\n>>")
	
	while True:
		
		option = raw_input("Enter 1 to control LEDs, 2 for the ADC value, 3 to exit.\n>>")
		sel = option.strip()
		if sel == '3':
			break
		elif sel == '1':
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
			cobs.encode_and_send(bob, port, 115200, 1.0) #confirm baud rate and com port
		elif sel == '2':
			#adc req
			print "Setting LED1 to the result of ADC Read"
			sam = bytearray([0x01, 0x08, 0x00])
			cobs.encode_and_send(sam, port, 115200, 1.0)