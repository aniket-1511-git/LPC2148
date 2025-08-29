#include <LPC214X.H>
#include <stdint.h>
/*Macro defined for LCD RS pin*/
#define RS (1<<17)
/*Macro defined for LCD RW pin */
#define RW (1<<18)
/*Macro defined for LCD EN pin */
#define EN (1<<19)
/*Macro defined for UART 0 THRE flag*/
#define THRE_U8 ((U0LSR>>5)&1)
/*Macro defined for I2C SI flag*/
#define SI ((I2C0CONSET>>3)&1)
// structure to store RTC values
typedef struct rtc
{
	uint8_t sec_u8;
	uint8_t min_u8;
	uint8_t hour_u8;
	uint8_t day_u8;
	uint8_t month_u8;
	uint8_t year_u8;
}clock;

//========================== I2C ==========================

void i2c_init(void);                                                      // Function To init I2C
void i2c_byteWriteFrame(uint8_t sa_u8, uint8_t mrAddr_u8,uint8_t data_u8); // Function To write frame for I2C
uint8_t  i2c_byteReadFrame(uint8_t sa_u8, uint8_t mrAddr_u8); // Function To read frame for I2C

//========================== DELAY ==========================

void ms_delay(int ms);// Function To generate dealy using time0

//========================== LCD ==========================

void lcd_init(void);// Function To init lcd 
void lcd_cmd(unsigned char data);// Function To send command on LCD
void lcd_data(unsigned char data);// Function To send data on LCD
void lcd_str(char *p);// Function To send string on LCD

