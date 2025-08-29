#include "pws_header.h"
/*
* Function Name : int main(void)
* Description   : This Function used read the password form Keypad and check it 
*                 
*/
int main(void)
{
	// variable to store entered password & index 
	int8_t pass[10],i=0;
	// Configure PORT0 pins for GPIO
	PINSEL0 |=0x00000000;
	// Set PORT0 pins (0–3) and pins 14 & 15 as output
	IODIR0 	|=0xF|3<<14;
	 // Initialize LCD
	lcd_init();
	while(1U)
	{
		if(i<4)
		{
			// Clear LCD
			lcd_cmd(0x01);
			lcd_str("enter Password");
			// Read one key from keypad and stor
		  pass[i++] = psw_keyPad();
		 // Null-terminate string
		  pass[i]='\0';
			// Move cursor to 2nd line
			lcd_cmd(0xC0);
			// Display password
			lcd_str(pass);
			ms_delay(100);
		}
		else
		{
			// Check if entered password matches "1511"
			if(strcmp(pass,"1511")==0)
			{
				while(i<10)
					{
						// Clear LCD
						lcd_cmd(0x01);
						// Move cursor to 1st line
						lcd_cmd(0x80);
						// Show success message
						lcd_str("Pasword Matched");
						// Turn ON LED
						IOSET0 |= 1<<14;
						ms_delay(100);
						 // Turn OFF
						IOCLR0 |= 1<<14;
						i++;
					}
			}
			else
			{
				while(i<10)
					{
						// Clear LCD
						lcd_cmd(0x01);
						// Move cursor to 1st line
						lcd_cmd(0x80);
						 // Show failure message
						lcd_str("Password Invalid");
						// Turn ON LED
						IOSET0 |= 1<<15;
						ms_delay(100);
						// Turn OFF LED
						IOCLR0 |= 1<<15;
						ms_delay(100);
						i++;
					}
			}
			// Reset index
			i=0;
		}
	}
	 
}
