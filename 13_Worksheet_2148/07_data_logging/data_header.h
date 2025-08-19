#include <LPC214X.H>
#include <stdint.h>
/* defined macro for chip select pin of SPI*/
#define CS_U8 (1<<7)
/* defined macro for SPIF flag */
#define SPIF_U8 ((S0SPSR>>7)&1) 
/* defined macro for Register select pin of LCD */
#define RS (1<<17)
/* defined macro for read write pin of LCD */
#define RW (1<<18)
/* defined macro for Enable pin of LCD */
#define EN (1<<19)

uint8_t SPI0_read_write(uint8_t data_u8);
void spi_init_master(void);

void ms_delay(int ms);

void lcd_data(unsigned char data);
void lcd_cmd(unsigned char data);
void lcd_init(void);
void lcd_str(char *p);
void lcd_intNo(int no);

void sd_enableWrite(void);
void sd_disableWrite(void);
uint8_t sd_dataRead(uint8_t mr);
void sd_dataWrite(uint8_t mr, uint8_t data);

