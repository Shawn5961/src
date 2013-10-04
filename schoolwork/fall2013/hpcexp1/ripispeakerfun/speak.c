#include "RPI.h"
#include "notes.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
	srand(time(NULL));
	time_t initTime, newTime;
	int counter = 440;
	int countersine;
	int flag, flag2 = 0;

	if(map_peripheral(&gpio) == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}
	
	INP_GPIO(18);
	OUT_GPIO(18);

	time(&initTime);
	printf("Current time: %d\n", initTime);

	while(1)
	{
/*		time(&newTime);
		if( (newTime - initTime) <= 1 )
			note_A4();
		if( (newTime - initTime) <= 2 )
			note_Bb4();
		if( (newTime - initTime) <= 3 )
			note_B4();
		if( (newTime - initTime) <= 4 )
			note_C5();
		else
		{
			note_Db5();
			initTime = initTime - 5;
		}
*/
		note_Ascend(counter);

/*		if( (counter % 200) == 0 )
		{
			flag = rand() % 10;
			flag2 = rand() % 2;

			switch( flag )
			{
				case 0:
					counter = 200;
					break;

				case 1:
					counter = 400;
					break;

				case 2:
					counter = 600;
					break;

				case 3:
					counter = 800;
					break;

				case 4:
					counter = 1000;
				break;

				case 5:
					counter = 1200;
					break;

				case 6:
					counter = 1400;
					break;

				case 7:
					counter = 1600;
					break;

				case 8:
					counter = 1800;
					break;

				case 9:
					counter = 2000;
					break;
			}		
		}

		if( counter == 880 )
			flag = 1;
		if( counter == 720 )
			flag = 0;
*/
		if( flag == 1 )
			counter--;
		else if( flag == 0 )
			counter++;

//		note_Db5();

	}

	return(0);
}
