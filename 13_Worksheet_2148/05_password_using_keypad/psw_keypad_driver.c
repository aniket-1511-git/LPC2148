#include "pws_header.h"
uint8_t psw_keyPad(void)
{
	uint8_t key;
	IODIR0 |= row1|row2|row3|row4;
	
	while(1)
	{
		
	  IOCLR0 |= row1|row2|row3|row4;	
		IOSET0 |= col1|col2|col3|col4;
		/********row 1 ******/
		IOCLR0 |= row1;
		IOSET0 |= (row2|row3|row4);
		if((IOPIN0&col1) == 0)
		{
			key ='7';
			ms_delay(10);
			return key;
		}
	
	if((IOPIN0&col2) == 0)
		{
			key ='8';
			ms_delay(2);
			return key;
		}
		if((IOPIN0&col3) == 0)
		{
			key ='9';
			ms_delay(2);
			return key;
		}
	
	if((IOPIN0&col4) == 0)
		{
			key ='/';
			ms_delay(2);
			return key;
		}
		/********row 2 ******/
		
		IOCLR0 |= row2;
		IOSET0 |= (row1|row3|row4);
		if((IOPIN0&col1) == 0)
		{
			key ='4';
			ms_delay(2);
			return key;
		}
	
	if((IOPIN0&col2) == 0)
		{
			key ='5';
			ms_delay(2);
			return key;
		}
		if((IOPIN0&col3) == 0)
		{
			key ='6';
			ms_delay(2);
			return key;
		}
	
	if((IOPIN0&col4) == 0)
		{
			key ='*';
			ms_delay(2);
			return key;
		}
		
		/********row 3 ******/
		
		IOCLR0 |= row3;
		IOSET0 |= (row1|row2|row4);
		if((IOPIN0&col1) == 0)
		{
			key ='1';
			ms_delay(2);
			return key;
		}
	
	if((IOPIN0&col2) == 0)
		{
			key ='2';
			ms_delay(2);
			return key;
		}
		if((IOPIN0&col3) == 0)
		{
			key ='3';
			ms_delay(2);
			return key;
		}
	
	if((IOPIN0&col4) == 0)
		{
			key ='-';
			ms_delay(2);
			return key;
		}
		/********row 4 ******/
		
		IOCLR0 |= row4;
		IOSET0 |= (row1|row3|row2);
		if((IOPIN0&col1) == 0)
		{
			lcd_cmd(0x01);
			lcd_cmd(0x80);
			break;
		}
	
	if((IOPIN0&col2) == 0)
		{
			key ='0';
			ms_delay(10);
			return key;
		}
		if((IOPIN0&col3) == 0)
		{
			key ='=';
			ms_delay(2);
			return key;
		}
	
	if((IOPIN0&col4) == 0)
		{
			key ='+';
			ms_delay(2);
			return key;
		}	
	}
}


