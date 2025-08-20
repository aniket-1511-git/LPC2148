#include "lcd_driver_header.h"
/*
* Function Name : void lcd_cmd_8bit(unsigned char cmd)
* Decription    : This Function to send command on lcd 
*/
void lcd_cmd_8bit(unsigned char cmd)
{
		// Clear bits P0.0 to P0.10
		IOCLR0 = 0X7FF;
		// send command to LCD
    	IOSET0 = cmd;
		// Clear Register Select line
   		IOCLR0 = RS;
		// Clear Read/Write line
		IOCLR0 = RW;
		// Set Enable line		
		IOSET0 = EN;
		// Function call to provide short delay
	 	ms_delay(2);
		// Clear EN line
		IOCLR0 = EN;
}
/*
* Function Name : void lcd_data_8bit(unsigned char data)
* Decription    : This Function to send data on lcd 
*/
void lcd_data_8bit(unsigned char data)
{
	// Clear bits P0.0 to P0.10
    IOCLR0 = 0X7FF;
	// send Data to LCD
    IOSET0 = data;
	// Set Register Select line
    IOSET0 = RS;
	// Clear Read/Write line
	IOCLR0 = RW;
	// Set Enable line	
	IOSET0 = EN;
	// Function call to provide short delay
	ms_delay(2);
	// Clear EN line
	IOCLR0 = EN;
}
/*
* Function Name : void lcd_init_8bit(void)
* Decription    : This Function to initialization of lcd 
*/
void lcd_init_8bit(void)
{
	// Set P0.0 to P0.10 as output
	IODIR0 = 0x7FF;
	 // Configure P0.0 to P0.15 as GPIO
	PINSEL0|=0x0;
	// Function call to Initializes LCD in 8-bit mode,
	lcd_cmd_8bit(0x38);
	// Function call to Turns on the display
	lcd_cmd_8bit(0x0E);
	// Function call to Clear display
	lcd_cmd_8bit(0x01);
}
/*
* Function Name : void lcd_string_8bit(char *p)
* Decription    : This Function to send string on lcd 
*/
void lcd_string_8bit(char *p)
{
		 // wait til end of string
		while(*p)
		{
			// Function call to send charater on LCD
			lcd_data_8bit(*p);
			// Move to the next character in the string
			p++;
		}
}

