#include "checkers.h"

board* board_factory()
{
    board* board_ptr = (board*)malloc(sizeof(board));
    space* prior_space_ptr = NULL;
    for (int row_cnt=1; row_cnt<=8; row_cnt++)
        for(int space_cnt=1; space_cnt<=4; space_cnt++)
        {
            board_ptr->active_space_ptr = space_factory(row_cnt, prior_space_ptr);
            if (prior_space_ptr == NULL)
                board_ptr->first_space_ptr = board_ptr->active_space_ptr;
            prior_space_ptr = board_ptr->active_space_ptr;
        }
    board_ptr->last_space_ptr = board_ptr->active_space_ptr;
    
    board_ptr->active_player = BLACK;
    board_ptr->active_space_ptr = NULL;
    board_ptr->move = board_ptr->->moves.MOVE_NONE
    board_ptr->jumpers[0] = NULL;
    board_ptr->game_over = false;
    
    return board_ptr;
}

void board_dispose(board* board_ptr)
{
    space* target;
    while (board_ptr->last_space_ptr)
    {
        target = board_ptr->last_space_ptr;
        board_ptr->last_space_ptr = target->prior_space_ptr;
        space_dispose(target);
    }
    board_ptr->first_space_ptr = NULL;
    board_ptr->last_space_ptr = NULL;
    free(board_ptr);
}

space* space_factory(int row_num, space* prior_space_ptr)
{
    space* space_ptr = (space*)malloc(sizeof(space));
    space_ptr->row_num = row_num;
    space_ptr->prior_space_ptr = prior_space_ptr;
    space_ptr->next_space_ptr = NULL;
    space_ptr->adj_space_ur = NULL;
    space_ptr->adj_space_ul = NULL;
    space_ptr->adj_space_dr = NULL;
    space_ptr->adj_space_dl = NULL;
    space_ptr->owner = NULL;

    if (prior_space_ptr)
        prior_space_ptr->next_space_ptr = space_ptr;
    link_adjacent_spaces(space_ptr);

    return space_ptr;
};

void space_dispose(space* space_ptr)
{
    space_ptr->prior_space_ptr = NULL;
    space_ptr->next_space_ptr = NULL;
    space_ptr->adj_space_ur = NULL;
    space_ptr->adj_space_ul = NULL;
    space_ptr->adj_space_dr = NULL;
    space_ptr->adj_space_dl = NULL;
    if (space_ptr->owner)
        checker_dispose(space_ptr->owner);
    space_ptr->owner = NULL;
    free(space_ptr);
}

checker* checker_factory(int color, int checker_num, space* location_ptr)
{
    checker* chkr_ptr = (checker*)malloc(sizeof(checker));
    chkr_ptr->color = color;
    chkr_ptr->color_char = (color==BLACK)? 'b' : 'r';
    chkr_ptr->number = checker_num;
    chkr_ptr->location = location_ptr;
    chkr_ptr->is_king = false;
    if (checker_num<10) //pad cell
        sprintf(chkr_ptr->name, " %c%1d", chkr_ptr->color_char, checker_num);
    else
        sprintf(chkr_ptr->name, "%c%2d", chkr_ptr->color_char, checker_num);
    return chkr_ptr;    
}

void checker_dispose(checker* chkr_ptr)
{
    chkr_ptr->location = NULL;
    free(chkr_ptr);
}

void link_adjacent_spaces(space* space_ptr)
{
    link_adjacent_space_left(space_ptr);
    link_adjacent_space_right(space_ptr);
}

void link_adjacent_space_left(space* space_ptr)
{
    space* left_adjacent_space_ptr;
    int space_offset = 5 - space_ptr->row_num % 2;
    left_adjacent_space_ptr = get_adjacent_space(space_ptr, space_offset);
    // adjacent cell must exist and be on prior row
    if (left_adjacent_space_ptr
        && left_adjacent_space_ptr->row_num == space_ptr->row_num-1)
    {
        space_ptr->adj_space_ul = left_adjacent_space_ptr;
        left_adjacent_space_ptr->adj_space_dr = space_ptr;
    }

}

