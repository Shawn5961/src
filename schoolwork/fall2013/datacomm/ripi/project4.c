#include "RPI.h"

int main()
{
	int counter = 0;
	int option;
	int debug;

	if( map_peripheral(&gpio) == -1 )
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}

	//Define output pins
	OUT_GPIO(7);
	//INP_GPIO(7);
	OUT_GPIO(8);
	//INP_GPIO(8);
	OUT_GPIO(9);
	//INP_GPIO(9);
	OUT_GPIO(10);
	//INP_GPIO(10);

	//Define input pins
	//OUT_GPIO(4);
	INP_GPIO(4);
	//OUT_GPIO(17);
	INP_GPIO(17);
	//OUT_GPIO(21);
	INP_GPIO(21);
	//OUT_GPIO(22);
	INP_GPIO(22);

	
	printf("Are you the pitcher or catcher?\n");
	printf("1: Pitcher\n");
	printf("2: Catcher\n");
	scanf("%d", &option);

	switch ( option )
	{
		case 1:
			while(1)
			{
				if( (counter % 2) == 1 )
					GPIO_SET = 1 << 4;
				else
					GPIO_CLR = 1 << 4;

				if( (counter % 4) >= 2 )
					GPIO_SET = 1 << 17;
				else
					GPIO_CLR = 1 << 17;

				if( (counter % 8) >= 4 )
					GPIO_SET = 1 << 21;
				else
					GPIO_CLR = 1 << 21;
					
				if( (counter % 16) >= 8 )
					GPIO_SET = 1 << 22;
				else
					GPIO_CLR = 1 << 22;

				usleep(500000);

				counter++;
			}

			break;

		case 2:
			printf("lolol poop");
			while(1)
			{
				debug = GPIO_READ(4);
				printf("%d\n", debug);
				if( GPIO_READ(4) != 0 )
				{	
				//	printf("IMONBITCH\n");
					GPIO_SET = 1 << 7;
				}
				else
				{	
				//	printf("OFFBITCH!\n");
					GPIO_CLR = 1 << 7;
				}

				if( GPIO_READ(17) != 0 )
					GPIO_SET = 1 << 8;
				else
					GPIO_CLR = 1 << 8;

				if( GPIO_READ(21) != 0 )
					GPIO_SET = 1 << 9;
				else
					GPIO_CLR = 1 << 9;

				if( GPIO_READ(22) != 0 )
					GPIO_SET = 1 << 10;
				else
					GPIO_CLR = 1 << 10;

				usleep(100000);
			}
			break;

		default:
			printf("lololol default");
			break;
	}

	return 0;
}
