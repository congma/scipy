#ifdef ELLINT_POLY_REAL
#undef ELLINT_POLY_REAL
#endif
#define ELLINT_POLY_COMPLEX
#include "test_common.h"


#define NARGS	(3)


static int testwrapper(const EllInt_Num_t args[NARGS], double rerr,
		       EllInt_Num_t * restrict res)
{
    return cellint_RD(args[0], args[1], args[2], rerr, res);
}


int main(int argc, char * argv[])
{
    (void)argc;
    (void)argv;
    const EllInt_Num_t eres[] = {
	1.7972103521034,
	0.16510527294261,
	0.65933854154220,
	1.2708196271910 + 2.7811120159521 * I,
	-1.8577235439239 - 0.96193450888839 * I,
	1.8249027393704 - 1.2218475784827 * I
    };
    const EllInt_Num_t args[][NARGS] = {
	{0.0, 2.0, 1.0},
	{2.0, 3.0, 4.0},
	{I, -I, 2.0},
	{0.0, I, -I},
	{0.0, -1.0 + I, I},
	{-2.0 - I, -I, -1.0 + I}
    };

    TESTARRAY_MAIN();
}
