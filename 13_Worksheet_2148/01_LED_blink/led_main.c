#include "led_header.h"
/*
* Function name      : int main(void)
* Description        : this function blink LED's in Pattern
*                      
*/
int main(void)
{
	// set Output direction to p0.0 to p0.3
	IODIR0 |= LED_u8;

	while(1U)
	{
		// On led 1		
		IOSET0 |= LED1_u8;
		// Function Call to generate Delay
		sec_delay(1);
		// On led 2
		IOSET0 |= LED2_u8;
		// Function Call to generate Delay
		sec_delay(1);
		// On led 3
		IOSET0 |= LED3_u8;
		// Function Call to generate Delay
		sec_delay(1);
		// On led 4
		IOSET0 |= LED4_u8;
		// Function Call to generate Delay
		sec_delay(1);
		// Off All LED's
		IOCLR0 = LED_u8;
	}
	
	
}

