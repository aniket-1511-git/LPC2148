#include "led_header.h"

int main()
{
	IODIR0 |= LED_u8;
	IOSET0 |= LED_u8;
	while(1U)
	{
		IOSET0 |= LED1_u8;
		sec_delay(1);
		IOSET0 |= LED2_u8;
		sec_delay(1);
		IOSET0 |= LED3_u8;
		sec_delay(1);
		IOSET0 |= LED4_u8;
		sec_delay(1);
		IOCLR0 = LED_u8;
	}
	
	
}

