// Checkers on stack
// Demo of bad code creating objects on the stack
#include <stdio.h>
#include <stdbool.h>

int* make_board();
void make_board2(int*);
void draw_board(int *brd_ptr);
bool is_in_array(int i, int* int_arry, int item_count);

int main(void)
{
    // call a function to make a board
    // FIRST TRY - this is a problem
    int* board_ptr = make_board();
    draw_board(board_ptr);

    // SECOND TRY - this is correct
    // int board[64];  //int board[8][8];
    // int* board_ptr = &board[0];
    // make_board2(board_ptr);
    // draw_board(board_ptr);

    return 0;
}

bool is_in_array(int val, int* int_array, int item_count)
{
    bool found = false;
    int a_val;
    for (int i=0; i<item_count; i++)
    {
        a_val = *(int_array+i);
        if (a_val == val)
        {
            found = true;
            break;
        }
    }
    return found;
}


int* make_board()
{
    int board[64];  //int board[8][8];
    int b_indexes[12] = {1,3,5,7,8,10,12,14,17,19,21,23};
    int r_indexes[12] = {40,42,44,46,49,51,53,55,56,58,60,62};
    int blank_indexes[8] = {24,26,28,30,33,35,37,39};
    int blk_chkr_num = 1;
    int red_chkr_num = 1;
    for (int i=0; i<64; i++)
    {
        if (is_in_array(i, b_indexes, 12))
        {
            board[i] = blk_chkr_num;
            blk_chkr_num++;
        }
        else if (is_in_array(i, r_indexes, 12))
        {
            board[i] = -red_chkr_num;
            red_chkr_num++;
        }
        else if (is_in_array(i, blank_indexes, 12))
            board[i] = 0;
        else
            board[i] = 99;
    }
    draw_board(&board[0]);
    return &board[0];
}

void make_board2(int* board_ptr)
{
    int b_indexes[12] = {1,3,5,7,8,10,12,14,17,19,21,23};
    int r_indexes[12] = {40,42,44,46,49,51,53,55,56,58,60,62};
    int blank_indexes[8] = {24,26,28,30,33,35,37,39};
    int blk_chkr_num = 1;
    int red_chkr_num = 1;
    for (int i=0; i<64; i++)
    {
        if (is_in_array(i, b_indexes, 12))
        {
            *(board_ptr+i) = blk_chkr_num;
            blk_chkr_num++;
        }
        else if (is_in_array(i, r_indexes, 12))
        {
            *(board_ptr+i) = -red_chkr_num;
            red_chkr_num++;
        }
        else if (is_in_array(i, blank_indexes, 12))
            *(board_ptr+i) = 0;
        else
            *(board_ptr+i) = 99;
    }
    draw_board(board_ptr);
}


void draw_board(int *brd_ptr)
{
    printf("\n---------------------------------\n");
    for (int cell = 0; cell < 64; cell++)
    {
        if (*(brd_ptr + cell) == 99)    //no play cell
            printf("|###");
        else if (*(brd_ptr + cell) >= 10)  //large black cell,
            printf("|%c%d", 'b', *(brd_ptr + cell));
        else if (*(brd_ptr + cell) > 0)  //small black cell - pad
            printf("| %c%d", 'b', *(brd_ptr + cell));
        else if (*(brd_ptr + cell) <= -10)  //large red cell,
            printf("|%c%d", 'r', -*(brd_ptr + cell));
        else if (*(brd_ptr + cell) < 0)  //small black cell - pad
            printf("| %c%d", 'r', -*(brd_ptr + cell));
        else if (*(brd_ptr + cell) == 0)  
            printf("|   ");

        if (cell % 8 == 7)
            printf("|\n---------------------------------\n");
    }
}