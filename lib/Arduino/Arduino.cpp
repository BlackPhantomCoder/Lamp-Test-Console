#include "Arduino.h"
#include <ctime>

unsigned random(unsigned a, unsigned b)
{
	return a + ((b - a) ? rand() % (b - a) : 0);
}

unsigned long millis()
{
	return clock();
}
