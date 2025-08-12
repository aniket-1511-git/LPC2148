#include "lcd_driver_header.h"
int main()
{
	lcd_init_8bit();
	
	lcd_cmd_8bit(0x82);
	lcd_string_8bit("Welcome To ");
	lcd_cmd_8bit(0xC3);
	lcd_string_8bit("LPC 2148");
}

