// Tic Tac Toe
// NMC EGR111 project with Unit Testing
// Keith E. Kelly
// 10/30/2023
#include "tictactoe.h"

#if !TESTING    //used to limit main() count to 1

int main()
{
    char player, winner, new_game;
    // char board[3][3];
    char board[9];
    // char* b_ptr = &board;  
    char* b_ptr = &board[0]; //the compiler likes this better
    winner ='\0';
    bool play_again = true;

    show_directions();
    while (play_again)
    {
        reset_board(b_ptr);
        display_first_board();
        player = select_first_player();
        while (!is_board_full(b_ptr))
        {
            play(b_ptr, player);
            display_board(b_ptr);
            if (is_winner(b_ptr, player))
            {
                winner = player;
                break;
            }    
            else
                player = get_next_player(player);
        }
        if (winner)
            show_winner(winner);
        else
            show_cat();
    
        printf("\nWould you like to play again? y or n: ");
        scanf("%c", &new_game );
        play_again = (new_game == 'y');
    }
    return 0;
}    
    
#endif