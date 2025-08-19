#include "pwm_header.h"

int main()
{
	pwm_init();
	while(1U)
	{
		PWMMR4 = 2500;
		PWMLER = (1<<4);
		PWMMR4 = 5000;
		PWMLER = (1<<4);
		PWMMR4 = 7500;
		PWMLER = (1<<4);
		PWMMR4 = 10000;
		PWMLER = (1<<4);
		PWMMR4 = 12500;
		PWMLER = (1<<4);
		
	}
}

