// Checkers in C
// Version 3.0
//  - includes jump and testing
//  - forward only moves and kings not implemented
// Keith E. Kelly
// 11/4/2023

#include "checkers.h"

#if !TESTING

int main(void)
{
    int board[ROW_COUNT][COL_COUNT]; 
    int* brd_ptr = &board[0][0];
    bool play_again = true;
    int player, chkr_number, move_vector;
    int * chkr_ptr;
    bool brd_has_jump, has_jump, has_move;
    bool jumped, moved;

    while (play_again)
    {
        make_board(brd_ptr);
        fill_board(brd_ptr);
        player = BLACK;    
        draw_board(brd_ptr);
        while (true)
        {
            brd_has_jump = false;
            has_jump = false;
            has_move = false;
            jumped = false;
            moved = false;
                        
            // get mover
            while (!(has_jump || has_move))
            {
                chkr_number = get_user_checker_number(brd_ptr, player);
                chkr_ptr = locate_cell(brd_ptr, chkr_number);
                brd_has_jump = board_has_jump(brd_ptr);
                if (brd_has_jump)
                    has_jump = cell_has_jump(brd_ptr, chkr_ptr);
                else
                    has_move = cell_has_move(brd_ptr, chkr_ptr);
                
                if (brd_has_jump && !has_jump)
                    printf("There is a jump on the board. You must move that checker.\n");
                else if (!(has_jump || has_move))
                    printf("No move possible for that checker. Please select another.\n");
            }
            //make move
            while (!(jumped || moved))
            {
                move_vector = get_user_move_vector();
                if (has_jump)
                    jumped = jump_checker(brd_ptr, chkr_ptr, move_vector);
                else
                    moved = move_checker(brd_ptr, chkr_ptr, move_vector);
                if (!(jumped || moved))
                    printf("Invalid move. Please try again.\n");
            }
            draw_board(brd_ptr);
            // check status
            if (check_game_over(brd_ptr))
                break;
            player = next_player(player);    
        }
        show_winner(player);
        play_again = check_play_again();
    }
    return 0;
}

#endif