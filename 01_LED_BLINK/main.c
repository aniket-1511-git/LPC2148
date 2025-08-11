#include <LPC214X.H>
#define LED 7<<14
void delay(unsigned int ms)
{
	for(unsigned int i=0;i<ms;i++);
}
int main()
{
	IODIR0 |= LED;
	
	while(1)
	{
		IOSET0 |= LED;
		delay(100000);
		IOCLR0 |= LED;
		delay(100000);
	}
}


