#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int main(void)
{
	int bright;

	printf("Raspberry Pi wiringPi PWM test program\n");

	if( wiringPiSetup () == -1 )
		exit(1);

	pinMode(1, PWM_OUTPUT);

	int i;
	int buf[8000];

	for( i = 0; i < 8000; i++ )
	{
//		buf[i] = sin(i * 440.0 / 8000.0 * 2.0 * 3.14159);
		int q = (sin(i * 440.0 / 8000.0 * 2.0 * 3.14159)) * 512 + 512;
//		printf("%d\n", q);
		buf[i] = q;
	}
	
	printf("Let's get it started, HA!\n");
	for(;;)
	{
		for( bright = 0; bright < 8000; ++bright )
		{
//			printf("%d\n", buf[bright]);
			pwmWrite(1, buf[bright]);
			usleep(125);
		}
	}
	
	return 0;
}
