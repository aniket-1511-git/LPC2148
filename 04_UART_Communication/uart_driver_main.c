#include"uart_header.h"

/* 
* Function name     : int main(void)
* Description       : this function Reads a string from UART0 and again send it back 
*                     to the serial terminal. 
*/
int main(void)
{
	// Varriable to store a string from UART0
	uint8_t stringData[15];
	// Function call to Initializes uart 0
	uart_init(9600);
	// Function call to display message on serial terminal of uart
	uart_stringTransmit("Enter string\n\r");
	while(1u)
	{
		// Function call to receive a string from UART0
		uart_stringReceive(stringData,13);
		// Function call to display received string on serial terminal of uart
		uart_stringTransmit(stringData);
	}
	
}
