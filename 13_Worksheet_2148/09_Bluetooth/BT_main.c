#include "BT_Header.h"
/* 
* Function name     : int main(void)
* Description       : this function Reads a command from UART0 and control the LED and display status 
*                     on the serial terminal. 
*/
int main(void)
{
	// Varriable to store a command from UART0
	uint8_t cmd;
	// Setting direction as a output
	IODIR0 |= LED_u8;
	// Function call to Initializes uart 0
	uart_init(9600);
	
	while(1u)
	{
		// Function call to display message on serial terminal of uart
		uart_stringTransmit("Enter Command\n\r a. ON LED1 b. OFF LED1 \n\r c. ON LED2 d. OFF LED2 \r\n");
		
		// Function call to receive a command from UART0 and storing in local varriable
		cmd = uart_charReceive();
		// checking received command operating LED's status
		switch(cmd)
		{
			case 'a':
				// LED1 ON State
			  IOSET0 |= LED1_U8;
			  // Function call to display LED 1 On state
			  uart_stringTransmit("LED1 ON\r\n");
				break;
			case 'c':
				// LED2 ON State
			  IOSET0 |= LED2_U8;
			  // Function call to display LED 2 On state
			  uart_stringTransmit("LED2 ON\r\n");
				break;
			case 'b':
				// LED1 OFF State
			  IOCLR0 |= LED1_U8;
			  // Function call to display LED 1 Off state
			  uart_stringTransmit("LED1 OFF\r\n");
				break;
			case 'd':
				// LED2 OFF State
			  IOCLR0 |= LED2_U8;
			  // Function call to display LED 2 Off state
			  uart_stringTransmit("LED2 OFF\r\n");
				break;
			default:
				//LED 1 and LED2 OFF State
				IOCLR0 |= LED_u8;
			  // Function call to display LED1 and LED 2 Off state
			  uart_stringTransmit("LED1 AND LED2 OFF\r\n");
				break;
		}
	}
	
}

