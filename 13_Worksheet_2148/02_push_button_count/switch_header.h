#include <LPC214X.H>

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

