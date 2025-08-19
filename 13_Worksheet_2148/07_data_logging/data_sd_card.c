#include "data_header.h"
/*
* Function Name : void sd_enableWrite(void)
* Descriptio    : This Function Enables write operation on 
*                  the SD card 
*/
void sd_enableWrite(void)
{
	// Clear Chip Select pin 
	IOCLR0 = CS_U8;
	// Function call to Send Write Enable command
	SPI0_read_write(0x6);
	// Set Chip Select pin 
	IOSET0 = CS_U8;
}
/*
* Function Name : void sd_enableWrite(void)
* Descriptio    : This Function Disables write operation on 
*                  the SD card 
*/
void sd_disableWrite(void)
{
	// Clear Chip Select pin 
	IOCLR0 = CS_U8;
	// Function call to Send Write Disable command
	SPI0_read_write(0x04);
	// Set Chip Select pin 
	IOSET0 = CS_U8;
}
/*
* Function Name : void sd_dataWrite(uint8_t mr, uint8_t data)
* Descriptio    : This Function Writes one byte to the specified 
*                 SD card address
*/
void sd_dataWrite(uint8_t mr, uint8_t data)
{
	// Function call to Send Write Enable command 
	sd_enableWrite();
	// Clear Chip Select pin
	IOCLR0 = CS_U8;
	// Function call to write command
	SPI0_read_write(0x2);
	// Function call to write memory address
	SPI0_read_write(mr);
	// Function call to write data
	SPI0_read_write(data);
	// Set Chip Select pin
	IOSET0 = CS_U8;
	// Function call to Send Write disable command
	sd_disableWrite();
}
/*
* Function Name : uint8_t sd_dataRead(uint8_t mr)
* Descriptio    : This Function Read one byte from the specified 
*                 SD card address 
*/
uint8_t sd_dataRead(uint8_t mr)
{
	uint8_t dataRead;
	// Clear Chip Select pin
	IOCLR0 = CS_U8;
	// Function call to Send Read command 
	SPI0_read_write(0x03);
	// Function call to send memory address to read data
	SPI0_read_write(mr);
	// Function call to Read and store the returned data byte
	dataRead = SPI0_read_write(0x0);
	// Set Chip Select pin
	IOSET0 = CS_U8;
	// Return the read data
	return dataRead;
}

