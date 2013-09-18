#include<stdio.h>
#include<time.h>
#include "randomNumberGenerator.h"

unsigned long applicationSeedVariable = 1L;

/**
 * It all begins here.
 */
int main()
{
	testMain();
}

/**
 * Generates an unparametered random long int based off of the seed passed in. Also updates to a new seed.
 */
long generateBaseRandomNumber()
{
	long randomNumberBase = (applicationSeedVariable * MULT_RNG_CONST + ADD_RNG_CONST) % MOD_RNG_CONST;
	seedRand(randomNumberBase);
	return(randomNumberBase);
}

/**
 * This gets a random number in a specific range
 * start: The the lower end inclusive
 * end: The upper end exclusive
 */
long rangedRand(long start, long end)
{
	return generateBaseRandomNumber() % (end - start + 1);
}

/**
 * Seeds the RNG
 * seed: A seed to set for the RNG.
 */
void seedRand(unsigned long seed)
{
	applicationSeedVariable = seed;
}

void testMain()
{
	seedRand(time(NULL));
	int i = 0;
	for(i=0;i < 10; i++)
	{
		printf("%ld\n", rangedRand(0, 10));
	}
}
