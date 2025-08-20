#include "lcd_driver_header.h"
/*
* Function Name : int main(void)
* Decription    : This Function to write data on LCD Display
*/
int main(void)
{
	// Function call to init LCD
	lcd_init_8bit();
	// Function call to send  Starting addr of  first line
	lcd_cmd_8bit(0x82);
	// Function call to display message on LCD 
	lcd_string_8bit("Welcome To ");
	// Function call to send  Starting addr of  Second line
	lcd_cmd_8bit(0xC3);
	// Function call to display message on LCD 
	lcd_string_8bit("LPC 2148");
}

