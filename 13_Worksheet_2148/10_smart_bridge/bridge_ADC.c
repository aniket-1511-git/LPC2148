#include "bridge_Header.h"
/*
* Function name      : void uart_init(uint16_t brate_u16)
* Description        : this function Initializes ADC0
*                             
*/
void adc_init(void)
{
	  // enabled ADC0 channel 1,2,3
		PINSEL1 |= 0x15400000;
	  // configuration of ADC0
	  AD0CR   |= 0x200400;
}
/*
* Function name      : uint16_t adc0_read_data(uint8_t chNo_u8)
* Description        : this function read the adc data and return it
*                             
*/
uint16_t adc0_read_data(uint8_t chNo_u8)
{
	//Varriable to store adc value
	uint16_t adcRes = 0;
	// Selecting channel
	AD0CR |= (1<<chNo_u8);
	// ADC start
	AD0CR |= (1<<24);
	// Waiting untill data convertion
	while(DONE_U8 ==0);
	// storing adc conveted data
	adcRes = ((AD0GDR>>6)&0x3FF);
	// ADC stop
	AD0CR ^= (1<<24);
	// channel Deselection
	AD0CR ^= (1<<chNo_u8);
	// return adc converted result
	return adcRes;
}




