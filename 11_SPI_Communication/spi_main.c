#include "spi_header.h"

int main()
{
	// Varriable to store adc output and volt voltage
	uint32_t spiOutput,volt;
	// Function call to Initializes SPI 
	spi_init_master();
	// Function call to Initializes UART
	uart_init(9600);
	while(1U)
	{
    // Function call to Read data form external adc 		
		spiOutput = spi0_exxtAdc('0');
		// adc value in voltage conversion formula
		volt = (spiOutput*3.3/1024);
		// Function call to display message on uart
		uart_stringTransmit("ADC Voltage : ");
		// Function call to display voltage on uart
		uart_intT0string(volt);
		// Function call for new line
		uart_stringTransmit("\r\n");
	}
}