void link_adjacent_space_right(space* space_ptr)
{
    space* right_adjacent_space_ptr;
    int space_offset = 4 - space_ptr->row_num % 2;
    right_adjacent_space_ptr = get_adjacent_space(space_ptr, space_offset);
    // adjacent cell must exist and be on prior row
    if (right_adjacent_space_ptr 
        && right_adjacent_space_ptr->row_num == space_ptr->row_num-1)
    {
        space_ptr->adj_space_ur = right_adjacent_space_ptr;
        right_adjacent_space_ptr->adj_space_dl = space_ptr;
    }
}

space* get_adjacent_space(space* space_ptr, int space_offset)
{
    space* adjacent_space = space_ptr;
    while (space_offset && adjacent_space)
    {
        adjacent_space = adjacent_space->prior_space_ptr;
        space_offset--;
    }
    return adjacent_space;
}

void fill_board(board* board_ptr)
{
    fill_board_black(board_ptr);
    fill_board_red(board_ptr);
}

void fill_board_black(board* board_ptr)
{
    checker* chkr_ptr;
    space* active_space_ptr = board_ptr->first_space_ptr;
    for (int i=1; i<=12; i++)
    {
        chkr_ptr = checker_factory(BLACK, i, active_space_ptr);
        active_space_ptr->owner = chkr_ptr;
        active_space_ptr = active_space_ptr->next_space_ptr;
    }
}

void fill_board_red(board* board_ptr)
{
    checker* chkr_ptr;
    space* active_space_ptr = board_ptr->last_space_ptr;
    for (int i=1; i<=12; i++)
    {
        chkr_ptr = checker_factory(RED, i, active_space_ptr);
        selected_space_ptr->owner = chkr_ptr;
        selected_space_ptr = selected_space_ptr->prior_space_ptr;
    }
}

void draw_board(board* board_ptr)
{
    space* space_ptr = board_ptr->first_space_ptr;
    printf("\n---------------------------------\n");
    for(int row_num=1; row_num<=8; row_num++)
    {
        if (row_num%2)
            draw_row_odd(space_ptr);
        else
            draw_row_even(space_ptr);
        printf("|\n---------------------------------\n"); 
        if (row_num<8)
            space_ptr = space_ptr->next_space_ptr
                    ->next_space_ptr
                    ->next_space_ptr
                    ->next_space_ptr;    //advance to next row
    }
}    

void draw_row_odd(space* space_ptr)
{
    for(int space_num=1; space_num<=4; space_num++)
    {
        if (space_ptr->owner)
            printf("|###|%s", space_ptr->owner->name);
        else
            printf("|###|   ");
        space_ptr = space_ptr->next_space_ptr;
    }
}

void draw_row_even(space* space_ptr)
{
    for(int space_num=1; space_num<=4; space_num++)
    {
        if (space_ptr->owner)
            printf("|%s|###", space_ptr->owner->name);
        else
            printf("|   |###");
        space_ptr = space_ptr->next_space_ptr;
    }
}

bool locate_checker(board* board_ptr, int checker_num)
{
    bool found = false;
    char chkr_name[4] = " ";

    if (checker_num >= 1 && checker_num <=12)    
    {
        char checker_color = (board_ptr->active_player == BLACK)? 'b' : 'r';
        if (checker_num<10)
            sprintf(chkr_name, " %c%d", checker_color, checker_num);
        else
            sprintf(chkr_name, "%c%d", checker_color, checker_num);
            
        board_ptr->active_space_ptr = board_ptr->first_space_ptr;
        while (board_ptr->active_space_ptr && !found)
        {
            if (board_ptr->active_space_ptr->owner)
                if (strcmp(board_ptr->active_space_ptr->owner->name, chkr_name) ==0)
                    found = true;
            board_ptr->active_space_ptr = board_ptr->active_space_ptr->next_space_ptr;
        }
    }
    return found;
}