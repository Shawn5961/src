#include "RPI.h"

int main()
{
	int i;

	if( map_peripheral(&gpio) == -1 )
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}

	for( i = 7; i <= 11; i++ )
	{
		INP_GPIO(i);
		OUT_GPIO(i);
		GPIO_CLR = 1 << i;
	}

	return 0;
}
