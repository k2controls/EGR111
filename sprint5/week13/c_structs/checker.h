#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BLACK 1
#define RED -1

typedef struct Checker
{
    int index;
    bool is_empty;
    bool is_black;
    bool is_red;
    bool is_king;
    char name[4];

} checker;

checker* checker_factory(int checker_color, int chkr_index); 
void checker_dispose(checker* chkr_ptr);
