#include "DAC_header.h"

/*
* Function name      : void DAC_init(void)
* Description        : this function Initializes DAC0                            
*/
void DAC_init(void)
{
	// Select pin p0.25  as DAC
	PINSEL1 |= 0x80000;
}
/*
* Function name      : void DAC_writeAnalogData(uint32_t digitalData_u32)
* Description        : this function to write digital data in DAC reg
*/
void DAC_writeAnalogData(uint32_t digitalData_u32)
{
	// Store digital data in DACR reg of DAC
	DACR = digitalData_u32 << 6;
}


