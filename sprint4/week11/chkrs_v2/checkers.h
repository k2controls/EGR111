#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

#define TESTING true

#define ROW_COUNT           8
#define COL_COUNT           8
#define CELL_COUNT          ROW_COUNT * COL_COUNT
#define NO_PLAY_CELL        -99     // flag for non-space
#define NO_PLAY_CHAR        '#'     // fill for non-space
#define EMPTY_CELL          0       // flag for empty space
#define EMPTY_CELL_CHAR    ' '     // fill for empty space
#define BLACK               1       // Black checkers have pos index
#define RED                 -1      // Red checkers have neg index 
#define LAST_BLACK          12
#define LAST_RED            -12
#define LAST_BLACK_KING     2*LAST_BLACK    //king value range is 13 to 24
#define LAST_RED_KING       2*LAST_RED

#define INVALID_CELL_PTR       NULL

#define MOVE_UP_LEFT        7
#define MOVE_UP_RIGHT       9
#define MOVE_DOWN_LEFT      1
#define MOVE_DOWN_RIGHT     3

void make_board(int* brd_ptr);
void fill_board(int* brd_ptr);
void fill_black(int *brd_ptr);
void fill_red(int *brd_ptr);
void make_cell_str(int* brd_ptr, int* cell_ptr, char* cell_string);
void make_chkr_str(int* brd_ptr, int* cell_ptr, char* cell_string);
char get_checker_mark(int* brd_ptr, int* cell_ptr);
int get_checker_value(int* brd_ptr, int* cell_ptr);
bool is_valid_cell_ptr(int* brd_ptr, int* cell_ptr);
bool is_checker_cell(int* brd_ptr, int* cell_ptr);
bool is_black_cell(int* brd_ptr, int* cell_ptr);
bool is_red_cell(int* brd_ptr, int* cell_ptr);
bool is_king_cell(int* brd_ptr, int* cell_ptr);
bool is_empty_cell(int* brd_ptr, int* cell_ptr);
bool is_no_play_cell(int* brd_ptr, int* cell_ptr);
bool is_foe_cell(int* brd_ptr, int* cell_ptr, int player);
bool is_valid_checker_num(int checker_num, int player);
bool is_valid_cell_ptr(int* brd_ptr, int* cell_ptr);
bool is_checker_on_board(int* brd_ptr, int checker);
int get_cell_owner(int* brd_ptr, int* cell_ptr);
int* locate_cell(int* brd_ptr, int checker_num);
int* get_next_cell_ptr(int* brd_ptr, int* cell_ptr, int move_vector);
bool board_has_jump(int* brd_ptr);
bool cell_has_jump(int* brd_ptr, int* cell_ptr);
bool cell_has_move(int* brd_ptr, int* cell_ptr);
bool jump_checker(int* brd_ptr, int* cell_ptr, int move_vector);
bool move_checker(int* brd_ptr, int* cell_ptr, int move_vector);
bool check_game_over(int* brd_ptr);
int next_player(int current_player);
// view files - not testable
void draw_board(int* brd_ptr);
void show_winner(int player);
bool check_play_again();
int get_user_checker_number(int* brd_ptr, int player);
int get_user_move_vector();
char input_char();
