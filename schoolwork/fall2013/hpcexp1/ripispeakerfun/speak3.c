#include "RPI.h"
#include "notes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

int main()
{
	srand(time(NULL));
	struct timeval tv;
	time_t initTime, newTime;
	int counter = 440;
	int counter2 = 440;
	int countersine;
	int flag = 0, flag2 = 0;

	float time1, time2;

	if(map_peripheral(&gpio) == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}
	
	INP_GPIO(7);
	OUT_GPIO(7);
	INP_GPIO(18);
	OUT_GPIO(18);

	gettimeofday(&tv, NULL);
	initTime = tv.tv_usec;
	printf("Current time: %d\n", initTime);


	while(1)
	{
/*		time(&newTime);
		if( ((newTime - initTime) % 4) == 0 )
			note_A4();
		else if( ((newTime - initTime) % 4 )== 1 || ((newTime - initTime) % 4 == 3 ) )
		{
			note_A4();
			note_E5();
		}
		else
			note_E5();
*/

		gettimeofday(&tv, NULL);
		newTime = tv.tv_usec;
		if( (newTime % 500000) < 200000)
			note_A4();
		else if( (newTime % 500000) >= 200000)
			note_A4_2();
				

		if( counter == 880 )
			flag = 1;
		if( counter == 220 )
			flag = 0;

		if( flag == 1 )
		{
			counter--;
			counter2++;
		}
		else if( flag == 0 )
		{
			counter++;
			counter2--;
		}

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
//		if( flag == 1 )
//			counter--;
//		else if( flag == 0 )
//			counter++;

//		note_Db5();

	}

	return(0);
}
