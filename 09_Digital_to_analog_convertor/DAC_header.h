#include <LPC214X.H>
#include <stdint.h>


void DAC_init(void);                                 // Function to Initializes DAC0            void DAC_writeAnalogData(uint32_t digitalData_u32);  // Function to pass Data to DAC
void usec_delay(uint32_t us_u32);                    // Function to generate delay in micro sec


