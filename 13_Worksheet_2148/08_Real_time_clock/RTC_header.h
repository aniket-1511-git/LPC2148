#include <LPC214X.H>
#include <stdint.h>

#define THRE_U8 ((U0LSR>>5)&1)
#define SI ((I2C0CONSET>>3)&1)

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

void i2c_init(void);
void i2c_byteWriteFrame(uint8_t sa_u8, uint8_t mrAddr_u8,uint8_t data_u8);
uint8_t  i2c_byteReadFrame(uint8_t sa_u8, uint8_t mrAddr_u8);

//========================== DELAY ==========================

void ms_delay(int ms);

//========================== LCD ==========================

#define RS (1<<17)
#define RW (1<<18)
#define EN (1<<19)

void lcd_init(void);
void lcd_cmd(unsigned char data);
void lcd_data(unsigned char data);
void lcd_str(char *p);