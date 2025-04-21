#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef TESTING

#define TESTING true


//*********** data definitions ****************/

#define RED     -1
#define BLACK   1

enum moves {MOVE_UP_LEFT = 7,
            MOVE_UP_RIGHT = 9,
            MOVE_DOWN_LEFT = 1,
            MOVE_DOWN_RIGHT = 3,
            MOVE_NONE = 0};

typedef struct Checker
{
    int color;
    char color_char;
    int number;
    struct Space* location;
    bool is_king;
    char name[4];
} checker;

typedef struct Space
{
    int row_num;
    struct Space* prior_space_ptr;
    struct Space* next_space_ptr;

    struct Space* adj_space_ur;        //up right adjacent space
    struct Space* adj_space_ul;        //up left adjacent space
    struct Space* adj_space_dr;        //down right adjacent space
    struct Space* adj_space_dl;        //down left adjacent space
    
    checker* owner;         //pointer to checker on ps
}space;

typedef struct Board
{
    space* first_space_ptr;
    space* last_space_ptr;

    int active_player;
    space* active_space_ptr;
    space* jumpers[4];
    enum moves move;

    char status[50];
    
    bool game_over;
}board;

//*********** functions ****************/
board* board_factory();
void board_dispose(board* board_ptr);
space* space_factory(int row_num, space* prior_space_ptr);
void space_dispose(space* space_ptr);
checker* checker_factory(int color, int checker_num, space* location_ptr);
void checker_dispose(checker* chkr_ptr);

void link_adjacent_spaces(space* space_ptr);
void link_adjacent_space_left(space* space_ptr);
void link_adjacent_space_right(space* space_ptr);
space* get_adjacent_space(space* space_ptr, int space_offset);

void fill_board(board* board_ptr);
void fill_board_black(board* board_ptr);
void fill_board_red(board* board_ptr);

void draw_board(board* board_ptr);
void draw_row_odd(space* space_ptr);
void draw_row_even(space* space_ptr);

bool locate_checker(board* board_ptr, int checker_num);

int get_checker_number(board* board_ptr);
bool validate_checker(board* board_ptr);
int get_user_moves();
bool space_has_jump(space* space_ptr);
bool board_has_jump(board* board_ptr);
bool space_has_move(space* space_ptr);
bool move_checker(board* board_ptr, enum moves move);

#endif

