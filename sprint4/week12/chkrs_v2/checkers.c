// EGR111 - chkrs_v2
// is_valid_jump not implemented #TODO
// jump_checker not implemented #TODO
// - king moves are supported
// - make_king is #TODO
// Keith E. Kelly
// 4/8/2024
#include "checkers.h"

void make_board(int *brd_ptr)
{
    int cell_index, cell_value;
    for (int row = 0; row < ROW_COUNT; row++)
        for (int col = 0; col < COL_COUNT; col++)
        {
            // make checker board pattern checking odd-even row-col match
            cell_value = (row % 2 == col % 2) ? NO_PLAY_CELL_VALUE : EMPTY_CELL_VALUE;
            cell_index = row * COL_COUNT + col;
            *(brd_ptr + cell_index) = cell_value;
        }
}

void fill_board(int *brd_ptr)
{
    fill_black(brd_ptr);
    fill_red(brd_ptr);
}

void fill_black(int *brd_ptr)
{
    int chkr_indexes[12] = CHECKER_INDEXES_BLK;
    int chkr_num, chkr_id, index;
    for (int i = 0; i < 12; i++)
    {
        chkr_num = i + 1;
        chkr_id = BLACK | chkr_num;
        index = chkr_indexes[i];
        *(brd_ptr + index) = chkr_id;
    }
}

void fill_red(int *brd_ptr)
{
    int chkr_indexes[12] = CHECKER_INDEXES_RED;
    int chkr_num, chkr_id, index;
    for (int i = 0; i < 12; i++)
    {
        chkr_num = i + 1;
        chkr_id = RED | chkr_num;
        index = chkr_indexes[i];
        *(brd_ptr + index) = chkr_id;
    }
}

bool is_valid_cell_ptr(int *brd_ptr, int *cell_ptr)
{
    return (cell_ptr >= brd_ptr && cell_ptr < brd_ptr + CELL_COUNT);
}

bool is_no_play_cell(int *cell_ptr)
{
    return *cell_ptr == NO_PLAY_CELL_VALUE;
}

bool is_play_cell(int *cell_ptr)
{
    return is_black_cell(cell_ptr) || is_red_cell(cell_ptr) || is_empty_cell(cell_ptr);
}

bool is_cell_occupied(int *cell_ptr)
{
    return is_black_cell(cell_ptr) || is_red_cell(cell_ptr);
}

bool is_empty_cell(int *cell_ptr)
{
    return *cell_ptr == EMPTY_CELL_VALUE;
}

bool is_black_cell(int *cell_ptr)
{
    int value = *cell_ptr;
    value = value & BLACK; // mask all but black color bit
    return value;
}

bool is_red_cell(int *cell_ptr)
{
    int value = *cell_ptr;
    value = value & RED; // mask all but red color bit
    return value;
}

bool is_king_cell(int *cell_ptr)
{
    int value = *cell_ptr;
    value = value & KING_FLAG; // mask all but King bit
    return value;
}

bool is_foe_cell(int *cell_ptr, int player)
{
    if (player == BLACK)
        return (is_red_cell(cell_ptr));
    else // player red
        return (is_black_cell(cell_ptr));
}

bool is_valid_checker_num(int checker_num)
{
    return (checker_num >= CHECKER_NUM_MIN && checker_num <= CHECKER_NUM_MAX);
}

bool is_valid_checker_id(int checker_id)
{
    checker_id = checker_id & 0b10111111;   // Mask KING_FLAG
    int chk_num1 = checker_id & 0b11011111; // Mask Red
    int chk_num2 = checker_id & 0b11101111; // Mask Black
    return is_valid_checker_num(chk_num1) || is_valid_checker_num(chk_num2);
}

bool is_checker_on_board(int *brd_ptr, int checker_id)
{
    int *cell_ptr = locate_checker_cell(brd_ptr, checker_id);
    return (cell_ptr != INVALID_CELL_PTR);
}

bool is_player_checker_on_board(int *brd_ptr, int player, int checker_num)
{
    int *cell_ptr = locate_player_checker_cell(brd_ptr, player, checker_num);
    return (cell_ptr != INVALID_CELL_PTR);
}

int *locate_checker_cell(int *brd_ptr, int checker_id)
{
    int *cell_ptr = INVALID_CELL_PTR;
    for (int idx = 0; idx < CELL_COUNT; idx++)
        if (*(brd_ptr + idx) == checker_id)
        {
            cell_ptr = brd_ptr + idx;
            break;
        }
    return cell_ptr;
}

int *locate_player_checker_cell(int *brd_ptr, int player, int checker_num)
{
    int checker_id = player | checker_num;
    int *cell_ptr = locate_checker_cell(brd_ptr, checker_id);
    if (!cell_ptr)
    {
        checker_id = KING_FLAG | checker_id;
        cell_ptr = locate_checker_cell(brd_ptr, checker_id);
    }
    return cell_ptr;
}

