#include "RPI.h"

struct bcm2835_peripheral gpio = {GPIO_BASE};

//Exposes the physical address defined in the passed structure using mmap on /dev/mem
int map_peripheral(struct bcm2835_peripheral *p)
{
	//Open /dev/mem
	if (( p->mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0)
	{
		printf("Failed to open /dev/mem, try checking permissions.\n");
		return -1;

