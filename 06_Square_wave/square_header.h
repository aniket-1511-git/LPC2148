#include <LPC214X.H>
/*Macro defind for P1.16*/
#define sqWave_u8 1<<16

typedef signed char       int8_t;   // 8-bit signed
typedef unsigned char     uint8_t;  // 8-bit unsigned

typedef signed int        int32_t;  // 32-bit signed 
typedef unsigned int      uint32_t; // 32-bit unsigned

typedef signed short int  int16_t;  // 16-bit signed
typedef unsigned short int uint16_t; // 16-bit unsigned 
	 

void msec_delay(uint32_t );    	     // Function to generate delay in millisec
void sec_delay(uint32_t );    	     // Function to generate delay in sec
void usec_delay(uint32_t );    	     // Function to generate delay in microsec
