#include "RPI.h"

int main()
{
	int counter = 0;
	int option;
	int led_1, led_2, led_3, led_4;

	if( map_peripheral(&gpio) == -1 )
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}

	//Define output pins
	OUT_GPIO(7);
	OUT_GPIO(8);
	OUT_GPIO(9);
	OUT_GPIO(10);

	
	printf("Are you the pitcher or catcher?\n");
	printf("1: Pitcher\n");
	printf("2: Catcher\n");
	scanf("%d", &option);

	switch ( option )
	{
		OUT_GPIO(4);
		OUT_GPIO(17);
		OUT_GPIO(21);
		OUT_GPIO(22);
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
					GPIO_SET = 1 << 27;
				else
					GPIO_CLR = 1 << 27;
					
				if( (counter % 16) >= 8 )
					GPIO_SET = 1 << 22;
				else
					GPIO_CLR = 1 << 22;

				usleep(500000);

				counter++;
			}

			break;

		case 2:
			INP_GPIO(4);
			INP_GPIO(17);
			INP_GPIO(27);
			INP_GPIO(22);
			while(1)
			{
				led_1 = GPIO_READ(4);
				led_2 = GPIO_READ(17);
				led_3 = GPIO_READ(27);
				led_4 = GPIO_READ(22);
				if( led_1 != 0)
					GPIO_SET = 1 << 7;
				else
					GPIO_CLR = 1 << 7;

				if( led_2 != 0 )
					GPIO_SET = 1 << 8;
				else
					GPIO_CLR = 1 << 8;

				if( led_3 != 0 )
					GPIO_SET = 1 << 9;
				else
					GPIO_CLR = 1 << 9;

				if( led_4 != 0 )
					GPIO_SET = 1 << 10;
				else
					GPIO_CLR = 1 << 10;

			}
			break;

		default:
			printf("lololol default");
			break;
	}

	return 0;
}
