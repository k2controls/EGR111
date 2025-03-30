// Tic Tac Toe
// NMC EGR111 project with multiple files and board pointer
// Keith E. Kelly
// 10/24/2023
#define TESTING true

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define OPEN ' '

void reset_board(char* board);
void show_directions();
void display_board(char* board);
void display_first_board();
char select_first_player();
char get_next_player(char current_player);
bool is_winner(char* board, char player);
bool is_hor_winner(char* board, char p);
bool is_ver_winner(char* board, char p);
bool is_diag_winner(char* board, char p);
bool is_board_full(char* board);
bool is_space_valid(int space);
bool is_space_empty(char* board, int space);
bool is_valid_move(char* board, int space);
void play(char* board, char current_player);
void show_cat();
void show_winner(char winner);
