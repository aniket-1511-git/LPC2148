#include <LPC214X.H>
#include <stdint.h>


/* Defined macro for led 1*/
#define LED1_u8  (1<<1)
/* Defined macro for led 2*/
#define LED2_u8  (1<<0)


void ext_Int_config(void); // Function to config ext_int0
void ms_delay(uint32_t sec_u32); // Function to genrate delay in sec
void config_extint0(void);

