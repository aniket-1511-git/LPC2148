#include "pwm_header.h"
/*
* Function Name : int main(void)
* Desription    : This function defined to rotate stepper motor
*                  using pwm
*/
int main(void)
{
	// Function call to Initializes PWM
	pwm_init();
	while(1U)
	{
		// Set duty cycle to 25%
		PWMMR4 = 2500;
		PWMLER = (1<<4);
		// Set duty cycle to 50%
		PWMMR4 = 5000;
		PWMLER = (1<<4);
		// Set duty cycle to 75%
		PWMMR4 = 7500;
		PWMLER = (1<<4);
		// Set duty cycle to 100%
		PWMMR4 = 10000;
		PWMLER = (1<<4);
		// Set duty cycle to 125%
		PWMMR4 = 12500;
		PWMLER = (1<<4);
		
	}
}

