#include <LPC214X.H>

#define RS 1<<8
#define RW 1<<9
#define EN 1<<10

void lcd_init_8bit(void);
void lcd_cmd_8bit(unsigned char cmd);
void lcd_data_8bit(unsigned char data);
void lcd_string_8bit(char *p);

void ms_delay(unsigned int ms);

