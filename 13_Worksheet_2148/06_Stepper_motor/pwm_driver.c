#include "pwm_header.h"
/*
* Function Name : void pwm_init(void)
* Description   : This function initializes the PWM module 
*                
*/
void pwm_init(void)
{
    // Configure P0.8 pin for PWM4 function
    PINSEL0 |= (PINSEL0 & ~(1<<16)) | (1<<17);

    // Disable all PWM outputs 
    PWMPCR = 0x0;

    // Set PWM prescaler: 
    PWMPR  = 60 - 1;

    // Set PWM period using Match Register 0
    PWMMR0 = 10000;

    // Set duty cycle using Match Register 4
    PWMMR4 = 500;

    // Reset TC when MR0 matches 
    PWMMCR = 1 << 1;

    // Enable latch so that MR0 and MR4 values take effect
    PWMLER = (1 << 0) | (1 << 4);

    // Enable PWM output on channel 4 
    PWMPCR = (1 << 12);

    // Reset PWM Timer Counter and Prescale Counter
    PWMTCR = (1 << 1);

    // Enable PWM & Counter 
    PWMTCR = (1 << 0) | (1 << 3);
}

