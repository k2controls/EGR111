#include "functions.h"

#if !TESTING    //not TESTING

int main()
{
    function1();
    function2();
    int z = add_two_nums(1,3);
    printf("%d\n", z);

    return 0;
}

#endif