#include "checkers.h"

void make_board(int* brd_ptr)
{
    int cell_index, cell_value;
    for (int row = 0; row < ROW_COUNT; row++)
        for (int col = 0; col < COL_COUNT; col ++)
        {
            //make checker board pattern checking odd-even row-col match
            cell_value = (row%2 == col%2)? NO_PLAY_CELL: EMPTY_CELL;
            cell_index = row*COL_COUNT+col;
            *(brd_ptr+cell_index) = cell_value;
        }
}

void fill_board(int* brd_ptr)
{
    fill_black(brd_ptr);
    fill_red(brd_ptr);
}

void fill_black(int *brd_ptr)
{
    int chkr_num = 1;
    for (int cell = 0; cell<CELL_COUNT; cell++)
    {
        if (*(brd_ptr+cell) == EMPTY_CELL)
            *(brd_ptr+cell) = chkr_num++;
        if (chkr_num > LAST_BLACK)
            break;    
    }
}

void fill_red(int *brd_ptr)
{
    int chkr_num = -1;
    for (int cell = CELL_COUNT-1; cell>=0; cell--)
    {
        if (*(brd_ptr+cell) == EMPTY_CELL)
            *(brd_ptr+cell) = chkr_num--;
        if (chkr_num < LAST_RED)
            break;    
    }
}

void make_cell_str(int* brd_ptr, int* cell_ptr, char* cell_string)
{
    if (is_checker_cell(brd_ptr, cell_ptr))
        make_chkr_str(brd_ptr, cell_ptr, cell_string);
    else if (is_empty_cell(brd_ptr, cell_ptr))
        sprintf(cell_string, "%c%c%c", EMPTY_CELL_CHAR, EMPTY_CELL_CHAR, EMPTY_CELL_CHAR);
    else //no play space
        sprintf(cell_string, "%c%c%c", NO_PLAY_CHAR, NO_PLAY_CHAR, NO_PLAY_CHAR);
}

void make_chkr_str(int* brd_ptr, int* cell_ptr, char* cell_string)
{
    char mark = get_checker_mark(brd_ptr, cell_ptr);
    int value = get_checker_value(brd_ptr, cell_ptr);
    if (value<10) //pad cell
        sprintf(cell_string, " %c%1d", mark, value);
    else
        sprintf(cell_string, "%c%2d", mark, value);
}

char get_checker_mark(int* brd_ptr, int* cell_ptr)
{
    char mark = is_black_cell(brd_ptr, cell_ptr)? 'b': 'r';
    if (is_king_cell(brd_ptr, cell_ptr))
        mark = toupper(mark);
    return mark;    
}

int get_checker_value(int* brd_ptr, int* cell_ptr)
{
    int chkr_value = abs(*cell_ptr);    //adjust for red
    if (is_king_cell(brd_ptr, cell_ptr))    //adjust for king
        chkr_value -= LAST_BLACK;   // values must be between 1 and 12
    return chkr_value;
}

bool is_valid_cell_ptr(int* brd_ptr, int* cell_ptr)
{
    return (cell_ptr >= brd_ptr && cell_ptr < brd_ptr+CELL_COUNT);
}

bool is_checker_cell(int* brd_ptr, int* cell_ptr)
{
    return is_black_cell(brd_ptr, cell_ptr) || is_red_cell(brd_ptr, cell_ptr);
}

bool is_black_cell(int* brd_ptr, int* cell_ptr)
{
    bool is_black = false;
    if (is_valid_cell_ptr(brd_ptr, cell_ptr))
        is_black = *cell_ptr > 0 && *cell_ptr <= LAST_BLACK_KING;
    return is_black;
}

bool is_red_cell(int* brd_ptr, int* cell_ptr)
{
    bool is_red = false;
    if (is_valid_cell_ptr(brd_ptr, cell_ptr))
        is_red = *cell_ptr < 0 && *cell_ptr >= LAST_RED_KING;
    return is_red;
}

bool is_king_cell(int* brd_ptr, int* cell_ptr)
{
    bool is_king = false;
    if (is_valid_cell_ptr(brd_ptr, cell_ptr))
        is_king = abs(*cell_ptr) > LAST_BLACK && abs(*cell_ptr) <= LAST_BLACK_KING;
    return is_king;
}