int get_cell_owner(int *cell_ptr)
{
    int owner = 0;
    if (is_black_cell(cell_ptr))
        owner = BLACK;
    else if (is_red_cell(cell_ptr))
        owner = RED;
    return owner;
}

int *get_next_cell_ptr(int *brd_ptr, int *cell_ptr, int move_vector)
{
    int *next_ptr = INVALID_CELL_PTR;
    switch (move_vector)
    {
    case MOVE_UP_LEFT:
        next_ptr = cell_ptr - 9;
        break;
    case MOVE_UP_RIGHT:
        next_ptr = cell_ptr - 7;
        break;
    case MOVE_DOWN_LEFT:
        next_ptr = cell_ptr + 7;
        break;
    case MOVE_DOWN_RIGHT:
        next_ptr = cell_ptr + 9;
        break;
    }
    if (!is_valid_cell_ptr(brd_ptr, next_ptr))
        next_ptr = INVALID_CELL_PTR; // ptr is off board
    else if (is_no_play_cell(next_ptr))
        next_ptr = INVALID_CELL_PTR; // ptr on NO_PLAY cell - invalid
    return next_ptr;
}

void make_move_vectors(int *chkr_ptr, int *move_vectors)
{
    if (is_king_cell(chkr_ptr))
    {
        *(move_vectors + 0) = MOVE_UP_LEFT;
        *(move_vectors + 1) = MOVE_UP_RIGHT;
        *(move_vectors + 2) = MOVE_DOWN_LEFT;
        *(move_vectors + 3) = MOVE_DOWN_RIGHT;
    }
    else if (is_black_cell(chkr_ptr))
    {
        *(move_vectors + 0) = MOVE_NONE;
        *(move_vectors + 1) = MOVE_NONE;
        *(move_vectors + 2) = MOVE_DOWN_LEFT;
        *(move_vectors + 3) = MOVE_DOWN_RIGHT;
    }
    else if (is_red_cell(chkr_ptr))
    {
        *(move_vectors + 0) = MOVE_UP_LEFT;
        *(move_vectors + 1) = MOVE_UP_RIGHT;
        *(move_vectors + 2) = MOVE_NONE;
        *(move_vectors + 3) = MOVE_NONE;
    }
    else
    {
        *(move_vectors + 0) = MOVE_NONE;
        *(move_vectors + 1) = MOVE_NONE;
        *(move_vectors + 2) = MOVE_NONE;
        *(move_vectors + 3) = MOVE_NONE;
    }
}

bool is_valid_move_vector(int *chkr_ptr, int move_vector)
{
    bool is_valid = false;
    int move_vectors[4];
    make_move_vectors(chkr_ptr, &move_vectors[0]);
    for (int i = 0; i < 4; i++)
    {
        if (*(move_vectors + i) == move_vector)
        {
            is_valid = true;
            break;
        }
    }
    return is_valid;
}

bool is_valid_move(int *brd_ptr, int *cell_ptr, int move_vector)
{
    // returns true if valid move
    bool is_valid = false;
    int *next_cell_ptr = get_next_cell_ptr(brd_ptr, cell_ptr, move_vector);
    if (is_valid_cell_ptr(brd_ptr, next_cell_ptr) && is_empty_cell(next_cell_ptr))
        is_valid = true;
    return is_valid;
}

bool is_valid_jump(int *brd_ptr, int *cell_ptr, int move_vector)
{
    // returns true if valid jump move
    bool is_valid = false;

    // #TODO

    return is_valid;
}

int *move_checker(int *brd_ptr, int *cell_ptr, int move_vector)
{
    // returns pointer to new location if move. No move returns null
    int *new_cell_ptr = INVALID_CELL_PTR;
    int *next_cell_ptr = INVALID_CELL_PTR;
    if (is_valid_move(brd_ptr, cell_ptr, move_vector))
    {
        next_cell_ptr = get_next_cell_ptr(brd_ptr, cell_ptr, move_vector);
        // move attacker
        *(next_cell_ptr) = *(cell_ptr);
        *(cell_ptr) = EMPTY_CELL_VALUE;
        new_cell_ptr = next_cell_ptr;
    }
    return new_cell_ptr;
}

int *jump_checker(int *brd_ptr, int *cell_ptr, int move_vector)
{
    // returns pointer to new location if jump. No jump returns null
    int *new_cell_ptr = INVALID_CELL_PTR;

    // #TODO
    
    return new_cell_ptr;
}

bool cell_has_move(int *brd_ptr, int *cell_ptr)
{
    bool has_move = false;
    int move_vectors[4];

    if (is_valid_cell_ptr(brd_ptr, cell_ptr) && is_cell_occupied(cell_ptr))
    {
        make_move_vectors(cell_ptr, &move_vectors[0]);
        for (int i = 0; i < 4; i++)
        {
            if (is_valid_move(brd_ptr, cell_ptr, move_vectors[i]))
            {    
                has_move = true;
                break;
            }
        }
    }
    return has_move;
}

