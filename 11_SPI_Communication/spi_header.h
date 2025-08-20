#include <LPC214X.H>
#include <stdint.h>
/* Macro defined for Chip Select pin */
#define CS_U8 (1<<7)
/* Macro defined for SPIF Flag */
#define SPIF_U8 ((S0SPSR>>7)&1)
/* Macro defined for THRE Flag */
#define THRE_U8 ((U0LSR>>5)&1)


void spi_init_master(void);                // Function to Initializes SPI
uint8_t SPI0_read_write(uint8_t data_u8); // Function to Read and write data from SPI
uint32_t spi0_exxtAdc(uint8_t chNo_U8);   // Function to read data from SPI Slave

void uart_init(uint16_t );            		// Function to Initializes uart 0
void uart_charTransmit(uint8_t);             // Fucntion to Transmit char via uart0
uint8_t uart_charReceive(void);              // Fucntion to Receive char via uart0
void uart_stringTransmit(uint8_t *);				 // Fucntion to Transmit string via uart0
void uart_stringReceive(uint8_t *,uint8_t);  // Fucntion to Receive string via uart0
void uart_intT0string(int32_t num_32);       // Fucntion to Transmit integer via uart0