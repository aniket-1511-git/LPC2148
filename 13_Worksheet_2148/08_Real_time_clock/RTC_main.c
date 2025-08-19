#include "RTC_header.h"

int main(){

	clock time;
	clock weekDays;
	uint8_t r;
	char week[7][10]={"MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY","SUNDAY"};
	lcd_init();
	i2c_init();
	
//*************************** TIME  ***************************
	
	i2c_byteWriteFrame(0xD0,0x2,0x70);//hr
	i2c_byteWriteFrame(0xD0,0x1,0x45);//min
	i2c_byteWriteFrame(0xD0,0x0,0x10);//sec

//*************************** DAY  ***************************
	
	i2c_byteWriteFrame(0xD0,0x3,0x07);
	while(1){

		//*************************** TIME  ***************************
		time.hour_u8 = i2c_byteReadFrame(0xD0,0x2);
	  time.min_u8	= i2c_byteReadFrame(0xD0,0x1);
		time.sec_u8 =i2c_byteReadFrame(0xD0,0x0);
		r =((time.hour_u8>>5)&1);
		lcd_cmd(0x80);
		time.hour_u8&=0x1F;
		lcd_data((time.hour_u8/0x10)+48);
		lcd_data((time.hour_u8%0x10)+48);
		lcd_data(':');
		lcd_data((time.min_u8/0x10)+48);
		lcd_data((time.min_u8%0x10)+48);
		lcd_data(':');
		lcd_data((time.sec_u8/0x10)+48);
		lcd_data((time.sec_u8%0x10)+48);
		lcd_data(' ');
		if(r==0){
				lcd_str("AM");
			}
		else{
				lcd_str("PM");
		}
		
//*************************** DAY  ***************************
		lcd_cmd(0xC0);
		weekDays.day_u8 =i2c_byteReadFrame(0xD0,0x3);
			switch(weekDays.day_u8){
							case 0:
								lcd_str(week[0]);
								break;
							case 1:
								lcd_str(week[1]);
								break;
							case 2:
								lcd_str(week[2]);
								break;
							case 3:
								lcd_str(week[3]);
								break;
							case 4:
								lcd_str(week[4]);
								break;
							case 5:
								lcd_str(week[5]);
								break;
							case 7:
								lcd_str(week[6]);
								break;
			}	
		
	}
}





