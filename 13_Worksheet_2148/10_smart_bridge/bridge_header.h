#include <LPC214X.H>
#include <stdint.h>

/* defined macro for LED1 */
#define LED1 (1<<17)
/* defined macro for LED2 */
#define LED2 (1<<18)

/* defined macro for transmitter holding register empty  */
#define THRE_U8 ((U0LSR>>5)&1)
/* defined macro for receiver data ready */
#define RDR_U8  (U0LSR&1)

/* defined macro for Register select pin of LCD */
#define RS (1<<17)
/* defined macro for Read/write pin of LCD  */
#define RW (1<<18)
/* defined macro for Enable pin of LCD */
#define EN (1<<19)
/* defined macro for DONE flag */
#define DONE_U8 ((AD0GDR>>31)&1)
/* defined macro for Switch */
#define sw ((IOPIN0>>14)&1)

//========================== UART ==========================

void uart_init(uint16_t );            			 // Function to Initializes uart 0
void uart_charTransmit(uint8_t);             // Fucntion to Transmit char via uart0
uint8_t uart_charReceive(void);              // Fucntion to Receive char via uart0
void uart_stringTransmit(uint8_t *);				 // Fucntion to Transmit string via uart0
void uart_stringReceive(uint8_t *,uint8_t);  // Fucntion to Receive string via uart0

//========================== DELAY ==========================

void ms_delay(int ms);// Function To generate dealy using time0

//========================== LCD ==========================

void lcd_init(void);// Function To init lcd 
void lcd_cmd(unsigned char data);// Function To send command on LCD
void lcd_data(unsigned char data);// Function To send data on LCD
void lcd_str(char *p);// Function To send string on LCD

//========================== ADC ==========================

void adc_init(void);  // Function to Initializes ADC
uint16_t adc0_read_data(uint8_t chNo_u8);  // Fucntion to Receive data from ADC