bool is_empty_cell(int* brd_ptr, int* cell_ptr)
{
    bool is_empty = false;
    if (is_valid_cell_ptr(brd_ptr, cell_ptr))
        is_empty = (*cell_ptr == EMPTY_CELL);
    return is_empty;
}

bool is_no_play_cell(int* brd_ptr, int* cell_ptr)
{
    bool is_no_play = false;
    if (is_valid_cell_ptr(brd_ptr, cell_ptr))
        is_no_play =  (*cell_ptr == NO_PLAY_CELL);
    return is_no_play;
}

bool is_foe_cell(int* brd_ptr, int* cell_ptr, int player)
{
    if (player==BLACK)
        return (is_red_cell(brd_ptr, cell_ptr));
    else //player red
        return (is_black_cell(brd_ptr, cell_ptr));
}

bool is_valid_checker_num(int checker_num, int player)
{
    return (checker_num*player>0 && checker_num*player<=12);
}

bool is_checker_on_board(int* brd_ptr, int checker)
{
    int* cell_ptr = locate_cell(brd_ptr, checker);
    return (cell_ptr != INVALID_CELL_PTR);
}

int get_cell_owner(int* brd_ptr, int* cell_ptr)
{
    int owner = 0;
    if (is_valid_cell_ptr(brd_ptr, cell_ptr))
        owner = (is_black_cell(brd_ptr, cell_ptr))?  BLACK: RED;
    return owner;
}

int* locate_cell(int* brd_ptr, int checker_num)
{
    int* cell_ptr = INVALID_CELL_PTR;
    for (int idx=0; idx<CELL_COUNT; idx++)
        if (*(brd_ptr+idx) == checker_num)
        {
            cell_ptr = brd_ptr+idx;
            break;
        }
    return cell_ptr;
}

int* get_next_cell_ptr(int* brd_ptr, int* cell_ptr, int move_vector)
{
    int* next_ptr = INVALID_CELL_PTR;
    switch (move_vector)
    {
        case 1:
            next_ptr = cell_ptr - 9;
        break;
        case 2:
            next_ptr = cell_ptr - 7;
        break;
        case 3:
            next_ptr = cell_ptr + 7;
        break;
        case 4:
            next_ptr = cell_ptr + 9;
        break;
    }
    if (next_ptr < brd_ptr || next_ptr >= brd_ptr+CELL_COUNT)
        next_ptr = INVALID_CELL_PTR;
    return next_ptr;
}

bool board_has_jump(int* brd_ptr)
{
    int* cell_ptr;
    bool has_jump = false;
    for (int idx=0; idx<CELL_COUNT; idx++)
    {
        cell_ptr = brd_ptr + idx;
        if (cell_has_jump(brd_ptr, cell_ptr))
        {
            has_jump = true;
            break;
        }
    }
    return has_jump;
}

bool cell_has_jump(int* brd_ptr, int* cell_ptr)
{
    int player;
    int* next_cell_ptr;
    int* next_next_cell_ptr;
    bool has_jump = false;
    if (is_checker_cell(brd_ptr, cell_ptr))
    {
        player = get_cell_owner(brd_ptr, cell_ptr);
        for (int move_vector=1; move_vector<=4; move_vector++)
        {
            next_cell_ptr = get_next_cell_ptr(brd_ptr, cell_ptr, move_vector);
            if (is_foe_cell(brd_ptr, next_cell_ptr, player))
            {
                next_next_cell_ptr = get_next_cell_ptr(brd_ptr, next_cell_ptr, move_vector);
                if (is_empty_cell(brd_ptr, next_next_cell_ptr))
                {
                    has_jump = true;
                    break;
                }
            }
        }
    }
    return has_jump;
}

bool cell_has_move(int* brd_ptr, int* cell_ptr)
{
    int* next_cell_ptr;
    bool has_move = false;
    for (int move_vector=1; move_vector<=4; move_vector++)
    {
        next_cell_ptr = get_next_cell_ptr(brd_ptr, cell_ptr, move_vector);
        if (is_empty_cell(brd_ptr, next_cell_ptr))
        {
            has_move = true;
            break;
        }
    }
    return has_move;
}

