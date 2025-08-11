#include <LPC214X.H>
#define set 1
#define clr 1

void delay(unsigned int ms);

void pinWrite(int pinNo, int pinVal);

void portWrite(int portNo, unsigned char portVal);

int pinRead(int pinNo);