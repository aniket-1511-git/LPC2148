#include "spi_header.h"

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

/*
* Function name      : uint32_t spi0_exxtAdc(uint8_t chNo_U8)
* Description        : this function read the analog output form External ADC                       
*/

uint32_t spi0_exxtAdc(uint8_t chNo_U8)
{
	// Varriable to store lowwer and higher byte of data 
	uint8_t lData,hdata;
	// Varriable to store adc output
	uint32_t adcData=0;
	// Enable CS Pin 
	IOCLR0 = CS_U8;
	// Function Call to pass data
	SPI0_read_write(0x060);
	// Function Call to send channel no and read data 
	hdata = SPI0_read_write(chNo_U8<<6);
	// Function Call to read data 
	lData = SPI0_read_write(0x0);
	// Disable CS Pin 
	IOSET0 = CS_U8;
	// store higher and lowwer byte 
	adcData = (hdata<<8)|lData;
  // return Adc data 
	return adcData;
}