bool jump_checker(int* brd_ptr, int* cell_ptr, int move_vector)
{
    bool jumped = false;
    int* next_cell_ptr = get_next_cell_ptr(brd_ptr, cell_ptr, move_vector);
    int* next_next_cell_ptr = get_next_cell_ptr(brd_ptr, next_cell_ptr, move_vector);
    int player = get_cell_owner(brd_ptr, cell_ptr);
    
    if (is_foe_cell(brd_ptr, next_cell_ptr, player))
        if (is_empty_cell(brd_ptr, next_next_cell_ptr))
        {
            //move attacker
            *(next_next_cell_ptr) = *(cell_ptr);
            *(cell_ptr) = EMPTY_CELL;
            //remove foe            
            *(next_cell_ptr) = EMPTY_CELL;
            jumped = true;
        }
    return jumped;
}

bool move_checker(int* brd_ptr, int* cell_ptr, int move_vector)
{
    bool moved = false;
    int* next_cell_ptr = get_next_cell_ptr(brd_ptr, cell_ptr, move_vector);
    if (is_empty_cell(brd_ptr, next_cell_ptr))
        {
            //move attacker
            *(next_cell_ptr) = *(cell_ptr);
            *(cell_ptr) = EMPTY_CELL;
            moved = true;
        }
    return moved;
}

bool check_game_over(int* brd_ptr)
{
    // return false;         //stub - #TODO
    bool has_black = false;
    bool has_red = false;
    for (int idx =0; idx<CELL_COUNT; idx++)
    {
        if (is_black_cell(brd_ptr, brd_ptr+idx))
            has_black = true;
        if (is_red_cell(brd_ptr, brd_ptr+idx))
            has_red = true;
    }
    return !(has_black && has_red);
}

int next_player(int current_player)
{
    return current_player * -1;         //stub - #TODO
}

// view files - not testable

void draw_board(int* brd_ptr)
{
    char cell_string[4];    // string value must be terminated with null value '\0'
    
    printf("\n---------------------------------\n");
    for (int cell = 0; cell<CELL_COUNT; cell++)
    {
        make_cell_str(brd_ptr, brd_ptr+cell, cell_string);        
        printf("|%s", cell_string);
        if (cell%8==7)
            printf("|\n---------------------------------\n");
    }
}

void show_winner(int player)
{
    if (player == BLACK)
        printf("Black wins!\n"); 
    else
        printf("Red wins!\n");
}

bool check_play_again()
{
    // return false;       //stub - #TODO
    printf("Would you like to play again? y or n: ");
    char response = input_char();
    return response == 'y';
}

int get_user_checker_number(int* brd_ptr, int player)
{
    int checker_num = 0;
    while (true)
    {
        printf("%s's move. Which checker: ", player<0?"Red":"Black");
        scanf("%d", &checker_num);
        checker_num *= player;   //adjust checker sign
        if (!is_valid_checker_num(checker_num, player))
            printf("Invalid checker number. Try again.\n");
        else if (!is_checker_on_board(brd_ptr, checker_num))
            printf("That checker is not in play. Try again.");
        else
            break;
    }
    return checker_num;
}

int get_user_move_vector()
{
    int move_vector = 0;
    int move_select = 0;
    printf("Enter move (7=upleft,9=upright,1=downleft, 3=downright): ");
    while (move_select == 0)
    {
        scanf("%d", &move_select);
        if (move_select != 7 && move_select != 9 && move_select != 3 && move_select != 1)
        {
            printf("That's not a valid direction. Try again.\n");
            move_select = 0;
        }
    }
    switch (move_select)
    {
        case 7:
            move_vector = 1;
        break;
        case 9:
            move_vector = 2;
        break;
        case 1:
            move_vector = 3;
        break;
        case 3:
            move_vector = 4;
        break;
    }
    return move_vector;
}

char input_char()
{
    //This function solves issues with capturing chars with scanf()
    //It does not take any parameters but returns a value.
    //An assignment operator is likely used when calling this function.
    //For example: char grade = input_char();
    char c = ' ';
    char return_char;
    while(c == ' ')             //strip leading spaces
        c =getchar();
    if (c == '\0' || c == '\n') //if null char or new line
        return_char = '\0';     //return null char
    else
        return_char = c;        //capture first character
    while (c != '\n')           //discard others until EOL
        c = getchar();    
    return return_char;
}