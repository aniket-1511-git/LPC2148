#include"adc_header.h"
/*
* Function name      : int main(void)
* Description        : this function read the adc data and send it to UART 0
*                             
*/
int main(void)
{
	// varriable to store Adc value
	uint16_t adc_data=0;
	// Function call to init uart 0
	uart_init(9600);
	// Function call to init Adc
	adc_init();
	while(1U)
	{
		// function call to read data from adc channel 1 and store it in varriable
		adc_data = adc0_read_data('1');
		// Function call to send message on uart 
		uart_stringTransmit("ADC Value :- ");
		// Function call to send integer num 
		uart_intT0string(adc_data);
		// function call for new line
		uart_stringTransmit("\r\n");
	}
}

