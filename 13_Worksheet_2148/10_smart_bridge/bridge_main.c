#include "bridge_Header.h"

int main()
{
	uint16_t temp,adcCount;
	 // Configure LED pins as output
	IODIR0 |= LED1|LED2;
	 // Initialize UART 
	uart_init(9600);
	// Initialize ADC 
	adc_init();
	// Initialize  LCD
	lcd_init();
	while(1U)
	{
		 // Set LCD cursor to first line
		lcd_cmd(0x80);
		// Read ADC0 channel-0
		adcCount = adc0_read_data('0');
		// Convert ADC to temperature 
		temp = (((adcCount * 3.3)/1024)*100);
		 // Display temperature value
		lcd_str("Temp : ");
		lcd_intNo(temp);
		// check If temperature exceeds threshold
		if(temp > 15)
		{	
			uart_stringTransmit("Temperature Above Threshold Value\r\n");
			// Turn ON LED2
			IOSET0 = LED2;
			// Turn OFF LED1
			IOCLR0 = LED1;
		}
		else
		{
			uart_stringTransmit("Temperature Below Threshold Value\r\n");
			// Turn ON LED1
			IOSET0 = LED1;
			// Turn OFF LED2
			IOCLR0 = LED2;
		}
		// If motion detected
		if(sw == 0)
		{
			while(sw == 0);
			// Move cursor to 2nd line
			lcd_cmd(0xC0);
			// Display Message
			lcd_str("Motion Detected");
		}
		ms_delay(100);
	}
}



