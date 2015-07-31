/* ========================================
 *
 * Copyright Coroware Robotics Solutions
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Coroware Robotics Solutions.
 *
 * ========================================
*/

/**********************************************************/
/* Required Includes                                      */
/**********************************************************/
#include <project.h>
#include <cobs.h>
#include <string.h>
//#include <cypins.h>

/***************************************
* Symbolic Constants
***************************************/

// Commands
#define SET_ATTRIB 1
#define READ_ADC 8

// Local attributes
#define ATTRIB_LED1 1
#define ATTRIB_LED2 2
#define ATTRIB_LED3 3


/**********************************************************/
/* Structure Definitions and Declarations                 */
/**********************************************************/

// Receive ring buffer
typedef struct {
	int capacity;
	int head;
	int tail;
	int available;
	uint8 *buffer;
} ringbuff_t;

ringbuff_t u_recv;
uint8 u_ringbuff_buff_rx[2048];

ringbuff_t u_send;
uint8 u_ringbuff_buff_tx[2048];

ringbuff_t h_recv;
uint8 h_ringbuff_buff_rx[2048];

ringbuff_t h_send;
uint8 h_ringbuff_buff_tx[2048];

// Command Buffer
#define CMD_MAX 64
uint8 cmd_buff[CMD_MAX];
int   cmd_offset = 0;

// Fix up stupidity with compiler/syntax highlighter in PSoC Creator
#define true 1
#define false 0

uint8 hexdigits[]="0123456789ABCDEF";

// Hacky implementation to respond to an ADC request
int sendADCFlag = 0;
int16 adcval = 0;

/**********************************************************/
/* Function Declarations                                  */
/**********************************************************/
void init(void);
void hw_init(void);
void handle_usb(void);
void handle_uart(void);

// Convenience Functions
int  getkey(void);
int hgetkey(void);
int b_hgetkey(void);
void uputs(char *str);
void uputc(int key);
void hputs(char *str);
void hputc(int key);
int b_getkey(void);
int getnum();
int getnums(uint8 *buf, int count);
void hexp(int by);
void hexdump(uint8 *buffer, int numbytes);

// merged functions
void encode_and_send_usb(unsigned char* buf, int length);
int blinkLED(void);
void handleFrames(void);
void handle_Frame(uint8_t *frame, unsigned int length);
void set_attribute(uint8_t *frame, unsigned int length);
void report_adc_val();

//network utility functions, could be moved to cobs
void uint16toNO(uint16_t invalue, unsigned char *outbuf);

// Hardware Control Functions


//Ring Buffer Functions
int  ringbuff_put(ringbuff_t *ringbuffer, uint8 data);
int  ringbuff_get(ringbuff_t *ringbuffer);
int  ringbuff_size(ringbuff_t *ringbuffer);
int  ringbuff_canput(ringbuff_t *ringbuffer, uint8 nbytes);

/**********************************************************/
/* Procedures Begin Here                                  */
/**********************************************************/
int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
	CyGlobalIntEnable;
	init();
	hw_init();
	RS485CTL_Write(0);

    //Set up ADC and PWM
    ADC_Start();
    ADC_StartConvert();
    PWM_1_Start();
    PWM_2_Start();
    PWM_3_Start();
    
	USB_Start(0,USB_DWR_VDDD_OPERATION); 

	while(!USB_GetConfiguration()){}; 

    
	USB_CDC_Init();
	hw_init();
	
	RS485CTL_Write(0);

    // LED Controls
    //PWM_1_WriteCompare(1900); //period is 2000.
    blinkLED(); //to signal all set up is done, entering for loop
    
    
    
    for(;;)
    {
        
		handle_usb(); // incoming serial info
		handle_uart(); 

        handleFrames();
         
        
        // send the adc value if the user requested it.
        // This is a duplicate of the "method 1" below, wrapped in an if check.
        if (sendADCFlag) {
            unsigned char outdat[12];
            unsigned char indat[11] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7};
            uint16toNO(uint16_t invalue, unsigned char *outbuf);
            
            uint32_t crc32 = Crc32_ComputeBuf(0, indat, 7);
            uint32toNO(crc32, &indat[7]);
            
            encode_cobs(indat, 11, outdat);
            
            uputc(0);
            uputs(outdat);
            uputc(0);
            sendADCFlag = 0;   
        }
        
        // Test writing out of psoc to PC
        
        // *********** method 1 *****************
        
//        // Dummy test arrays
//        unsigned char outdat[12];
//        unsigned char indat[11] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7};
//        
//        
//        uint32_t crc32 = Crc32_ComputeBuf(0, indat, 7);
//        uint32toNO(crc32, &indat[7]);
//        
//        encode_cobs(indat, 11, outdat);
//        
//        uputc(0);
//        uputs(outdat);
//        uputc(0);
        
        
        // ************ method 2 *****************
        
