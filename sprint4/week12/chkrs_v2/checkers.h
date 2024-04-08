// EGR111 - chkrs_v2
// - king moves are supported
// - make_king is #TODO
// Keith E. Kelly
// 4/8/2024
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

#define TESTING true

#define ROW_COUNT 8
#define COL_COUNT 8
#define CELL_COUNT ROW_COUNT *COL_COUNT
#define INVALID_CELL_PTR NULL

#define EMPTY_CELL_VALUE 0x00   // value for empty space
#define NO_PLAY_CELL_VALUE 0x80 // bit 7 flags no play space
#define KING_FLAG 0x40          // bit 6 is king flag
#define RED 0x20                // bit 5 is red flag
#define BLACK 0x10              // bit 4 is black flag
#define CHECKER_NUM_MIN 0x01    // first checker number is checker 1
#define CHECKER_NUM_MAX 0x0C    // last checker number is checker 12
// example: checker_id for last red as a king is 0x6C or 0110 1100

#define NO_PLAY_CHAR '#'    // fill for non-space
#define EMPTY_CELL_CHAR ' ' // fill for empty space
#define CHECKER_INDEXES_BLK                       \
    {                                             \
        1, 3, 5, 7, 8, 10, 12, 14, 17, 19, 21, 23 \
    }
#define CHECKER_INDEXES_RED                            \
    {                                                  \
        62, 60, 58, 56, 55, 53, 51, 49, 46, 44, 42, 40 \
    }

#define MOVE_UP_LEFT 7    // numeric keypad direction
#define MOVE_UP_RIGHT 9   // numeric keypad direction
#define MOVE_DOWN_LEFT 1  // numeric keypad direction
#define MOVE_DOWN_RIGHT 3 // numeric keypad direction
#define MOVE_NONE 0       // null move vector
// board build functions
void make_board(int *brd_ptr);
void fill_board(int *brd_ptr);
void fill_black(int *brd_ptr);
void fill_red(int *brd_ptr);
// state check functions
bool is_valid_cell_ptr(int *brd_ptr, int *cell_ptr);
bool is_no_play_cell(int *cell_ptr);
bool is_play_cell(int *cell_ptr);
bool is_cell_occupied(int *cell_ptr);
bool is_empty_cell(int *cell_ptr);
bool is_black_cell(int *cell_ptr);
bool is_red_cell(int *cell_ptr);
bool is_king_cell(int *cell_ptr);
bool is_foe_cell(int *cell_ptr, int player);

bool is_valid_checker_num(int checker_num);
bool is_valid_checker_id(int checker_id);

bool is_checker_on_board(int *brd_ptr, int checker_id);
bool is_player_checker_on_board(int *brd_ptr, int player, int checker_num);
int *locate_checker_cell(int *brd_ptr, int checker_id);
int *locate_player_checker_cell(int *brd_ptr, int player, int checker_num);

int get_cell_owner(int *cell_ptr);
int *get_next_cell_ptr(int *brd_ptr, int *cell_ptr, int move_vector);

void make_move_vectors(int *chkr_ptr, int *move_vectors);
bool is_valid_move_vector(int *chkr_ptr, int move_vector);
bool is_valid_move(int *brd_ptr, int *cell_ptr, int move_vector);
bool is_valid_jump(int *brd_ptr, int *cell_ptr, int move_vector);
int *move_checker(int *brd_ptr, int *cell_ptr, int move_vector);
int *jump_checker(int *brd_ptr, int *cell_ptr, int move_vector);

bool cell_has_move(int *brd_ptr, int *cell_ptr);
bool cell_has_jump(int *brd_ptr, int *cell_ptr);
bool board_has_move(int *brd_ptr, int player);
bool board_has_jump(int *brd_ptr, int player);

// not tested
bool check_game_over(int *brd_ptr);
int get_next_player(int current_player);
// view files - not testable
void draw_board(int *brd_ptr);
void make_cell_str(int *cell_ptr, char *cell_string);
void make_chkr_str(int *cell_ptr, char *cell_string);
char make_checker_mark(int *cell_ptr);
int make_checker_value(int *cell_ptr);
void show_winner(int player);
bool check_play_again();
int get_user_checker_number(int *brd_ptr, int player);
int get_user_move_vector();
char input_char();
