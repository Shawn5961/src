#include "RPI.h"

int main()
{
	int counter = 0;

	if( map_peripheral(&gpio) == -1 )
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}

	//Define pin 11 as output
	INP_GPIO(7);
	OUT_GPIO(7);
	INP_GPIO(8);
	OUT_GPIO(8);
	INP_GPIO(9);
	OUT_GPIO(9);
	INP_GPIO(10);
	OUT_GPIO(10);


	while( 1 )
	{
		if( (counter % 2) == 1 )
			GPIO_SET = 1 << 7;
		else
			GPIO_CLR = 1 << 7;

		if( (counter % 4) >= 2 )
			GPIO_SET = 1 << 8;
		else
			GPIO_CLR = 1 << 8;

		if( (counter % 8) >= 4 )
			GPIO_SET = 1 << 9;
		else
			GPIO_CLR = 1 << 9;
			
		if( (counter % 16) >= 8 )
			GPIO_SET = 1 << 10;
		else
			GPIO_CLR = 1 << 10;

		usleep(500000);

		counter++;
	}

	return 0;
}
