#include "RPI.h"

int main()
{
	int counter;

	if( map_peripheral(&gpio) == -1 )
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}

	//Define pin 11 as output
	INP_GPIO(9);
	OUT_GPIO(9);
	INP_GPIO(10);
	OUT_GPIO(10);
	INP_GPIO(11);
	OUT_GPIO(11);

	while( 1 )
	{
		GPIO_CLR = 1 << 9;
		GPIO_CLR = 1 << 10;
		GPIO_CLR = 1 << 11;
	}

	return 0;
}
