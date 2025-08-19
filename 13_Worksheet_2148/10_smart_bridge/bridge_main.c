#include "bridge_Header.h"

int main()
{
	uint16_t temp,adcCount;
	IODIR0 |= LED1|LED2;
	uart_init(9600);
	adc_init();
	lcd_init();
	while(1U)
	{
		lcd_cmd(0x80);
		adcCount = adc0_read_data('0');
		temp = (((adcCount * 3.3)/1024)*100);
		lcd_str("Temp : ");
		lcd_intNo(temp);
		if(temp > 15)
		{
			uart_stringTransmit("Temperature Above Threshold Value\r\n");
			IOSET0 = LED2;
			IOCLR0 = LED1;
		}
		else
		{
			uart_stringTransmit("Temperature Below Threshold Value\r\n");
			IOSET0 = LED1;
			IOCLR0 = LED2;
		}
		if(sw == 0)
		{
			while(sw == 0);
			lcd_cmd(0xC0);
			lcd_str("Motion Detected");
		}
//	  lcd_cmd(0x01);
		ms_delay(100);
	}
}



