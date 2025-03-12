```C

// Tic Tac Toe
// Second version using function stubs

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define OPEN ' '

// use Globals for now
char player1, player2;
char winner = '\0';
char board[3][3] = {
    {OPEN, OPEN, OPEN},
    {OPEN, OPEN, OPEN},
    {OPEN, OPEN, OPEN}};
 
// declare functions here
void show_directions();
void display_board();
// void choose_player1();
char select_first_player();
char get_next_player(char current_player);
bool is_winner(char player);
bool is_hor_winner(char p);
bool is_ver_winner(char p);
bool is_diag_winner(char p);
bool is_board_full();
bool is_cell_valid(int row, int col);
bool is_cell_empty(int row, int col);
bool is_valid_move(int row, int col);
void play(char current_player);
void show_cat();
void show_winner();


int main()
{
    // provides game play. No edit here.
    char player;

    show_directions();
    // choose_player();
    player = select_first_player();
    display_board();

    while(!is_board_full() != false)
    {
        play(player);
        display_board();
        if(is_winner(player))
            break;
        else
            player = get_next_player(player);
    }
    if (winner)
        show_winner();
    else
        show_cat();
}

// define functions here
void show_directions()
{
    //TODO - provide the user with directions.
    //This is a stub. More required.
    printf("Welcome!\n");
}

void display_board()
{
    // display board with clear and row 0 on bottom - kek0
    system("clear");    // require <stdlib.h>
    for (int r = 2; r>=0; r--)  //backward through the array so row 0 is at the bottom
    {
        for (int c = 0; c <= 2; c++)
        {
            printf(" %c ", board[r][c]);
            (c < 2) ? printf("|") : printf("\n");
        }
        (r > 0) ? printf("-----------\n") : printf("\n");  
    }
}

// void choose_player1();
char select_first_player()
{
    //TODO - choose player x an o. Someone goes first.
    // rand() used in final.
    // In tic-tac-toe, the player who uses "X" typically goes first.
    return PLAYER_X;
}

char get_next_player(char current_player)
{
    char next;
    next = (current_player == PLAYER_X) ? PLAYER_O: PLAYER_X;
    return next;
}

bool is_winner(char player)
{
    //TODO - check for winner. Set winner value
    // return false;
    return (is_hor_winner(player) || is_ver_winner(player) || is_diag_winner(player)); 
}

bool is_hor_winner(char p)
{
    //TODO - check three rows for winner
    return false;
}

bool is_ver_winner(char p)
{
    //TODO - check three cols for winner
    return false;
}
bool is_diag_winner(char p)
{
    //TODO - check two diags for winner
    return false;
}

bool is_board_full()
{
    //TODO - any open spaces left?
    return false;
}

bool is_cell_valid(int row, int col)
{
    //TODO - valid row and col index entered?
    return true;
}

bool is_cell_empty(int row, int col)
{
    //TODO - valid cell but is this one empty?
    return true;
}

bool is_valid_move(int row, int col)
{
    return is_cell_valid(row, col) && is_cell_empty(row, col);
}

void play(char current_player)
{
    //TODO - ask current player for row and col
    // if valid, place checker
    getchar(); // Stub requires a key press
    board[1][1] = current_player;   //stub - place current in middle space
}

void show_cat()
{
    //TODO - display Cat's game.
    //In tic-tac-toe, a "cat's game" refers to a tie, where neither player wins.
    ;
}
void show_winner()
{
    //TODO - show winner
    ;
}

```