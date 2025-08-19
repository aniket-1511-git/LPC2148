#include <LPC214X.H>
#include <stdint.h>
#include <string.h>

#define col1 (1<<0)
#define col2 (1<<1)
#define col3 (1<<2)
#define col4 (1<<3)

#define row1 (1<<4)
#define row2 (1<<5)
#define row3 (1<<6)
#define row4 (1<<7)

#define RS (1<<17)
#define RW (1<<18)
#define EN (1<<19)

#define sw1 ((IOPIN0>>14)&1)
void lcd_data(unsigned char data);
void lcd_cmd(unsigned char data);
void lcd_init(void);
void lcd_str(char *p);
void lcd_intNo(int no);

void ms_delay(int ms);
uint8_t psw_keyPad(void);

