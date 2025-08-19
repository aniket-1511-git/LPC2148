#include "data_header.h"
/*
* Function Name : int main(void)
* Descriptio    : This Function  
*                  
*/
int main(void)
{
	uint8_t readData;
	// Function call to Initialize the LCD display
	lcd_init();
	// Function call to Initialize SPI in master mode
	spi_init_master();
	// Function call to Write char 'A' to SD card 
	sd_dataWrite(0x5,'A');
	ms_delay(5);
	// Function call to Read back the data from address
	readData = sd_dataRead(0x5);
	 // Function call to Display the read data on the LCD
	lcd_data(readData);
	
	while(1);
}


