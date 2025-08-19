#include "data_header.h"

/*
* Function name      : void spi_init_master(void)
* Description        : this function Initializes SPI0 with specified speed, Mode, and Pin selection                        
*/
void spi_init_master(void)
{
	// Configure Pins for UART0 function
	PINSEL0 |=0x00001505;
	// Configure speed of Speed of SPI
	S0SPCCR =  15;
	// Selection of SPI 0 as master
	S0SPCR = 0X20;
	// Select CS pin direction
	IODIR0 |= CS_U8;
	// Select CS pin Mode
	IOSET0 = CS_U8;
}
/*
* Function name      : uint8_t SPI0_read_write(uint8_t data_u8)
* Description        : this function read and write the data in spi0 data buffer                        
*/
uint8_t SPI0_read_write(uint8_t data_u8)
{
	// Store Data in spi data buffer
	S0SPDR = data_u8;
	// Wait until the SPIF_U8 flag is set
	while(SPIF_U8 == 0);
	// return data form spi buffer
	return S0SPDR;
}