//        unsigned char indat[7] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7};
//        encode_and_send_usb(indat, 7); // at the moment, parameters dont matter, 
//                                       //behavior is hardcoded until debugged.
        
        // end test communications.
        
		if (ringbuff_size(&u_recv) > 0 && ringbuff_canput(&h_send,1)) {
			int ch = ringbuff_get(&u_recv);
			ringbuff_put(&h_send, ch);
		}
		if (ringbuff_size(&h_recv) > 0 && ringbuff_canput(&u_send,1)) {
			ringbuff_put(&u_send, ringbuff_get(&h_recv));
		}
	}
}




// ***********************************************
// Merged functions
// ***********************************************

void uint16toNO(uint16_t invalue, unsigned char *outbuf) {
    outbuf[1] = (invalue & 0xFF);
	outbuf[0] = (invalue >> 8) & 0xFF;
}

void encode_and_send_usb(unsigned char* buf, int length) {

//    // Duplicate code from main:
//    
//    // Test writing out of psoc to PC
//    
//    // Dummy test arrays
//    unsigned char outdat[12];
//    unsigned char indat[11] = {0x1, 0x0, 0x3, 0x0, 0x0, 0x6, 0x7};
//    uint32_t crc32 = Crc32_ComputeBuf(0, indat, 7);
//    uint32toNO(crc32, &indat[7]);
//    
//    encode_cobs(indat, 11, outdat);
//    
//    uputc(0);
//    uputs(outdat);
//    uputc(0);
        
    // ********** Desired Functionaliy (once its debugged) ***************
        
    unsigned char indat[length + 4];
    memcpy(indat, buf, length); 
    //strncpy(buf, indat, length); 
    
    uint32_t crc32 = Crc32_ComputeBuf(0, indat, length);
    uint32toNO(crc32, &indat[length]);
    
    unsigned char outdat[length + 5];
    encode_cobs(indat, length + 4, outdat);
    
    uputc(0);
    uputs(outdat);
    uputc(0);
}

void handleFrames(void) {
    
	static int offset = 0;
	static uint8_t inframe[64];
	static uint8_t decoded[64];
	
	int inbyte;

	while (1) {
		//inbyte = U_RX_UartGetByte(); //replaed by getkey()
        inbyte = getkey(); //returns -1 if no key returned.
        
		if (inbyte == -1) { // Handle buffer underrun / serial error
            
			return; // Assume the problem is an underrun. Anything else will fail
			        // cobs decode or CRC32 check. Save partial frame and go around
			        // again to wait for more bytes to arrive in the buffer.
		}
		// Zeroes are frame delimeters. If the byte is not a zero, it's probably part of the data.
		// If so, add it to the input buffer - with boundary checking to avoid buffer overruns.
		if (inbyte != 0) {
			if (offset == 63) { // Frame too long - dump.
				offset = 0;
				continue; // Jump back to start of loop
			}
			inframe[offset] = inbyte;
			offset++;
			continue; // Jump back to start of loop
		}
		// At this point we know that inbyte == 0
		
		if (offset < 5) { // Frame too short - dump
			offset = 0;
			continue;
		}
		break; // Have a full frame - time to do something sane with it.
	}
    

    
	int rv = decode_cobs(inframe, offset, decoded);
	if (rv < 0) { // If the decoder blew up, we have a bad frame. Dump.
		offset = 0;
		return;
	}
        

	uint32_t cmp_crc32 = NO_to_uint32(&decoded[rv-4]);
	uint32_t crc32 = Crc32_ComputeBuf(0, decoded, rv-4);
	if (crc32 != cmp_crc32) { // Bad CRC32 - dump frame
		offset = 0;
		return;
	}
    

	offset = 0;

	handle_Frame(decoded, rv); // Good frame - Process result
}

void handle_Frame(uint8_t *frame, unsigned int length) {
//	if (frame[0] != Unit_Number) { // If they're not talking to us
//		return; // Drop the frame on the floor
//	}
    
	length -= 4; // Snip off CRC32

	switch (frame[1]) {
		
		case 0: // Send buffered frame
			//send_frame_really();
			break;
		
		case 1: // Set attribute (integer)
			set_attribute(frame, length);
			break;

		case 2: // Set attribute (octet string)
			break; //Stub -- not implemented yet

		case 3: // Send hardware description
			break; //Stub -- not implemented yet

		case 4: // Enable output
			//Enable_Output = true;
			break;

		case 5: // Disable Output
			//Enable_Output = false;
			break;
		case 8: // Read ADC value
            report_adc_val(); //temporarily just sets LED1 to the adc read value.
            break;
		default:
			break;
	}	
}

