#include "gpio_header.h"

int main()
{
	while(1)
	{
		
		
/********************* Pin Write ***********************/
		/*
		// Set pin P0.1 to HIGH
		pinWrite(1,1);
		// Set pin P1.16 to HIGH
		pinWrite(116,1);
		// Function call to generate delay
		delay(1000000);
		// Set pin P0.1 to LOW
		pinWrite(1,0);
		// Set pin P1.16 to LOW
		pinWrite(116,0);
		// Function call to generate delay
		delay(1000000);
		*/
/********************* Pin Write ***********************/
		// Set Port 0 pins 0 to 3 to High
		portWrite(0,15);
		// Set Port 1 pins 16 to 19 to HIGH
		portWrite(12,15);
		// Function call to generate delay
		delay(1000000);
		// Set Port 0 pins 0 to 3 to LOW
		portWrite(0,0);
		// Set Port 1 pins 16 to 19 to LOW
		portWrite(12,0);
		// Function call to generate delay
		delay(1000000);
		
	}
}

