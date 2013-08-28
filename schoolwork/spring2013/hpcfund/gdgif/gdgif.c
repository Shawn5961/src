#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gd.h>
#include <math.h>

#define BLACK		0
#define GRAY		1
#define VIOLET		2
#define INDIGO		3
#define BLUE		4
#define GREEN		5
#define YELLOW		6
#define ORANGE		7
#define RED			8
#define WHITE		9

#define PI			3.1415926535897

int main(int argc, char* argv[])
{
	// Creation of file pointers for our output files and GD image
	FILE *out;
	gdImagePtr img;

	// Setting of the output files name formatting
	char format[] = "output/%02d.png";
	char outfile[sizeof format+100];

	// Instantiation of the array of usable colors
	unsigned int color[10];

	// Instantiation of the image dimensions
	int wide, high;

	// Instantiation of variables needed for the spiral.
	int degree, x, y;
	float radian;

	// Counter variables
	int imageNum, i, j, k;

	/* Conditional statement for size of images based on arguments, defaulting to correct syntax in
	 * case of improper usage
	 */
	if(argc == 1)
	{
		wide = 800;
		high = 600;
		printf("Program run with no arguments\n");
		printf("Setting dimensions to default. W:800 x H:600\n");
	}
	else if(argc == 3)
	{
		wide = atoi(argv[1]);
		high = atoi(argv[2]);
		printf("Program run with two arguments\n");
		printf("Setting dimensions to W:%u x H:%u", wide, high);
	}
	else
	{
		printf("Syntax: gdgif [width] [height]\n");
		printf("If run with no arguments, the default dimensions are set to W:800 x H:600\n");
		exit(1);
	}

	// Main loop of the program. Set to run as many times as the number of images you wish to create
	for(imageNum = 0; imageNum < 100; imageNum++)
	{
		// Creation of a new image
		img = gdImageCreate(wide, high);

		// Setting of the color values
		color[BLACK]			= gdImageColorAllocate(img, 0x00, 0x00, 0x00);
		color[GRAY]				= gdImageColorAllocate(img, 0x70, 0x70, 0x70);
		color[VIOLET]			= gdImageColorAllocate(img, 0x8F, 0x00, 0xFF);
		color[INDIGO]			= gdImageColorAllocate(img, 0x4B, 0x00, 0x82);
		color[BLUE]				= gdImageColorAllocate(img, 0x00, 0x00, 0xFF);
		color[GREEN]			= gdImageColorAllocate(img, 0x00, 0xFF, 0x00);
		color[YELLOW]			= gdImageColorAllocate(img, 0xFF, 0xFF, 0x00);
		color[ORANGE]			= gdImageColorAllocate(img, 0xFF, 0x7F, 0x00);
		color[RED]				= gdImageColorAllocate(img, 0xFF, 0x00, 0x00);
		color[WHITE]			= gdImageColorAllocate(img, 0xFF, 0xFF, 0xFF);

		/* Set the output file's name to the specified format, and name it based on the number of 
		 * times the main loop has run.
		 */
		sprintf(outfile, format, imageNum);

		/* Loop to generate a number of circles based on the number of images created with
		 * positions and colors set relevant to the number of times through the loop
		 */
		for(i = 0; i <= imageNum; i++)
		{
			degree = i * 10;
			radian = degree * (PI / 180);
			x = (wide / 2) + (i * 2) * sin(radian);
			y = (high / 2) + (i * 2) * cos(radian);
			gdImageFilledArc(img, x, y, (i + 3), (i + 3), 0, 360, color[i % 10], gdArc);
		}

		// Write the output file, and then write the image to the output file
		out = fopen(outfile, "wb");
		gdImagePngEx(img, out, -1);

		// Print the file being written
		printf("Writing: [%s]\n", outfile);

		// Clean up
		fclose(out);
		gdImageDestroy(img);
	}

	return 0;
}
