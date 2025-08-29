#include <LPC214X.H>

/* defined macro for Register select pin of LCD */
#define RS (1<<17)
/* defined macro for read write pin of LCD */
#define RW (1<<18)
/* defined macro for Enable pin of LCD */
#define EN (1<<19)

/* defined macro for Switch  */
#define sw1 ((IOPIN0>>14)&1)

void lcd_data(unsigned char data);    // Function to send char on LCD
void lcd_cmd(unsigned char data);   // Function to Send command on LCD
void lcd_init(void);   // Function to  Init LCD
void lcd_str(char *p);   // Function to send String on LCD
void lcd_intNo(int no);   // Function to send integer no  on LCD

void ms_delay(int ms);   // Function to generate delay

