// 3/18/24
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ROW_COUNT           8
#define COL_COUNT           8
#define SPACE_COUNT         ROW_COUNT * COL_COUNT
#define NON_SPACE           -99     // flag for non-space
#define NON_SPACE_CHAR      '#'     // fill for non-space
#define EMPTY_SPACE         0       // flag for empty space
#define EMPTY_SPACE_CHAR    ' '     // fill for empty space
#define BLACK               1       // Black checkers have pos index
#define RED                 -1      // Red checkers have neg index 

#define NONE_SELECTED                   -1
#define INVALID_POSITION                -1
#define MOVE_COMPLETE                   0

#define MOVE_UP_LEFT        7
#define MOVE_UP_RIGHT       9
#define MOVE_DOWN_LEFT      1
#define MOVE_DOWN_RIGHT     3

void make_board(int* brd_ptr);
void fill_board(int* brd_ptr);
void draw_board(int* brd_ptr);
int get_checker_number(int* brd_ptr, int player);
int get_checker_position(int* brd_ptr, int player);
// bool is_black_position(int* brd_prt, int position);
// bool is_red_position(int* brd_prt, int position);
// bool is_empty_position(int* brd_prt, int position);
bool has_moves(int* brd_ptr, int selected_position);
int get_move_direction();
int get_next_position(int current_position, int move_direction);
bool is_valid_position(int* brd_ptr, int next_position);
void move_checker(int* brd_ptr, int current_position, int next_position);
bool check_game_over(int* brd_ptr);
int next_player(int current_player);
void show_winner(int player);
bool check_play_again();

char input_char(void);