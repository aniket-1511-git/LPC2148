#include "ext_int_header.h"
/*
* Function name      : int main(void)
* Description        : this function to check external interrut                         
*/
int main(void)
{
	// Function Call to init ext int0
	ext_Int_config();
	// Function Call to config ext int0
 	config_extint0();
	while(1U)
	{

	}
}



