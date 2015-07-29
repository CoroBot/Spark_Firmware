import serial
import time
import binascii
import struct

#-------------------------------------------------------------------------------------------------#
#                                        cobs encoder                                             #
#-------------------------------------------------------------------------------------------------#

def encode_and_send(data,port,baud,to):
	#try:
	ser = serial.Serial(port,baud,timeout = to)
	#except:
		#print "error opening serial port, please double check configuration and try again"
		#return None
	try:
		send = bytearray('\0')
		send += build_frame(data)
		send += '\0'
		#print repr(send)
		#print
	except:
		print "error encoding packet, packet may be too long or of the incorrect type"
		return None
	ser.write(send)
	ser.close
	return 1
	
def build_frame(indata):
	framedat = indata
	framedat += crc32_checksum(indata)
	outdat = encode_cobs(framedat, len(framedat))
	return outdat
	
def crc32_checksum(encdata):
	checksum = binascii.crc32(encdata)
	bytcheck = struct.pack('>i', checksum)
	return bytcheck
	
def encode_cobs(indata,data_len):
	outframe = bytearray(len(indata)+1)
	z_offset = 0
	offset = 1
	while offset < (data_len+1):
		if indata[offset-1] == 0:
			outframe[z_offset] = (offset-z_offset)
			z_offset = offset
			outframe[z_offset] = 0
		else:
			outframe[offset] = indata[offset-1]
		offset +=1
	outframe[z_offset] = (offset-z_offset)
	return outframe


#--------------------------------------------------------------------------------------------------#
#                                        cobs decoder                                              #
#--------------------------------------------------------------------------------------------------#

def block_and_return(port, baud):
	try:
		ser = serial.Serial(port,baud,timeout = None)
	except:
		print "error opening serial port, please double check configuration and try again"
		return None
	got = read_and_build(ser)
	dec = decode_cobs(got)
	return test_checksum(dec)
	
def read_and_build(ser):
	rawdat = bytearray(69)
	offset = 0
	while True:
		inbyte = ser.read()
		if inbyte != 0:
			if offset == 63:
				offset = 0
				continue
			rawdat[offset] = inbyte
			offset+=1
			continue
		if offset < 5:
			offset = 0
			continue
		break
	retdat = bytearray(offset)
	for i in range(0,len(retdat)):
		retdat[i] = rawdat[i]
	return retdat
	
def decode_cobs(indata):
	offset = 0
	length = len(indata)
	outdata = bytearray(69)
	while offset < length:
		block = indata[offset]
		if block == 0:
			print "too short"
			return None
		if (offset+block)>length:
			print "too long"
			return None
		outdata[offset:offset + block-1] = indata[offset+1:offset+1+block-1]
		offset +=block
		if offset < length:
			outdata[offset-1] = 0
	outdata[offset-1] = 0
	retdat = bytearray(offset)
	for i in range(0,len(retdat)):
		retdat[i] = outdata[i]
	return retdat
		
def test_checksum(indata):
	datchecksum = binascii.crc32(indata[0:len(indata)-5])
	sentchecksum = struct.unpack('>i', indata[len(indata)-5:len(indata)-1])
	if datchecksum == sentchecksum[0]:
		return indata[0:len(indata)-5]
	else:
		return None
	
if __name__ == '__main__':
	print encode_cobs(bytearray([0,1,2,0,0,2,3]),7)
	print repr(encode_cobs(bytearray([0,1,2,0,0,2,3]),7))

	