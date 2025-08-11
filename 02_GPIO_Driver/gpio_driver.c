#include <LPC214X.H>
#define set 1
#define clr 1

void delay(unsigned int ms)
{
	for(unsigned int i=0;i<ms;i++);
}

void pinWrite(int pinNo, int pinVal)
{
	
	// if pinNo is in between 0 to 31 then PORT 0
	if(0<= pinNo && 31>= pinNo)
	{
		IODIR0 |= set <<pinNo;
		
		// if pinVal is 0 then clear pin 
		if(0 == pinVal)
		{
			IOCLR0 |= clr <<pinNo;
		}
		// if pinVal is 1 then set pin 
		else if (1 == pinVal)
		{
			IOSET0 |= set <<pinNo;
		}
	}
	// if pinNo is in between 100 to 131 then PORT 1
	else if(100<= pinNo && 131>= pinNo)
	{
		
		pinNo -= 100;
		if(16<= pinNo && 31>=pinNo)
		{
			IODIR1 |= set <<pinNo;
			// if pinVal is 0 then clear pin 
			if(0 == pinVal)
			{
				IOCLR1 |= clr <<pinNo;
			}
			// if pinVal is 1 then set pin 
			else if (1 == pinVal)
			{
				IOSET1 |= set <<pinNo;
			}
		}
	}
}

void portWrite(int portNo, unsigned char portVal)
{
	int i;
	if(0 <= portNo && 9>= portNo)
	{
		if(0 == portNo)
		{
			for(i=0; i<8;i++)
			{
				if(portVal>>i&1)
				{
					pinWrite(i,1);
				}
				else
				{
					pinWrite(i,0);
				}
			}
		}
		else if(1== portNo)
		{
			for(i=0; i<8;i++)
			{
				if(portVal>>i&1)
				{
					pinWrite(8+i,1);
				}
				else
				{
					pinWrite(8+i,0);
				}
			}
		}
		else if(2== portNo)
		{
			for(i=0; i<8;i++)
			{
				if(portVal>>i&1)
				{
					pinWrite(16+i,1);
				}
				else
				{
					pinWrite(16+i,0);
				}
			}
		}
		else if(3== portNo)
		{
			for(i=0; i<8;i++)
			{
				if(portVal>>i&1)
				{
					pinWrite(24+i,1);
				}
				else
				{
					pinWrite(24+i,0);
				}
			}
		}
		else
		{
			
		}
	}
	else if(10 <= portNo && 19>= portNo)
	{
		if(12== portNo)
		{
			for(i=0; i<8;i++)
			{
				if(portVal>>i&1)
				{
					pinWrite(116+i,1);
				}
				else
				{
					pinWrite(116+i,0);
				}
			}
		}
		else if(13== portNo)
		{
			for(i=0; i<8;i++)
			{
				if(portVal>>i&1)
				{
					pinWrite(124+i,1);
				}
				else
				{
					pinWrite(124+i,0);
				}
			}
		}
		else 
		{
		}
	}
}

int pinRead(int pinNo)
{
	if(0<= pinNo && 31>= pinNo)
	{
		IODIR0&=~(1<<pinNo);
		return IOPIN0>>pinNo&1;
	}
	else if(100<= pinNo && 131>= pinNo)
	{
			pinNo -= 100;
			if(16<= pinNo && 31>=pinNo)
			{
				IODIR1&=~(1<<pinNo);
				return IOPIN1>>pinNo&1;
			}
	}		
}

