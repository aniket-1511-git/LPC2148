#include <LPC214X.H>
#include <stdint.h>

/* defined macro for transmitter holding register empty  */
#define THRE_U8 ((U0LSR>>5)&1)
/* defined macro for receiver data ready */
#define RDR_U8  (U0LSR&1)
#define DONE_U8 ((AD0GDR>>31)&1) 
	 

void uart_init(uint16_t );            			 // Function to Initializes uart 0
void uart_charTransmit(uint8_t);             // Fucntion to Transmit char via uart0
uint8_t uart_charReceive(void);              // Fucntion to Receive char via uart0
void uart_stringTransmit(uint8_t *);				 // Fucntion to Transmit string via uart0
void uart_stringReceive(uint8_t *,uint8_t);  // Fucntion to Receive string via uart0
void uart_intT0string(int32_t num_32);       // Fucntion to Transmit integer via uart0


void adc_init(void);                         // Function to Initializes adc
uint16_t adc0_read_data(uint8_t chNo_u8);    // Function to ADC result

