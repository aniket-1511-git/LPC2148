#include "I2C_header.h"
/*
* Function name      : int main(void)
* Description        : this function to read the data form RTC and Display on LCD
*/
int main(){
	// Varriable to store time and Date 
	unsigned int h=0,m=0,s=0,d=0,mon=0,y=0,r,wd=0;
	// Array to store Week days
	char week[7][10]={"MON", "TUE", "WED", "THU", "FRI", "SAT","SUN"};
// Function call to Initializes LCD
	lcd_init();
// Function call to Initializes I2C
	i2c_init();
	
//*************************** TIME  ***************************
	// Function call to set hours
	i2c_byteWriteFrame(0xD0,0x2,0x71);//hr
	// Function call to set min
	i2c_byteWriteFrame(0xD0,0x1,0x01);//min
	// Function call to set sec
	i2c_byteWriteFrame(0xD0,0x0,0x1);//sec

//	
	
//*************************** DATE  ***************************
	// Function call to set date
	i2c_byteWriteFrame(0xD0,0x4,0x07);//Date
	// Function call to set month
	i2c_byteWriteFrame(0xD0,0x5,0x07);//Month
	// Function call to set year
	i2c_byteWriteFrame(0xD0,0x6,0x24);//Year


//*************************** DAY  ***************************
	// Function call to set Week days
	i2c_byteWriteFrame(0xD0,0x3,0x07);


	while(1){

		//*************************** TIME  ***************************
		// Function call to read hour
		h=i2c_byteReadFrame(0xD0,0x2);
		// Function call to read min
		m=i2c_byteReadFrame(0xD0,0x1);
		// Function call to read sec
		s=i2c_byteReadFrame(0xD0,0x0);
		r=((h>>5)&1);
		// Function call to set LCD Address
		lcd_cmd(0x80);
		h&=0x1F;
		// Function call to send hour
		lcd_data((h/0x10)+48);
		// Function call to send hour
		lcd_data((h%0x10)+48);
		// Function call to display :
		lcd_data(':');
		// Function call to send min
		lcd_data((m/0x10)+48);
		// Function call to send min
		lcd_data((m%0x10)+48);
		// Function call to display : 
		lcd_data(':');
		// Function call to send sec
		lcd_data((s/0x10)+48);
		// Function call to send sec
		lcd_data((s%0x10)+48);
		// Function call to display space 
		lcd_data(' ');
		if(r==0){
			// Function call to send AM
				lcd_str("AM");
			}
		else{
			// Function call to send PM 
				lcd_str("PM");
		}
		
//*************************** DATE  ***************************	
		
		// Function call to read day
		d=i2c_byteReadFrame(0xD0,0x4);
		// Function call to read month
		mon=i2c_byteReadFrame(0xD0,0x5);
		// Function call to read year
		y=i2c_byteReadFrame(0xD0,0x6);
		// Function call to send second line addr
		lcd_cmd(0xC0);
		// Function call to send day
		lcd_data((d/0x10)+48);
		// Function call to send day
		lcd_data((d%0x10)+48);
		// Function call to display /
		lcd_data('/');

		switch(mon){
			case 1:
			// Function call to send month 
				lcd_str("JAN");
				break;
			case 2:
			// Function call to send month 
				lcd_str("FEB");
				break;
			case 3:
			// Function call to send month 
				lcd_str("MAR");
				break;
			case 4:
			// Function call to send month 
				lcd_str("APR");
				break;
			case 5:
			// Function call to send month 
				lcd_str("MAY");
				break;
			case 6:
			// Function call to send month 
				lcd_str("JUN");
				break;
			case 7:
			// Function call to send month 
				lcd_str("JUL");
				break;
			case 8:
			// Function call to send month 
				lcd_str("AUG");
				break;
			case 9:
			// Function call to send month 
				lcd_str("SEPT");
				break;
			case 10:
			// Function call to send month 
				lcd_str("OCT");
				break;
			case 11:
			// Function call to send month 
				lcd_str("NOV");
				break;
			case 12:
			// Function call to send month 
				lcd_str("DEC");
				break;
			default:
			// Function call to send error message 
				lcd_str("ERR!");
			break;
		}
		// Function call to display /
		lcd_data('/');
		// Function call to send year 
		lcd_data((y/0x10)+48);
		// Function call to send year 
		lcd_data((y%0x10)+48);
		// Function call to 
		lcd_data(' ');
		
		
		//*************************** DAY  ***************************
		
		// Function call to read week day
		wd=i2c_byteReadFrame(0xD0,0x3);
			switch(wd){
							case 0:
							// Function call to send week day
								lcd_str(week[0]);
								break;
							case 1:
							// Function call to send week day
								lcd_str(week[1]);
								break;
							case 2:
							// Function call to send week day
								lcd_str(week[2]);
								break;
							case 3:
							// Function call to send week day
								lcd_str(week[3]);
								break;
							case 4:
							// Function call to send week day
								lcd_str(week[4]);
								break;
							case 5:
							// Function call to send week day
								lcd_str(week[5]);
								break;
							case 7:
							// Function call to send week day
								lcd_str(week[6]);
								break;
			}	
		
	}
}