bool cell_has_jump(int *brd_ptr, int *cell_ptr)
{
    bool has_jump = false;
    int move_vectors[4];

    if (is_valid_cell_ptr(brd_ptr, cell_ptr) && is_cell_occupied(cell_ptr))
    {
        make_move_vectors(cell_ptr, &move_vectors[0]);
        for (int i = 0; i < 4; i++)
        {
            if (is_valid_jump(brd_ptr, cell_ptr, move_vectors[i]))
            {
                    has_jump = true;
                    break;
            }
        }
    }
    return has_jump;
}

bool board_has_move(int *brd_ptr, int player)
{
    int *cell_ptr;
    bool has_move = false;
    for (int idx = 0; idx < CELL_COUNT; idx++)
    {
        cell_ptr = brd_ptr + idx;
        if (cell_has_move(brd_ptr, cell_ptr))
            if (get_cell_owner(cell_ptr) == player)
            {
                has_move = true;
                break;
            }
    }
    return has_move;
}

bool board_has_jump(int *brd_ptr, int player)
{
    int *cell_ptr;
    bool has_jump = false;
    for (int idx = 0; idx < CELL_COUNT; idx++)
    {
        cell_ptr = brd_ptr + idx;
        if (cell_has_jump(brd_ptr, cell_ptr))
            if (get_cell_owner(cell_ptr) == player)
            {
                has_jump = true;
                break;
            }
    }
    return has_jump;
}

bool check_game_over(int *brd_ptr)
{
    bool return_val = false;
    if (!(board_has_move(brd_ptr, BLACK) || board_has_jump(brd_ptr, BLACK)))
        return_val = true;
    else if (!(board_has_move(brd_ptr, RED) || board_has_jump(brd_ptr, RED)))
        return_val = true;
    return return_val;
}

int get_next_player(int current_player)
{
    int next_player = current_player ^ BLACK ^ RED;
    return next_player; 
}

// view files - not testable

void draw_board(int *brd_ptr)
{
    char cell_string[4]; // string value must be terminated with null value '\0'

    printf("\n---------------------------------\n");
    for (int cell = 0; cell < CELL_COUNT; cell++)
    {
        make_cell_str(brd_ptr + cell, cell_string);
        printf("|%s", cell_string);
        if (cell % 8 == 7)
            printf("|\n---------------------------------\n");
    }
}

void make_cell_str(int *cell_ptr, char *cell_string)
{
    if (is_cell_occupied(cell_ptr))
        make_chkr_str(cell_ptr, cell_string);
    else if (is_empty_cell(cell_ptr))
        sprintf(cell_string, "%c%c%c", EMPTY_CELL_CHAR, EMPTY_CELL_CHAR, EMPTY_CELL_CHAR);
    else // no play space
        sprintf(cell_string, "%c%c%c", NO_PLAY_CHAR, NO_PLAY_CHAR, NO_PLAY_CHAR);
}

void make_chkr_str(int *cell_ptr, char *cell_string)
{
    char mark = make_checker_mark(cell_ptr);
    int value = make_checker_value(cell_ptr);
    if (value < 10) // pad cell
        sprintf(cell_string, " %c%1d", mark, value);
    else
        sprintf(cell_string, "%c%2d", mark, value);
}

char make_checker_mark(int *cell_ptr)
{
    char mark = is_black_cell(cell_ptr) ? 'b' : 'r';
    if (is_king_cell(cell_ptr))
        mark = toupper(mark);
    return mark;
}

int make_checker_value(int *cell_ptr)
{
    int chkr_value = abs(*cell_ptr); // adjust for red
    chkr_value = chkr_value & 0x0F;  // remove KING_FLAG
    return chkr_value;
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
    printf("Would you like to play again? y or n: ");
    char response = input_char();
    return response == 'y';
}

int get_user_checker_number(int *brd_ptr, int player)
{
    int checker_num = 0;
    while (true)
    {
        printf("%s's move. Which checker: ", player == BLACK ? "Black" : "Red");
        scanf("%d", &checker_num);
        if (locate_player_checker_cell(brd_ptr, player, checker_num))
            break;
        else
            printf("Invalid checker number. Try again.\n");
    }
    return checker_num;
}

int get_user_move_vector(int* chkr_ptr)
{
    int move_vector;
    while (true)
    {
        printf("Enter move (7=upleft,9=upright,1=downleft, 3=downright): ");
        scanf("%d", &move_vector);
        if (is_valid_move_vector(chkr_ptr, move_vector))
            break;
        else
            printf("That's not a valid direction. Try again.\n");
    }
    return move_vector;
}

char input_char()
{
    // This function solves issues with capturing chars with scanf()
    // It does not take any parameters but returns a value.
    // An assignment operator is likely used when calling this function.
    // For example: char grade = input_char();
    char c = ' ';
    char return_char;
    while (c == ' ') // strip leading spaces
        c = getchar();
    if (c == '\0' || c == '\n') // if null char or new line
        return_char = '\0';     // return null char
    else
        return_char = c; // capture first character
    while (c != '\n')    // discard others until EOL
        c = getchar();
    return return_char;
}