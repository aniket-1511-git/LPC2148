#include <LPC214X.H>
#include <stdint.h>
/* Macro defined of THRE Flag of UART */
#define THRE_U8 ((U0LSR>>5)&1)
/* Macro defined of SI Flag of I2C */
#define SI ((I2C0CONSET>>3)&1)
/* Macro defined for Registe select pin of LCD */
#define RS (1<<17)
/* Macro defined for Read write pin of LCD */
#define RW (1<<18)
/* Macro defined for Enable pin of LCD */
#define EN (1<<19)
/*Structure to store the RTC values */
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

void i2c_init(void); // Function to  init I2C0                                             
void i2c_byteWriteFrame(uint8_t sa_u8, uint8_t mrAddr_u8,uint8_t data_u8);// Function to I2C Write frame
uint8_t  i2c_byteReadFrame(uint8_t sa_u8, uint8_t mrAddr_u8);// Function to I2C Read frame

//========================== DELAY ==========================

void ms_delay(int ms); // Function to timer delay generation 

//========================== LCD ==========================



void lcd_init(void);             // Function to initialize LCD
void lcd_cmd(unsigned char data);// Function to Send Command on LCD
void lcd_data(unsigned char data);// Function to Send Data on LCD
void lcd_str(char *p);// Function to Send String on LCD








