#include <stdlib.h>

void note_Ascend(int increment)
{
	GPIO_SET = 1 << 10;
	usleep(increment);
	GPIO_CLR = 1 << 10;
	usleep(increment);
}

void note_A4()
{
	GPIO_SET = 1 << 10;
	usleep((1000000 / 440) / 2);
	GPIO_CLR = 1 << 10;
	usleep((1000000 / 440) / 2);
}

void note_B4()
{
	GPIO_SET = 1 << 10;
	usleep(925);
	GPIO_CLR = 1 << 10;
	usleep(925);
}
