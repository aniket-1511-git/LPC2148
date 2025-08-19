#include <LPC214X.H>
#include <stdint.h>

#define LED_u8 0Xf
#define LED1_u8 1<<0
#define LED2_u8 1<<1
#define LED3_u8 1<<2
#define LED4_u8 1<<3

void sec_delay(uint32_t sec_u32);
