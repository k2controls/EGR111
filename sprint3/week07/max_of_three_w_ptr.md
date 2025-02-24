```C

// Max of three solution
// Practice declaring and defining functions
// see max calculation in RGB solution
#include <stdio.h>

//declare
void max_of_three(int x, int y, int z, int* max_val);

void main(void)
{
    int a, b, c;
    int max;

    max_of_three(3, 2, -1, &max);
    printf("The maximum of 3, 2, and -1 is %d.\n", max);

    max_of_three(100, 200, 50, &max);
    printf("The maximum of 100, 200, and 50 is %d.\n", max);

    a = 44;
    b = 55;
    c = 66;
    max_of_three(a, b, c, &max);
    printf("The maximum of %d, %d, and %d is %d.\n", a, b, c, max);

}

//define
void max_of_three(int x, int y, int z, int* max_val)
{
    *max_val = x > y? x: y;
    *max_val = *max_val > z? *max_val: z;
}

```
