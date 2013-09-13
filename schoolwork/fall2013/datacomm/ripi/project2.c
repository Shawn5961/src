#include "RPI.h"

int main()
{
	if( map_peripheral(&gpio) == -1 )
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}

	//Define pin 7 as output
	INP_GPIO(10);
	OUT_GPIO(10);

	while( 1 )
	{
		//Toggle pin 7 (blink a led!)
		GPIO_SET = 1 << 10;
		sleep(1);

		GPIO_CLR = 1 << 10;
		sleep(1);
	}

	return 0;
}
