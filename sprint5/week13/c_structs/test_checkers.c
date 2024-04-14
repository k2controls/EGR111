#include "checker.h"

int main()
{
    struct Checker c1;
    c1.is_black = true;
    c1.index = 12;
    c1.is_king = false;
    strcpy(c1.name, "B12");

    if (!c1.is_king)
        printf("Checker %s is not a king.\n", c1.name);
    else
        printf("Checker %s is not a king.\n", c1.name);


    checker* c2_ptr = checker_factory(RED, 9);

    printf("Checker 2 index is %d.\n", c2_ptr->index);
    if (c2_ptr->is_red)
        printf("Checker 2 is Red.\n");
    c2_ptr->is_king = true;
    if (c2_ptr->is_king)
        printf("Checker %s is a king.\n", c2_ptr->name);
    
    checker_dispose(c2_ptr);
}