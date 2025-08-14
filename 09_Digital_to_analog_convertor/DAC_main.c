#include "DAC_header.h"

/*
* Function name      : int main(void)
* Description        : this function to generate sawtooth Wave                            
*/


int main(void)
{
	// Varriable to pass digital data to DAC
	uint32_t digital_data;
	// function call to init DAC
	DAC_init();
	while(1U)
	{
   /************************* Sawtooth Wave *************************/
		/*
		for(digital_data = 0; digital_data<100 ;digital_data++ )
		{
			// Function call to send Digital data
			DAC_writeAnalogData(digital_data*10);
			// Function Call to generate delay 200 micro SEC]
			usec_delay(200);
		}
		*/
		/************************* Tringle Wave *************************/
		/*
		for(digital_data = 0; digital_data<50 ;digital_data++ )
		{
			// Function call to send Digital data
			DAC_writeAnalogData(digital_data*20);
			// Function Call to generate delay 200 micro SEC]
			usec_delay(200);
		}
		for(digital_data = 0; digital_data<50 ;digital_data++ )
		{
			// Function call to send Digital data
			DAC_writeAnalogData(1000-(digital_data*20));
			// Function Call to generate delay 200 micro SEC]
			usec_delay(200);
		}
		*/
		/************************* Square Wave *************************/
			// Function call to send max voltage
			DAC_writeAnalogData(1023);
			// Function Call to generate delay 200 micro SEC]
			usec_delay(200);
			// Function call to send min voltage
			DAC_writeAnalogData(0);
			// Function Call to generate delay 200 micro SEC]
			usec_delay(200);
		
	}
		
}

