#include <LPC214X.H>

/* defined macro for transmitter holding register empty  */
#define THRE_U8 ((U0LSR>>5)&1)

/* defined macro for receiver data ready */
#define RDR_U8  (U0LSR&1)

typedef signed char       int8_t;   // 8-bit signed
typedef unsigned char     uint8_t;  // 8-bit unsigned

typedef signed int        int32_t;  // 32-bit signed 
typedef unsigned int      uint32_t; // 32-bit unsigned

typedef signed short int  int16_t;  // 16-bit signed
typedef unsigned short int uint16_t; // 16-bit unsigned 
	 

void uart_init(uint16_t );            	     // Function to Initializes uart 0
void uart_charTransmit(uint8_t);             // Fucntion to Transmit char via uart0
uint8_t uart_charReceive(void);              // Fucntion to Receive char via uart0
void uart_stringTransmit(uint8_t *);	     // Fucntion to Transmit string via uart0
void uart_stringReceive(uint8_t *,uint8_t);  // Fucntion to Receive string via uart0
