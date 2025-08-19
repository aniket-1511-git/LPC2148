#include "led_header.h"

/*
* Function name      : void msec_delay(uint32_t ms_u32)
* Description        : this function generate the delay in milliseconds
*                      
*/
void msec_delay(uint32_t ms_u32)
{
	
	// Array storing possible Peripheral Clock (PCLK) values in MHz
	int32_t vpbdiv[] = {15,60,30,15};
	// Set the mode as Timer
	T0CTCR = 0;
	// store max time based on VPBDIV setting
	T0PR = vpbdiv[VPBDIV]*1000-1;
	// Clear timer 
	T0TC = 0;
	// start timer 
	T0TCR = 1;
	// Wait untill t0tc value reaches  ms_u32
	while(T0TC<ms_u32);
	// stop timer 
	T0TCR = 0 ;	
}
/*
* Function name      : void sec_delay(uint32_t sec_u32)
* Description        : this function generate the delay in seconds
*                      
*/
void sec_delay(uint32_t sec_u32)
{
	// Array storing possible Peripheral Clock (PCLK) values in MHz
	int32_t vpbdiv[] = {15,60,30,15};
	// Set the mode as Timer
	T0CTCR = 0;
	// store max time based on VPBDIV setting
	T0PR = vpbdiv[VPBDIV]*1000000-1;
	// Clear timer 
	T0TC = 0;
	// start timer 
	T0TCR = 1;
	// Wait untill t0tc value reaches  sec_u32
	while(T0TC<sec_u32);
	// stop timer 
	T0TCR = 0 ;
}
/*
* Function name      : void usec_delay(uint32_t us_u32)
* Description        : this function generate the delay in microseconds
*                      
*/
void usec_delay(uint32_t us_u32)
{
	// Array storing possible Peripheral Clock (PCLK) values in MHz
	int32_t vpbdiv[] = {15,60,30,15};
	// Set the mode as Timer
	T0CTCR = 0;
	// store max time based on VPBDIV setting
	T0PR = vpbdiv[VPBDIV]-1;
	// Clear timer 
	T0TC = 0;
	// start timer 
	T0TCR = 1;
	// Wait untill t0tc value reaches  us_u32
	while(T0TC<us_u32);
	// stop timer 
	T0TCR = 0 ;
}

