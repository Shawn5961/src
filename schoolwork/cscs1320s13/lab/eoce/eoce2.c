#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gd.h>
#include <gdfontl.h>
#include <time.h>

#define LIGHTGREEN	0
#define GREEN       1
#define DARKGREEN   2
#define BROWN		3
#define WHITE		4

double randDouble(double max)
{
	double randdouble = (((double)rand()/(double)RAND_MAX) + 1) * (max);

	return randdouble;
}

int main(int argc, char* argv[])
{
	FILE *out;
	gdImagePtr img;
	char format[] = "trees/%02d.png";
	char outfile[sizeof format+100];
	unsigned int color[5];
	unsigned short int wide, high, x;
	int i, j, k;
	double randNum, randNum2, randNum3;
	int randNum4;

	wide = atoi(argv[1]);
	high = atoi(argv[2]);

	srand(time(NULL));


	//My GD color definitions

	for(k = 0; k < 100; k++)
	{
		img = gdImageCreate(wide, high);
		color[LIGHTGREEN]		= gdImageColorAllocate(img, 0x6C, 0xFD, 0x70);
		color[GREEN]            = gdImageColorAllocate(img, 0x00, 0xFF, 0x00);
		color[DARKGREEN]        = gdImageColorAllocate(img, 0x33, 0x6B, 0x00);
		color[BROWN]			= gdImageColorAllocate(img, 0x71, 0x28, 0x00);
		color[WHITE]			= gdImageColorAllocate(img, 0xFF, 0xFF, 0xFF);
		sprintf(outfile, format, k);
		printf("[%s]\n", outfile);
		
		gdImageFilledRectangle(img, 0, 0, wide, high, color[WHITE]);

		gdImageFilledRectangle(img, (wide/2)-25, 100, (wide/2)+25, high, color[BROWN]);

		for(i = 1; i < 5; i++)
		{
			gdImageFilledRectangle(img, (wide/4), ((high/5)*i), (wide/2)-25, ((high/5)*i)-5, color[BROWN]);

			randNum3 = rand() % 20 + 1;
			for(j = 1; j < randNum3; j++)
			{
				randNum = randDouble(wide/40);
				randNum2 = randDouble(wide/200);
				randNum4 = rand() % 3;
				gdImageFilledArc(img, (wide/4)+(randNum*(j/(randNum3/5))), ((high/5)*i)-(randNum2*2), randNum2*5, randNum2*5, 0, 360, color[randNum4], gdArc);
			}

			randNum3 = rand() % 20 + 1;
			for(j = 1; j < randNum3; j++)
			{
				randNum = randDouble(wide/40);
				randNum2 = randDouble(wide/200);
				randNum4 = rand() % 3;
				gdImageFilledArc(img, (wide/4)+(randNum*(j/(randNum3/5))), ((high/5)*i)+(randNum2*2), randNum2*5, randNum2*5, 0, 360, color[randNum4], gdArc);
			}

			randNum = randDouble(wide/100);
			randNum4 = rand() % 3;
			gdImageFilledArc(img, (wide/4), ((high/5)*i)-3, randNum*5, randNum*5, 0, 360, color[randNum4], gdArc);
		}

		for(i = 1; i < 6; i++)
		{
			gdImageFilledRectangle(img, (wide/2)+25, ((high/6.1)*i)+25, wide-(wide/4), ((high/6.1)*i)-5+25, color[BROWN]);

			randNum3 = rand() % 20 + 1;
			for(j = randNum3; j > 1; j--)
			{
				randNum = randDouble(wide/40);
				randNum2 = randDouble(wide/200);
				randNum4 = rand() % 3;
				gdImageFilledArc(img, (wide/2)+(wide/40)+(randNum*(j/(randNum3/5))), ((high/6.1)*i)+(randNum2+2), randNum2*5, randNum2*5, 0, 360, color[randNum4], gdArc);
			}

			randNum3 = rand() % 20 + 1;
			for(j = randNum3; j > 1; j--)
			{
				randNum = randDouble(wide/40);
				randNum2 = randDouble(wide/200);
				randNum4 = rand() % 3;
				gdImageFilledArc(img, (wide/2)+(wide/40)+(randNum*(j/(randNum3/5))), ((high/6.1)*i)+(randNum2+25), randNum2*5, randNum2*5, 0, 360, color[randNum4], gdArc);
			}

			randNum = randDouble(wide/100);
			randNum4 = rand() % 3;
			gdImageFilledArc(img, wide-(wide/4), ((high/6.1)*i)+22, randNum*5, randNum*5, 0, 360, color[randNum4], gdArc);
		}

		for(i = 1; i < 6; i++)
		{
			randNum = randDouble(wide/40);
			randNum2 = randDouble(high/40);
			randNum3 = randDouble(high/100);
			randNum4 = rand() % 3;
			gdImageFilledArc(img, (wide/2), ((high/randNum3)*i), randNum*5, randNum2*5, 0, 360, color[randNum4], gdArc);
		}

		out = fopen(outfile, "wb");
		gdImagePngEx(img, out, -1);

		// Close things up
		//
		fclose(out);
		gdImageDestroy(img);
	}
	
	return(0);
}
