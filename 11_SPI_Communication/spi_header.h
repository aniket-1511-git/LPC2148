#include <LPC214X.H>
#include <stdint.h>

#define CS_U8 (1<<7)
#define SPIF_U8 ((S0SPSR>>7)&1)

#define THRE_U8 ((U0LSR>>5)&1)


uint32_t spi0_exxtAdc(uint8_t chNo_U8);
uint8_t SPI0_read_write(uint8_t data_u8);
void spi_init_master(void);

void uart_init(uint16_t brate_u16);
void uart_charTransmit(uint8_t data_u8);
void uart_stringTransmit(uint8_t *stringData_u8);
void uart_intT0string(int32_t num_32);