void report_adc_val() {
    blinkLED();
    int16 adcResult = ADC_GetResult16(0x00u);   
    // encode and send back over wire?
    // for now lets just set an led to the pot value to show we can read the ADC.
    PWM_1_WriteCompare(adcResult);
    
    //set global flags (hacky way)
    adcval = adcResult;
    sendADCFlag = 1;
    
    // desired way, prep data buffer and encode_and_send();
//    unsigned char dat[7] = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7};
//    encode_and_send_usb(dat, 7);
}

void set_attribute(uint8_t *frame, unsigned int length) {
	// Guard check - Don't try to decode past end of buffer
	if (length < 7) {
		return;
	}
    
	//decode both integers
    
	uint16_t attrib = NO_to_int16(&frame[3]); //first two data bytes are attribute
	uint16_t value = NO_to_int16(&frame[5]); //second two bytes are value

	//set the desired attribute to the desired value.
	switch (attrib) {
		case ATTRIB_LED1:
            PWM_1_WriteCompare(value);
			break;
		case ATTRIB_LED2:          
            PWM_2_WriteCompare(value);
			break;
		case ATTRIB_LED3:
            PWM_3_WriteCompare(value);
			break;
		default:
			break;
	}
}

// ******************************
// End merged functions
// ******************************

//Note, reordered from above, just to make debugging easier.
int blinkLED(void) {

    PWM_1_WriteCompare(PWM_1_ReadPeriod()); //sets the duty cycle to on 100% of time
	CyDelay(200);
	
    PWM_1_WriteCompare(0); // turns LED off
	CyDelay(200);

	PWM_1_WriteCompare(PWM_1_ReadPeriod());
    CyDelay(200);
    
    PWM_1_WriteCompare(0);
    CyDelay(200);
    
    return 0;
}

void init(void) {

	// Set up USB UART Receive Buffer
	u_recv.buffer = u_ringbuff_buff_rx;
	u_recv.capacity = 2048;
	u_recv.head = 0;
	u_recv.tail = 0;
	u_recv.available = 0;	

	// Set up USB UART Transmit Buffer
	u_send.buffer = u_ringbuff_buff_tx;
	u_send.capacity = 2048;
	u_send.head = 0;
	u_send.tail = 0;
	u_send.available = 0;	

	// Set up Hardware UART Receive Buffer
	h_recv.buffer = h_ringbuff_buff_rx;
	h_recv.capacity = 2048;
	h_recv.head = 0;
	h_recv.tail = 0;
	h_recv.available = 0;	

	// Set up Hardware UART Transmit Buffer
	h_send.buffer = h_ringbuff_buff_tx;
	h_send.capacity = 2048;
	h_send.head = 0;
	h_send.tail = 0;
	h_send.available = 0;	

}

void hw_init(void) {
	U_Start();
}

void handle_usb(void) {
	int i;
	int sbytes;
	static uint8 datbuf[64];
    
	
	//Handle incoming frames
	if (USB_DataIsReady() != 0u) {
		int count = USB_GetAll((unsigned char *)datbuf);
		if (count) {
			for (i=0; i<count; i++) {
				ringbuff_put(&u_recv,datbuf[i]);
			}
		}
	}

	//Handle outgoing frames
	if (USB_CDCIsReady() != 0) {
		sbytes = ringbuff_size(&u_send);
		if (sbytes > 63) {
			sbytes = 63;
		}
		for (i=0; i<sbytes; i++) {
			datbuf[i] = ringbuff_get(&u_send);
		}
		if (sbytes > 0) {
			USB_PutData(datbuf, sbytes);
		}
	}
}

void handle_uart(void) { //will eventually talk between psoc5 and psoc4's. Unimplemented.
	int i;
	int sbytes;
	
	//Handle incoming serial data
	if (U_GetRxBufferSize() != 0u) {
		int count = U_GetRxBufferSize();
		if (count) {
            //blinkLED();
			for (i=0; i<count; i++) {
				uint16 rb = U_GetByte();
				if (rb > 255) { 
					continue;
				}
				ringbuff_put(&h_recv, rb);
			}
		}
	}

	//Handle outgoing serial data
	sbytes = ringbuff_size(&h_send);
	if (sbytes > 0 && U_GetTxBufferSize() < 4) { //ONLY works if TX software buffer disabled!
		U_PutChar(ringbuff_get(&h_send));
	}

}

/********************************************************************/
/* Ring Buffer Functions                                            */
/********************************************************************/

