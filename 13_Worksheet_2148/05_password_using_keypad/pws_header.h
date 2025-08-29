#include <LPC214X.H>
#include <stdint.h>
#include <string.h>
/* Macro Defined for column 1*/
#define col1 (1<<0)
/* Macro Defined for column 2*/
#define col2 (1<<1)
/* Macro Defined for column 3*/
#define col3 (1<<2)
/* Macro Defined for column 4*/
#define col4 (1<<3)

/* Macro Defined for Row 1*/
#define row1 (1<<4)
/* Macro Defined for Row 2*/
#define row2 (1<<5)
/* Macro Defined for Row 3*/
#define row3 (1<<6)
/* Macro Defined for Row 4*/
#define row4 (1<<7)

/* defined macro for Register select pin of LCD */
#define RS (1<<17)
/* defined macro for read write pin of LCD */
#define RW (1<<18)
/* defined macro for Enable pin of LCD */
#define EN (1<<19)
/* Macro Defined for Switch */
#define sw1 ((IOPIN0>>14)&1)

void lcd_data(unsigned char data);    // Function to send char on LCD
void lcd_cmd(unsigned char data);   // Function to Send command on LCD
void lcd_init(void);   // Function to  Init LCD
void lcd_str(char *p);   // Function to send String on LCD
void lcd_intNo(int no);   // Function to send integer no  on LCD


void ms_delay(int ms);   // Function to generate delay
uint8_t psw_keyPad(void); // Function to key pad

