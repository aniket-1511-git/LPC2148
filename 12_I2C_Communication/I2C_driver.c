#include "I2C_header.h"

/*
* Function Name : void i2c_init(void)
* Decription    : this function Initializes I2C controller 
*/

void i2c_init(void)
{
	// I2C Pin selection 
	PINSEL0 |= 0x55;
	// Select speed 100 kbps 
	I2C0SCLH = 75;
	// Select speed 100 kbps 
	I2C0SCLL = 75;
	// Enable I2c0 controller 
	I2C0CONSET = (1<<6);
}

/*
* Function Name : void i2c_byteWriteFrame(uint8_t sa_u8, uint8_t mrAddr_u8,uint8_t data_u8)
* Decription    : this function used to send slave address, memory address and data to I2c
*                 I2C controller
*/

void i2c_byteWriteFrame(uint8_t sa_u8, uint8_t mrAddr_u8,uint8_t data_u8)
{
	// Start i2c controller
	I2C0CONSET = (1<<5);
	// clear i2c SI flag
	I2C0CONCLR = (1<<3);
	// Wait till SI flag set
	while(SI==0);
	// Clear i2c start flag
	I2C0CONCLR = (1<<5);
	// Store slave addr in i2c data register
	I2C0DAT = sa_u8;
	// clear i2c SI flag 
	I2C0CONCLR = (1<<3);
	// Wait till SI flag set
	while(SI==0);
	// check if i2c slave addr transmitted
	if(I2C0STAT == 0x20)
	{
		// goto exit lable 
		goto exit;
	}
	// Store Memory addr in i2c data register
	I2C0DAT = mrAddr_u8;
	// clear i2c SI flag 
	I2C0CONCLR = (1<<3);
	// Wait till SI flag set
	while(SI==0);
	// check if i2c mem addr transmitted 
	if(I2C0STAT==0x30)
	{
		// goto exit lable 
		goto exit;
	}
	// Store data in i2c data register
	I2C0DAT = data_u8;
	// clear i2c SI flag 
	I2C0CONCLR = (1<<3);
	// Wait till SI flag set
	while(SI==0);
	// check if data transmitted 
	if(I2C0STAT==0x30)
	{
		// goto exit lable 
		goto exit;
	}
	// Stop i2c Controller 
	exit:
	I2C0CONSET = (1<<4);
	// clear i2c SI flag 
	I2C0CONCLR = (1<<3);
	
}
/*
* Function Name : uint8_t  i2c_byteReadFrame(uint8_t sa_u8, uint8_t mrAddr_u8)
* Decription    : this function used to read the data form slave ant it's memory address
*/
uint8_t  i2c_byteReadFrame(uint8_t sa_u8, uint8_t mrAddr_u8)
{
	// Varriable to store I2C data
	uint8_t readData;
	// Start i2c controller
	I2C0CONSET = (1<<5);
	// clear i2c SI flag 
	I2C0CONCLR = (1<<3);
	// Wait till SI flag set
	while(SI==0);
	// Clear i2c start flag
	I2C0CONCLR = (1<<5);
	// Store slave addr in i2c data register
	I2C0DAT = sa_u8;
	// clear i2c SI flag 
	I2C0CONCLR = (1<<3);
	// Wait till SI flag set
	while(SI==0);
	// check if i2c slave addr transmitted 
	if(I2C0STAT==0x20)
	{
		// goto exit lable 
		goto exit;
	}
	// Store Memory addr in i2c data register
	I2C0DAT = mrAddr_u8;
	// clear i2c SI flag 
	I2C0CONCLR = (1<<3);
	// Wait till SI flag set
	while(SI==0);
	// check if i2c mem addr transmitted
	if(I2C0STAT==0x30)
	{
		// goto exit lable 
		goto exit;
	}
	// Restart i2c Controller 
	I2C0CONSET = (1<<5);
	// clear i2c SI flag 
	I2C0CONCLR = (1<<3);
	// Clear i2c start flag
	while(SI==0);
	I2C0CONCLR = (1<<5);
		// Store slave addr in i2c data register
	I2C0DAT = sa_u8|1;
	// clear i2c SI flag 
	I2C0CONCLR = (1<<3);
	// Wait till SI flag set
	while(SI==0);
	// check if i2c slave addr transmitted 
	if(I2C0STAT==0x48)
	{
		// goto exit lable 
		goto exit;
	}
	// clear i2c SI flag 
	I2C0CONCLR = (1<<3);
	// Wait till SI flag set
	while(SI==0);
	// Get received data
	readData = I2C0DAT;
	// check if data stored  
	if(I2C0STAT == 0x30)
	{
		// goto exit lable 
		goto exit;
	}
	exit:
	// Stop i2c Controller 
	I2C0CONSET = (1<<4);
	// clear i2c SI flag 
	I2C0CONCLR = (1<<3);
	// return received data
	return readData;
}



