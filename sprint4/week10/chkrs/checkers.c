#include "checkers.h"

void make_board(int* brd_ptr)
{
    //add code analysis comments here
    int space_value;
    for (int row = 0; row < ROW_COUNT; row++)
        for (int col = 0; col < COL_COUNT; col ++)
            {
                space_value = (row%2 == col%2)?NO_PLAY_CELL:EMPTY_CELL;
                *(brd_ptr+row*COL_COUNT+col) = space_value;
            }
}

void fill_board(int* brd_ptr)
{
    //add code analysis comments here
    int blk_ckr_index = BLACK;
    int red_ckr_index = RED;
    for (int i = 0; i<CELL_COUNT;i++)
        if (*(brd_ptr+i) != NO_PLAY_CELL && i < 3*COL_COUNT)
            *(brd_ptr+i) = blk_ckr_index++;
        else if (*(brd_ptr+i) != NO_PLAY_CELL && i >= 5*COL_COUNT)
            *(brd_ptr+i) = red_ckr_index--;
}

void draw_board(int* brd_ptr)
{
    //add code analysis comments here
    char chkr_color;
    int chkr_index;
    printf("\n");
    printf("---------------------------------\n");
    for (int i = 0; i<CELL_COUNT;i++)
    {
        printf("%c", '|');
        if (*(brd_ptr+i) == NO_PLAY_CELL)
            printf("%c%c%c", NO_PLAY_CHAR,NO_PLAY_CHAR,NO_PLAY_CHAR);
        else if (*(brd_ptr+i) == EMPTY_CELL)
            printf("%c%c%c", EMPTY_CELL_CHAR,EMPTY_CELL_CHAR,EMPTY_CELL_CHAR);
        else
        {
            chkr_index =*(brd_ptr+i);
            chkr_color = (chkr_index>0)?'b':'r';
            if (abs(chkr_index)<10) //add pad
                printf("%c", ' ');
            printf("%c", chkr_color);
            printf("%d", abs(chkr_index));
            
        }
        if (i%8==7)
        {
            printf("%c\n", '|');
            printf("---------------------------------\n");
        }
    }
}

int get_checker_number(int* brd_ptr, int player)
{
    int checker_num = 12;   //stub - #TODO
}

int get_checker_position(int* brd_ptr, int checker_number)
{
    return 23;             //stub - #TODO
}

bool has_moves(int* brd_ptr, int selected_position)
{
    return true;            //stub - #TODO
}

int get_move_direction()
{
    return MOVE_DOWN_LEFT;  //stub - #TODO
}

int get_next_position(int current_position, int move_direction)
{
    return 30;              //stub - #TODO
}

bool is_valid_position(int* brd_ptr, int next_position)
{
    return true;            //stub - #TODO
}

void move_checker(int* brd_ptr, int current_position, int next_position)
{
    *(brd_ptr+next_position) = *(brd_ptr+current_position);
    *(brd_ptr+current_position) = EMPTY_CELL;
}

bool check_game_over(int* brd_ptr)
{
    return true;         //stub - #TODO
}

int next_player(int current_player)
{
    return RED;         //stub - #TODO
}

void show_winner(int player)
{
    ;                   //stub - #TODO
}

bool check_play_again()
{
    return false;       //stub - #TODO
}

