#include <LPC214X.H>
// Macro define for P0.14, P0.15 and P0.16
#define LED 7<<14
/*
* Function Name : void delay(unsigned int ms)
* Decription    : This Function generates software delay
*/
void delay(unsigned int ms)
{
	// Loop to iterate till delay time         
	for(unsigned int i=0;i<ms;i++);
}
/*
* Function Name : int main(void)
* Decription    : This Function blink the led after 100000 ms delay 
*/
int main(void)
{
	// Select output direction for LED
	IODIR0 |= LED;
	
	while(1)
	{
		// Set the LED pins
		IOSET0 |= LED;
		// Function call to generate delay
		delay(100000);
		// Clear the LED Pins
		IOCLR0 |= LED;
		// Function call to generate delay
		delay(100000);
	}
}


