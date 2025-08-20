#include "ext_int_header.h"
int8_t count_8;
/*
* Function name      : void ext_int0_isr(void)__irq
* Description        : this function ISR of External interrupt 0
*/
void ext_int0_isr(void)__irq
{
	IODIR0 |=  LED1_u8;
	// toggle  varriable to on / off led1
	count_8 ^=1;
	if(count_8)
	{
		// on led 1
		IOSET0 |= LED1_u8;
	}
	else 
	{
		// Off led 1
		IOCLR0 |= LED1_u8;
	}
	// clear external interrupt0  
	EXTINT =0x1;
	// End of external interrupt0 ISR
	VICVectAddr = 0;
}

/*
* Function name      : void ext_Int_config(void)
* Description        : this function to vic Configure external interrupt0                            
*/
void ext_Int_config(void)
{
	
	VICIntSelect = 0;
	// Enable Ext int 0
  	VICIntEnable |= (1<<14);	
	// To enable vectored IRQ slot
	VICVectCntl0 |=14|(1<<5);
	// pointer interrupt function (ISR)
	VICVectAddr0 =(uint32_t)ext_int0_isr;
	 
}
/*
* Function name      : void config_extint0()
* Description        : this function to Configure external interrupt0                            
*/
void config_extint0(void)
{
	// Select p0.16 ext interrupt 0
	PINSEL1 |= 0x01;
	// setting Edge sensitive for ext_int0
	EXTMODE =0x1;
	// setting falling edge for ext_int0
	EXTPOLAR = 0x00;
}





