#include<stdio.h>
#include<time.h>

//Constants
#define MULT_RNG_CONST 	214013L
#define ADD_RNG_CONST 	2531011L
#define MOD_RNG_CONST	32768L

unsigned long applicationSeedVariable = 1L;

long generateBaseRandomNumber();
long rangedRand(long start, long end);
void seedRand(unsigned long seed);
void testMain();

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
