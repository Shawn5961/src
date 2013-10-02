#include "RPI.h"
#include <stdlib.h>

int main()
{

	if(map_peripheral(&gpio) == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}
	
	INP_GPIO(10);
	OUT_GPIO(10);

	while(1)
	{
	
		GPIO_SET = 1 <<  10;
		usleep(1055);
		GPIO_CLR = 1 <<  10;
		usleep(1056);
	}

	return(0);
}
