#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int main(void)
{
	int bright;
	FILE *dickass;

	printf("Raspberry Pi wiringPi PWM test program\n");

	if( wiringPiSetup () == -1 )
		exit(1);

	pwmSetMode(PWM_MODE_MS);
	pinMode(1, PWM_OUTPUT);

	int i;
	float q, buf[22];

	dickass = fopen("dat", "w");
	for( i = 0; i < 22; i++ )
	{
//		buf[i] = sin(i * 440.0 / 8000.0 * 2.0 * 3.14159);
		q = (sin(i * 440.0 / 8000.0 * 3.14159) * 512 + 512);
//		q = sin((1000 * (2 * 3.14159) * i) / 44100) * 440;
//		q = 400;
		buf[i] = q;
		fprintf(dickass, "%f\n", buf[i]);
	}
	fclose(dickass);

	printf("\n\n");
	printf("Let's get it started, HA!\n");
	for(;;)
	{
		for( bright = 0; bright < 22; ++bright )
		{
//			printf("%f\n", buf[bright]);
			pwmWrite(1, buf[bright]);
			usleep(125);
		}
	}

	return 0;
}
