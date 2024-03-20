#include "functions.h"

#if TESTING
#include "acutest.h"

void test_add_two(void)
{
    //arrange
    int m = 2;
    int n = 3;
    int p = 0;
    //act
    p = add_two_nums(m, n);
    //assert
    TEST_CHECK(p == 5);
}

// List of tests - key, value pairs with {NULL, NULL} termination.
TEST_LIST = {
    { "can_add_two", test_add_two },
    { NULL, NULL }
};

#endif