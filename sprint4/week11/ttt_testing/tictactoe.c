// Tic Tac Toe
// NMC EGR111 project with multiple files
// Keith E. Kelly
// 10/24/2023
#include "tictactoe.h"

void reset_board(char* board)
{ 
    for (int i=0; i<9; i++)
        *(board + i) = OPEN;
}

void show_directions()
{
    printf("Play tic tac toe!\n");
    printf("Use the space index to select your space.\n\n");
}

void display_board(char* board)
{   
    int space_index = 0;
    for (int r = 6; r>=0; r-=3)  //backward through the array so row 0 is at the bottom
    {
        for (int c = 0; c <= 2; c++)
        {
            space_index = r+c;
            printf(" %c ", *(board+space_index));
            (c < 2) ? printf("|") : printf("\n");
        }
        (r > 0) ? printf("-----------\n") : printf("\n");  
    }
}

void display_first_board()
{   
    int space_index = 0;
    for (int r = 6; r>=0; r-=3)  //backward through the array so row 0 is at the bottom
    {
        for (int c = 0; c <= 2; c++)
        {
            space_index = r+c;
            printf(" %d ", space_index);
            (c < 2) ? printf("|") : printf("\n");
        }
        (r > 0) ? printf("-----------\n") : printf("\n");  
    }
}

char choose_player1_mark()
{
    char player_mark = ' ';
    while(player_mark != PLAYER_X && player_mark != PLAYER_O)
    {
        printf("Player 1, would you like to be X or O? ");
        scanf("%c", &player_mark);
        while(getchar() != '\n')
            ;
        player_mark = toupper(player_mark);
        printf("\n");
    }
    return player_mark;
}

char select_first_player()
{
    return (rand()%2) ? PLAYER_X : PLAYER_O;
}

char get_next_player(char current_player)
{
    char next;
    next = (current_player == PLAYER_X) ? PLAYER_O :PLAYER_X;
    return next;
}

bool is_winner(char* board, char player)
{
    if(is_hor_winner(board, player) 
        || is_ver_winner(board, player) 
            || is_diag_winner(board, player))
        return true;
    else
        return false;
}

bool is_hor_winner(char* board, char p)
{
    bool win = false;
    for(int r = 0; r<=6; r+=3)
        if (*(board+r) == p && *(board+r+1) == p && *(board+r+2) == p)
            win = true;
    return win;
}

bool is_ver_winner(char* board, char p)
{
    bool win = false;
    for(int c = 0; c<=2; c++)
        if (*(board+c) == p && *(board+3+c) == p && *(board+6+c) == p)
            win = true;
    return win;
}

bool is_diag_winner(char* board, char p)
{
    bool win = false;
    if (*(board+4) == p)
    {   
        if (*(board) == p && *(board+8) == p)
            win = true;
        else if (*(board+2) == p && *(board+6) == p)
            win = true;
    }
    return win;
}

bool is_board_full(char* board)
{
    bool full = true;
    for (int i=0; i<9; i++)
        if (*(board+i) == OPEN)
           full = false;
    return full; 
}

bool is_space_valid(int space)
{
    return (space >= 0 && space <= 8);
}

bool is_space_empty(char* board, int space)
{
    return (*(board+space) == OPEN);
}

bool is_valid_move(char* board, int space)
{
    return (is_space_valid(space) && is_space_empty(board, space));
}

void play(char* board, char current_player)
{
    int move;
    bool valid_move = false;
    
    while (!valid_move)
    {
        printf("It's %c's move. Enter move: ", current_player);
        scanf("%d", &move);
        valid_move = is_valid_move(board, move);
        if (valid_move)
            *(board+move) = current_player;
        else
           printf("Invalid move. Please try again.\n");
        while ((getchar()) != '\n') //clear input stream
            ;
    }
}

void show_cat()
{
    printf("Cat's Game!\n\n");
}

void show_winner(char winner)
{
    printf("Congratulations Player %c. You won!\n\n", winner);
}
