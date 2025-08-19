#include <LPC214X.H>
#include <stdint.h>

//=================== Macros ===================
/* defined macro for transmitter holding register empty  */
#define THRE_U8 ((U0LSR>>5)&1)
/* defined macro for receiver data ready */
#define RDR_U8  (U0LSR&1)
/* defined macro for ADC data  */
#define DONE_U8 ((AD0GDR>>31)&1)
/* defined macro for Register select pin of LCD */
#define RS (1<<17)
/* defined macro for read write pin of LCD */
#define RW (1<<18)
/* defined macro for Enable pin of LCD */
#define EN (1<<19)

//=================== LCD Function prototype ===================

void lcd_data(unsigned char data);
void lcd_cmd(unsigned char data);
void lcd_init(void);
void lcd_str(char *p);
void lcd_intNo(int no);

//=================== delay Function prototype ===================

void ms_delay(int ms);

//=================== UART Function prototype ===================

void uart_init(uint16_t );            	  
void uart_charTransmit(uint8_t);          
uint8_t uart_charReceive(void);           
void uart_stringTransmit(uint8_t *);	    
void uart_stringReceive(uint8_t *,uint8_t);

//=================== UART Function prototype ===================
void adc_init(void);
uint16_t adc0_read_data(uint8_t chNo_u8);
