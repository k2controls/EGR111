#include "swap.h"

int main()
{
    int t = 11;
    int p = 22;
    swap_bad(t, p);
    printf("t=%d, p=%d\n", t, p);
    printf("now swap!\n");
    int* t_ptr = &t;
    int* p_ptr = &p;
    swap_good(t_ptr, p_ptr); //pass by reference
    printf("t=%d, p=%d\n", t, p);
    
}