#include "swap.h"

void swap_bad(int a, int b)
{
    int z = a;
    a = b;
    b = z;
}

void swap_good(int* m, int* n)
{
    int z = *m;
    *m = *n;
    *n = z;
}