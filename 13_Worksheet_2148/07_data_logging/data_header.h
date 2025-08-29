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

uint8_t SPI0_read_write(uint8_t data_u8); // Function To read and write data using SPI
void spi_init_master(void); // Function To SPI init

void ms_delay(int ms);// Function To delay generation 

void lcd_data(unsigned char data);// Function To send data on LCD
void lcd_cmd(unsigned char data);// Function To send Command on LCD
void lcd_init(void);// Function To Init LCD
void lcd_str(char *p);// Function To send String on LCD
void lcd_intNo(int no);// Function To send no on LCD

void sd_enableWrite(void); // Function To enable write operation
void sd_disableWrite(void);// Function To disable write operation
uint8_t sd_dataRead(uint8_t mr);// Function To read data from SD card
void sd_dataWrite(uint8_t mr, uint8_t data);// Function To write data on SD card

