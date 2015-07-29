/* ========================================
 *
 * Copyright Coroware, Inc. 2014
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Coroware, Inc.
 *
 * ========================================
*/
#include <stdlib.h>
#include <stdint.h>

enum boolean {
	false = 0,
	true = 1
};

typedef enum boolean bool;

uint32_t Crc32_ComputeBuf( uint32_t inCrc32, const void *buf, size_t bufLen );
int encode_frame(unsigned char *indata, int data_len, unsigned char *outframe);
int decode_frame(unsigned char *inframe, unsigned char *outframe, int maxlen);
int encode_cobs(unsigned char *indata, int data_len, unsigned char *outframe);
int decode_cobs(unsigned char *inframe, int length, unsigned char *outframe);
inline void uint32tole(uint32_t invalue, unsigned char *outbuf);
inline uint32_t le_to_uint32(unsigned char *inbuf);
inline void uint32toNO(uint32_t invalue, unsigned char *outbuf);
inline uint32_t NO_to_uint32(unsigned char *inbuf);
int16_t NO_to_int16(unsigned char * inbuf);

/* [] END OF FILE */
