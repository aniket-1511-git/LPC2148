#include "lcd_driver_header.h"
void lcd_cmd_8bit(unsigned char cmd)
{
		IOCLR0 = 0X7FF;
    IOSET0 = cmd;
    IOCLR0 = RS;
		IOCLR0 = RW;
		IOSET0 = EN;
	  ms_delay(2);
		IOCLR0 = EN;
}
void lcd_data_8bit(unsigned char data)
{
    IOCLR0 = 0X7FF;
    IOSET0 = data;
    IOSET0 = RS;
		IOCLR0 = RW;
		IOSET0 = EN;
	  ms_delay(2);
		IOCLR0 = EN;
}
void lcd_init_8bit(void)
{
	IODIR0 = 0x7FF;
	PINSEL0|=0x0;
	lcd_cmd_8bit(0x38);
	lcd_cmd_8bit(0x0E);
	lcd_cmd_8bit(0x01);
}

void lcd_string_8bit(char *p)
{
		while(*p)
		{
			lcd_data_8bit(*p);
			p++;
		}
}

