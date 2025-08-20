#include "lcd_driver_header.h"
/*
* Function Name : void ms_delay(unsigned int ms)
* Decription    : This Function generates software delay
*/
void ms_delay(unsigned int ms)
{
    unsigned int i,j;
	// loop runs ms times 
	for(i=0;i<ms;i++)
	{
		//  loop creates a short delay
		for(j=0;j<12000;j++);
	}
}

