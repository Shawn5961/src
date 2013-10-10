#include <stdlib.h>

#define A4	440
#define Bb4	466.16
#define B4 	493.88
#define C5	523.25
#define Db5	554.37
#define D5	587.33
#define E5	659.26
#define A5	880.00
#define E6	1318.51

void note_Ascend(int increment)
{
	GPIO_SET = 1 << 18;
	usleep(increment);
	GPIO_CLR = 1 << 18;
	usleep(increment);
}

void note_Descend(int increment)
{
	GPIO_SET = 1 << 7;
	usleep(increment);
	GPIO_CLR = 1 << 7;
	usleep(increment);
}

void note_A4()
{
	GPIO_SET = 1 << 18;
	usleep((1000000 / A4) / 2 - 80);
	GPIO_CLR = 1 << 18;
	usleep((1000000 / A4) / 2 - 80);
}

void note_A4_2()
{
	GPIO_SET = 1 << 7;
	usleep((1000000 / A4) / 2 - 80);
	GPIO_CLR = 1 << 7;
	usleep((1000000 / A4) / 2 - 80);
}
void note_Bb4()
{
	GPIO_SET = 1 << 18;
	usleep((1000000 / Bb4) / 2 - (Bb4 / 5.8));
	GPIO_CLR = 1 << 18;
	usleep((1000000 / Bb4) / 2 - (Bb4 / 5.8));
}

void note_B4()
{
	GPIO_SET = 1 << 7;
	usleep((1000000 / B4) / 2 - (B4 / 6.15));
	GPIO_CLR = 1 << 7;
	usleep((1000000 / B4) / 2 - (B4 / 6.15));
}

void note_C5()
{
	GPIO_SET = 1 << 18;
	usleep((1000000 / C5) / 2 - (C5 / 6.5));
	GPIO_CLR = 1 << 18;
	usleep((1000000 / C5) / 2 - (C5 / 6.5));
}

void note_Db5()
{
	GPIO_SET = 1 << 18;
	usleep((1000000 / Db5) / 2 - (Db5 / 7.1));
	GPIO_CLR = 1 << 18;
	usleep((1000000 / Db5) / 2 - (Db5 / 7.1));
}

void note_D5()
{
	GPIO_SET = 1 << 7;
	usleep((1000000 / D5) / 2 - (Db5 / 7.1));
	GPIO_CLR = 1 << 7;
	usleep((1000000 / D5) / 2 - (Db5 / 7.1));
}

void note_E5()
{
	GPIO_SET = 1 << 7;
	usleep((1000000 / E5) / 2 - 80);
	GPIO_CLR = 1 << 7;
	usleep((1000000 / E5) / 2 - 80);
}

void note_A5()
{
	GPIO_SET = 1 << 18;
	usleep((1000000 / A5) / 2 - 80);
	GPIO_CLR = 1 << 18;
	usleep((1000000 / A5) / 2 - 80);
}

void note_E6()
{
	GPIO_SET = 1 << 7;
	usleep((1000000 / E6) / 2 - 80);
	GPIO_CLR = 1 << 7;
	usleep((1000000 / E6) / 2 - 80);
}
