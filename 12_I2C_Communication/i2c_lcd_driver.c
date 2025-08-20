#include "I2C_header.h"

/*
* Function Name : void ms_delay(int ms)
* Description   : This Function generate delay in milisec 
*                 
*/
void ms_delay(int ms)
{
	// Array clkDiv holds clock division and 'p' will store calculated prescale value
	unsigned int clkDiv[]={15,60,30,15,15},p;
	// Formulae to get pclk value
	p=clkDiv[VPBDIV]*1000;
	//	Reset Timer0 Counter Register to 0
	T0TC=0;
	// Reset Timer0 Prescale Counter to 0
	T0PC=0;
	// Set Prescale Register to calculated value - 1
	T0PR=p-1;
	// Start timer 
	T0TCR=1;
	// Wait until Timer Counter reaches the desired millisecond delay
	while(T0TC<ms);
	// Stop timer
	T0TCR=0;
}
/*
* Function Name : void lcd_data(unsigned char data)
* Description   : This Function used to pass data on lcd display 
*                 
*/
void lcd_data(unsigned char data)
	{
	 // Clear data lines P1.17 to P1.23
	IOCLR1=0xFE0000;
	// Send higher nibble of data 
	IOSET1=(data&0xF0)<<16;
	// Set Register Select line
	IOSET1=RS;
	// Clear Read/Write line	
	IOCLR1=RW;
	// Set Enable line
	IOSET1=EN;
	// Function call to provide short delay	
	ms_delay(2);
	// Clear EN line 
	IOCLR1=EN;
	// Clear data lines P1.17 to P1.23
	IOCLR1=0xFE0000;
	// Send lowwer nibble of data
	IOSET1=(data&0xF)<<20;
	// Set Register Select line	
	IOSET1=RS;
	// Clear Read/Write line	
	IOCLR1=RW;
	// Set Enable line
	IOSET1=EN;
	// Function call to provide short delay
	ms_delay(2);
	// Clear EN line 
	IOCLR1=EN;
	
}
/*
* Function Name : void lcd_cmd(unsigned char data)
* Description   : This Function used to pass command on lcd display 
*                 
*/
void lcd_cmd(unsigned char data)
{
	// Clear data lines P1.17 to P1.23
	IOCLR1=0xFE0000;
	// Send higher nibble of command		
	IOSET1=(data&0xF0)<<16;
	// Clear Register Select line	
	IOCLR1=RS;
	// Clear Read/Write line	
	IOCLR1=RW;
	// Set Enable line	
	IOSET1=EN;
	// Function call to provide short delay	
	ms_delay(2);
	// Clear EN line	
	IOCLR1=EN;
	// Clear data lines P1.17 to P1.23
	IOCLR1=0xFE0000;
	// Send lowwer nibble of command	
	IOSET1=(data&0xF)<<20;
	// Clear Register Select line	
	IOCLR1=RS;
	// Clear Read/Write line	
	IOCLR1=RW;
	// Set Enable line	
	IOSET1=EN;
	// Function call to provide short delay	
	ms_delay(2);
	// Clear EN line	
	IOCLR1=EN;
}
/*
* Function Name : void lcd_init(void)
* Description   : This Function used to Initialize lcd
*                 
*/
void lcd_init(void)
{
	// Set P1.17 to P1.23 as output 
	IODIR1|=0xFE0000;
	// Set pins in GPIO mode
	PINSEL2|=0x0;
	// Function call to Initialize LCD in 4-bit mode
	lcd_cmd(0x02);
	// Function call to enable single line
	lcd_cmd(0x03);
	// Function call to on Display and Cursor
	lcd_cmd(0x0E);
	// Function call to enable double line in 4 bit mode
	lcd_cmd(0x28);
	// Clear display
	lcd_cmd(0x01);
}
/*
* Function Name : void lcd_str(char *p)
* Description   : This Function used to send string on lcd
*                 
*/
void lcd_str(char *p)
{
	// loop iterate till valid characters in string
	while(*p){
		// Function call to display character form string
		lcd_data(*p);
		// pointer increment
		p++;
	}
}
