#include "checker.h"

checker* checker_factory(int checker_color, int chkr_index)  
{
    checker* chkr_ptr = (checker*)malloc(sizeof(checker));
    chkr_ptr->index = chkr_index;
    chkr_ptr->is_black = (checker_color == BLACK);
    chkr_ptr->is_red = (checker_color == RED);
    chkr_ptr->is_king = false;
    char color_char = (checker_color==BLACK)? 'b': 'r';
    if (chkr_index<10) //pad cell
        sprintf(chkr_ptr->name, " %c%1d", color_char, chkr_ptr->index);
    else
        sprintf(chkr_ptr->name, "%c%2d", color_char, chkr_ptr->index);
    return chkr_ptr;    
}

void checker_dispose(checker* chkr_ptr)
{
    //you made it. if you're done with it, then be sure to clean up!
    free(chkr_ptr);
}
