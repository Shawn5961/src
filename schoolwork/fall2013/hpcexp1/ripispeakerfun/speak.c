#include "RPI.h"
#include "notes.h"
#include <stdlib.h>
#include <time.h>

int main()
{
	time_t initTime, newTime;
	int counter = 1000;
	int flag = 0;

	if(map_peripheral(&gpio) == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}
	
	INP_GPIO(10);
	OUT_GPIO(10);

	time(&initTime);
	printf("Current time: %d\n", initTime);

	while(1)
	{
//		time(&newTime);
//		if( (newTime - initTime) < 4 )
//		{
			note_A4();
//		}
//		else
//		{
//			note_B4();
//		}

/*
		note_Ascend(counter);
		if ( counter == 2000 )
			flag = 1;
		else if ( counter == 200 )
			flag = 0;

		if ( flag == 1 )
			counter--;
		else if( flag == 0 )
			counter++;
*/	
	}

	return(0);
}
