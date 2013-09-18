//Constants
#define MULT_RNG_CONST 	214013L
#define ADD_RNG_CONST 	2531011L
#define MOD_RNG_CONST	32768L

long generateBaseRandomNumber();
long rangedRand(long start, long end);
void seedRand(unsigned long seed);
void testMain();
