#include "pws_header.h"

int main()
{
	int8_t pass[10],i=0;
	
	PINSEL0 |=0x00000000;
	IODIR0 	|=0xF|3<<14;
	
	lcd_init();
	while(1U)
	{
		if(i<4)
		{
			lcd_cmd(0x01);
			lcd_str("enter Password");
		  pass[i++] = psw_keyPad();
		  pass[i]='\0';
			lcd_cmd(0xC0);
			lcd_str(pass);
			ms_delay(100);
		}
		else
		{
			if(strcmp(pass,"1511")==0)
			{
				while(i<10)
					{
						lcd_cmd(0x01);
						lcd_cmd(0x80);
						lcd_str("Pasword Matched");
						IOSET0 |= 1<<14;
						ms_delay(100);
						IOCLR0 |= 1<<14;
						i++;
					}
			}
			else
			{
				while(i<10)
					{
						lcd_cmd(0x01);
						lcd_cmd(0x80);
						lcd_str("Password Invalid");
						IOSET0 |= 1<<15;
						ms_delay(100);
						IOCLR0 |= 1<<15;
						ms_delay(100);
						i++;
					}
			}
			i=0;
		}
	}
	 
}
