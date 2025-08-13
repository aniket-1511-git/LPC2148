#include "square_header.h" 


/*
* Function name      : int main(void)
* Description        : this function generate the square wave on 
*                      every 50 micros delay 
*/

int main(void)
{
	// setting output direction on p1.16 pin
	IODIR1 |= sqWave_u8;
	while(1)
	{
		// setting  p1.16 pin
		IOSET1 |= sqWave_u8;
		// function call to generate 50 micros delay 
		usec_delay(50);
		// clearing p1.16 pin
		IOCLR1 |= sqWave_u8;
		// function call to generate 50 micros delay 
		usec_delay(50);
	}
}

