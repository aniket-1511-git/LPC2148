#include "temp_header.h"

int main()
{
	uint16_t adcValue,temp;
	lcd_init();
	uart_init(9600);
	adc_init();
	while(1U)
	{
		lcd_cmd(0x80);
		adcValue = adc0_read_data('0');
		temp = ((adcValue *3.3)/1024)*100;
		lcd_str("Temp : ");
		lcd_intNo(temp);
		lcd_str(" 'c");
	}
	
}

