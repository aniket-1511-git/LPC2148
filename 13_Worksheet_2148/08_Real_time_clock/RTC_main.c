#include "RTC_header.h"
/*
/*
* Function Name : main
* Description   : Reads time and weekday from RTC and displays it 
*/
int main(void)
{
	// Structure Variable  to hold time values
	clock time;
	// Structure Variable  to hold weekday value
	clock weekDays;
	// Variable to store AM/PM flag
	uint8_t r;
	// Weekday names
	char week[7][10]={"MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY","SUNDAY"};
	 // Initialize LCD
	lcd_init();
	// Initialize I2C
	i2c_init();
	
// *************** SET INITIAL TIME   ******************
	i2c_byteWriteFrame(0xD0, 0x02, 0x70); // Write Hour = 0x70 → 7 PM
	i2c_byteWriteFrame(0xD0, 0x01, 0x45); // Write Min  = 0x45 → 45
	i2c_byteWriteFrame(0xD0, 0x00, 0x10); // Write Sec  = 0x10 → 10
	
	// *************** SET INITIAL DAY *****************************
	i2c_byteWriteFrame(0xD0, 0x03, 0x07); // Set Day = 7 (SUNDAY)
	
	while(1)
	{
		// *************** READ TIME ********************
		time.hour_u8 = i2c_byteReadFrame(0xD0, 0x02); // Read Hour
		time.min_u8  = i2c_byteReadFrame(0xD0, 0x01); // Read Minute
		time.sec_u8  = i2c_byteReadFrame(0xD0, 0x00); // Read Second
		
		r = ((time.hour_u8 >> 5) & 1);  // Extract AM/PM bit (bit 5)
		
		lcd_cmd(0x80);                  // Move LCD cursor to 1st line
		
		time.hour_u8 &= 0x1F;           // Mask out upper bits (keep 5 bits for hour)
		
		// Display HH:MM:SS format on LCD
		lcd_data((time.hour_u8 / 0x10) + 48); // Tens of hour
		lcd_data((time.hour_u8 % 0x10) + 48); // Ones of hour
		lcd_data(':');
		lcd_data((time.min_u8 / 0x10) + 48);  // Tens of minute
		lcd_data((time.min_u8 % 0x10) + 48);  // Ones of minute
		lcd_data(':');
		lcd_data((time.sec_u8 / 0x10) + 48);  // Tens of second
		lcd_data((time.sec_u8 % 0x10) + 48);  // Ones of second
		lcd_data(' ');
		
		// Print AM or PM based on flag
		if(r == 0){
			lcd_str("AM");
		}
		else{
			lcd_str("PM");
		}
		
		// *************** READ DAY  *********************
		lcd_cmd(0xC0); // Move LCD cursor to 2nd line
		weekDays.day_u8 = i2c_byteReadFrame(0xD0, 0x03); // Read day register
		
		// Match weekday number with string
		switch(weekDays.day_u8)
		{
			case 0: lcd_str(week[0]); break; // MONDAY
			case 1: lcd_str(week[1]); break; // TUESDAY
			case 2: lcd_str(week[2]); break; // WEDNESDAY
			case 3: lcd_str(week[3]); break; // THURSDAY
			case 4: lcd_str(week[4]); break; // FRIDAY
			case 5: lcd_str(week[5]); break; // SATURDAY
			case 7: lcd_str(week[6]); break; // SUNDAY
		}	
	}
}



