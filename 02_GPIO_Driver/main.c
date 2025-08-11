#include "gpio_header.h"

int main()
{
	while(1)
	{
		
		
/********************* Pin Write ***********************/
		/*
		pinWrite(1,1);
		pinWrite(116,1);
		delay(1000000);
		pinWrite(1,0);
		pinWrite(116,0);
		delay(1000000);
		*/
/********************* Pin Write ***********************/
		portWrite(0,15);
		portWrite(12,15);
		delay(1000000);
		portWrite(0,0);
		portWrite(12,0);
		delay(1000000);
		
	}
}

