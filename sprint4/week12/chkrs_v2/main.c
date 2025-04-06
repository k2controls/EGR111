// Checkers in C
// Version 2.0
//  - includes jump and testing
//  - kings moves implemented
//  - kinging not implemented
// Keith E. Kelly
// 04/06/2024

#include "checkers.h"

#if !TESTING

int* get_selected_checker_from_user(int* brd_ptr, int player, bool has_jump);
int get_selected_move_vector_from_user(int* brd_ptr, int*chkr_ptr, bool has_jump);

int main(void)
{
    int board[ROW_COUNT][COL_COUNT]; 
    int* brd_ptr = &board[0][0];
    bool has_jump, has_second_jump;
    int* chkr_ptr;
    int player, move_vector;
    bool play_again = true;

    while (play_again)
    {
        make_board(brd_ptr);
        fill_board(brd_ptr);
        player = BLACK;    
        while (!check_game_over(brd_ptr))
        {
            draw_board(brd_ptr);
            has_jump = board_has_jump(brd_ptr, player);
            chkr_ptr = get_selected_checker_from_user(brd_ptr, player, has_jump);
            move_vector = get_selected_move_vector_from_user(brd_ptr, chkr_ptr, has_jump);
            if (has_jump)
                jump_checker(brd_ptr, chkr_ptr, move_vector);
            else
                move_checker(brd_ptr, chkr_ptr, move_vector);
            
            has_second_jump = board_has_jump(brd_ptr, player);
            if (has_jump && has_second_jump)
                printf("Additional jump available. Player continues!");
            else
                player = get_next_player(player);
        }
        show_winner(player);
        play_again = check_play_again();
    }
    return 0;
}

int* get_selected_checker_from_user(int* brd_ptr, int player, bool has_jump)
{
    bool valid_chkr = false;
    int chkr_num;
    int* chkr_ptr;
    while (!valid_chkr)
    {
        chkr_num = get_user_checker_number(brd_ptr, player);
        chkr_ptr = locate_player_checker_cell(brd_ptr, player, chkr_num);
        if (has_jump && cell_has_jump(brd_ptr, chkr_ptr))
            valid_chkr = true;
        else if (has_jump)                
            printf("There is a jump on the board. You must move that checker.\n");
        else if (cell_has_move(brd_ptr, chkr_ptr))
            valid_chkr = true;
        else
            printf("No move possible for that checker. Please select another.\n");
    }
    return chkr_ptr;
}

int get_selected_move_vector_from_user(int* brd_ptr, int*chkr_ptr, bool has_jump)
{
    bool valid_move = false;
    int move_vector;

    while(!valid_move)
    {
        move_vector = get_user_move_vector(chkr_ptr);
        if (has_jump && is_valid_jump(brd_ptr, chkr_ptr, move_vector))
            valid_move = true;
        else if (has_jump)
            printf("That's not valid. A jump is required. Please try again.\n");
        else if (is_valid_move(brd_ptr, chkr_ptr, move_vector))
            valid_move = true;
        else
            printf("That's not a valid move. Please try again.\n");

    }
    return move_vector;
}

#endif