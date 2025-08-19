#include "ext_int_header.h"
/*
* Function name      : void sec_delay(uint32_t sec_u32)
* Description        : this function generate the delay in miliseconds
*                      
*/
void ms_delay(uint32_t sec_u32)
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
	// Wait untill t0tc value reaches  sec_u32
	while(T0TC<sec_u32);
	// stop timer 
	T0TCR = 0 ;
}





