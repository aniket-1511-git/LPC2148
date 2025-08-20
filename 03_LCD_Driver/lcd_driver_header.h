#include <LPC214X.H>
/* Macro defined for Registe select pin of LCD */
#define RS 1<<8
/* Macro defined for Read write pin of LCD */
#define RW 1<<9
/* Macro defined for Enable pin of LCD */
#define EN 1<<10

void lcd_init_8bit(void);               // Function to initialize LCD
void lcd_cmd_8bit(unsigned char cmd);   // Function to write Command on LCD
void lcd_data_8bit(unsigned char data); // Function to write Data on LCD
void lcd_string_8bit(char *p);          // Function to write String on LCD

void ms_delay(unsigned int ms);         // Function to generate delay

