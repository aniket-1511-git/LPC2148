#include "temp_header.h"
/*
* Function Name :int main(void)
* Description   : This function read the analog data and display on LCD
*/
int main(void)
{
	// Varriable to store adc value and temperatur
	uint16_t adcValue,temp;
	// LCD init
	lcd_init();
	// UART init 
	uart_init(9600);
	// ADC init
	adc_init();
	while(1U)
	{
		// Send command to start form 1st line of LCD
		lcd_cmd(0x80);
		// Read and store data form ADC
		adcValue = adc0_read_data('0');
		// ADC value to temperature conversion formula
		temp = ((adcValue *3.3)/1024)*100;
		// Send message to LCD
		lcd_str("Temp : ");
		lcd_intNo(temp);
		lcd_str(" 'c");
	}
	
}

