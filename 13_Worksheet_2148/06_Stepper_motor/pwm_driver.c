#include "pwm_header.h"
void pwm_init(void)
{
	PINSEL0 |= (PINSEL0 &~(1<<16))|(1<<17);
	
	PWMPCR = 0x0;
	PWMPR  = 60-1;
	PWMMR0 = 10000;
	PWMMR4 = 500;
	PWMMCR = 1<<1;
	PWMLER = (1<<0)|(1<<4);
	PWMPCR = (1<<12);
	PWMTCR = (1<<1);
	PWMTCR = (1<<0)|(1<<3);	
	
}

