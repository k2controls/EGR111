// EGR111 Checkers Project - Starter File
// Work with your partner to analze starter code.
// Add comments and be prepared to discuss
// Continue on your own to code the stubs to 
// create a version of checker that is limited 
// to moving checkers to open board spaces.
// Refer to class discussion and recording provided.
// Keith E. Kelly
// 3/18/24

#include "checkers.h"

int main(void)
{
    int board[ROW_COUNT][COL_COUNT]; 
    int* brd_ptr = &board[0][0];
    bool play_again = true;
    bool game_over = false;
    int player, checker_number, selected_position, move_direction, next_position;

    while (play_again)
    {
        make_board(brd_ptr);
        fill_board(brd_ptr);
        draw_board(brd_ptr);
        player = BLACK;    
        while (!game_over)
        {
            selected_position = NONE_SELECTED;
            while (selected_position == NONE_SELECTED)
            {
                checker_number = get_checker_number(brd_ptr, player);
                selected_position = get_checker_position(brd_ptr, checker_number);
                if (selected_position == NONE_SELECTED)
                    printf("Invalid checker selection. Please try again.\n");
                else if (!has_moves(brd_ptr, selected_position))
                {
                    printf("Invalid checker selection. This checker has no open moves! Please try again.\n");
                    selected_position = NONE_SELECTED;
                }
            }

            next_position = INVALID_POSITION;
            while (next_position == INVALID_POSITION)
            {
                move_direction = get_move_direction();
                next_position = get_next_position(selected_position, move_direction);
                if (!is_valid_position(brd_ptr, next_position))
                {    
                    next_position = INVALID_POSITION;
                    printf("Invalid move. Please try again.\n");
                }
            }

            move_checker(brd_ptr, selected_position, next_position);
            draw_board(brd_ptr);
            
            if (check_game_over(brd_ptr))
            {
                game_over = true;
                break;
            }
            player = next_player(player);    
        }
        show_winner(player);
        play_again = check_play_again();
    }
    return 0;
}
