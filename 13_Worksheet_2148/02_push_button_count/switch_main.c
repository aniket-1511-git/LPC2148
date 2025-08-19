// header file 
#include "switch_header.h"
/*
* Function Name : int main(void)
* Description   : This Function init lcd, check the switch press count and display 
*                 it on lcd
*/
int main(void)
{
	// Varriable for switch count
	int swCount=0;
	// function call to init LCD 
	lcd_init();
	while(1)
	{
		// checking switch is pressed or not
		if(sw1==0)
		{
			// wait till switch release
			while(sw1==0);
			// count increment
				swCount++;
		}
		// function call to display message on LCD
		lcd_str("Count : ");
		// function call to display switch count on LCD
		lcd_intNo(swCount);
		// function call to restart writing from first line
		lcd_cmd(0x80);
	}
}