int ringbuff_put(ringbuff_t *ringbuffer, uint8 data){
	if (ringbuffer->available == ringbuffer->capacity) {
		return -1;
	}
	ringbuffer->buffer[ringbuffer->tail] = data;
	ringbuffer->tail = (ringbuffer->tail +1) % ringbuffer->capacity;
	ringbuffer->available += 1;
	
	return 0;
}

int  ringbuff_get(ringbuff_t *ringbuffer) {
	if (ringbuffer->available == 0) {
		return -1;
	}
	int cout = ringbuffer->buffer[ringbuffer->head];
	ringbuffer->head = (ringbuffer->head + 1) % ringbuffer->capacity;
	ringbuffer->available -= 1;
	
	return cout;
}

int  ringbuff_size(ringbuff_t *ringbuffer) {
	return ringbuffer->available;
}

int  ringbuff_canput(ringbuff_t *ringbuffer, uint8 nbytes) {
	if ((ringbuffer->available + nbytes) < ringbuffer->capacity) {
		return true;
	}
	return false;
}

/********************************************************************/
/* Hardware Interface Functions                                     */
/********************************************************************/


/********************************************************************/
/* Convenience Functions                                            */
/********************************************************************/
int getkey(void) {  //use this in combination with the handleFrames
	int key = ringbuff_get(&u_recv);
	return key;
}

int hgetkey(void) {
	int key = ringbuff_get(&h_recv);
	return key;
}

//blocking
int b_getkey(void) {
	int key = ringbuff_get(&u_recv);
	while (1) {
		if (key >= 0) {
			break;
		}
		handle_usb();
		handle_uart();
		key = ringbuff_get(&u_recv);
	}
	return key;
}

int b_hgetkey(void) {
	int key = ringbuff_get(&h_recv);
	while (1) {
		if (key >= 0) {
			break;
		}
		handle_usb();
		handle_uart();
		key = ringbuff_get(&h_recv);
	}
	return key;
}

void uputs(char *str) { //should this take an unsigned char* ?
	int i;
	int slen;
	slen = strlen(str);
	if (!ringbuff_canput(&u_send, slen)) {
		handle_usb(); // NO SUPPORT FOR SENDING STRINGS LARGER THAN BUFFER
		handle_uart();
	}
	for (i = 0; i < slen;i++) {
		ringbuff_put(&u_send, str[i]);
	}
}

void hputs(char *str) {
	int i;
	int slen;
	slen = strlen(str);
	if (!ringbuff_canput(&h_send, slen)) {
		handle_usb(); // NO SUPPORT FOR SENDING STRINGS LARGER THAN BUFFER
		handle_uart();
	}
	for (i = 0; i < slen;i++) {
		ringbuff_put(&h_send, str[i]);
	}
}

void uputc(int key) {
	if (!ringbuff_canput(&u_send, 1)) {
		handle_usb(); // NO SUPPORT FOR SENDING STRINGS LARGER THAN BUFFER
		handle_uart();
	}
	ringbuff_put(&u_send, key);
}

void hputc(int key) {
	if (!ringbuff_canput(&h_send, 1)) {
		handle_usb(); // NO SUPPORT FOR SENDING STRINGS LARGER THAN BUFFER
		handle_uart();
	}
	ringbuff_put(&h_send, key);
}

int gethex(void) {
	int key = 0;
	while (1) {
		key = b_getkey();
		if (key == 27) return -2;
		if (key == 10) return -1;
		if (key == 13) return -1;
		if (key == 32) return -1;
		if (key >= 48 && key <= 57) return key-48;
		if (key >= 65 && key <= 70)	return key-55;
		if (key >= 97 && key <= 102) return key-87;
	}
}

int getnum() {
	int digit1;
	int digit2;
	
	digit1 = gethex();
	if (digit1 > 0) {
		uputc(hexdigits[digit1]);
	} else {
		return digit1;
	} 
	digit2 = gethex();
	if (digit2 == -1) {
		return digit1;
	} else if (digit2 < -1) {
		return digit2;
	}
	uputc(hexdigits[digit2]);
	uputc(' ');
	return (digit1 << 4) + digit2;
}

int getnums(uint8 *buf, int count) {
	int i = 0;
	int rv = 0;
	for (i=0; i<count; i++) {
		rv = getnum();
		if (rv > 0) {
			buf[count] = rv;
		} else {
			break;
		}
	}
	if (rv == -2) {
		i=-1;
	}
	return i;
}

void hexp(int by) {
		uputc(hexdigits[by>>4]);
		uputc(hexdigits[by%16]);
}


void hexdump(uint8 *buffer, int numbytes) {
	int i;
	for (i=0; i<numbytes; i++) {
		uputc(hexdigits[buffer[i]>>4]);
		uputc(hexdigits[buffer[i]%16]);
		uputc(' ');
	}
}

/* [] END OF FILE */
