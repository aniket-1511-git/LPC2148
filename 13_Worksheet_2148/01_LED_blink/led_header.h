#include <LPC214X.H>
#include <stdint.h>
/*Macro for LED */
#define LED_u8 0Xf
/*Macro for LED1 */
#define LED1_u8 1<<0
/*Macro for LED2 */
#define LED2_u8 1<<1
/*Macro for LED3 */
#define LED3_u8 1<<2
/*Macro for LED4 */
#define LED4_u8 1<<3

void sec_delay(uint32_t sec_u32); // Function to Delay generation 
