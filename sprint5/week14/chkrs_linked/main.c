// Checkers with Links
// Version 5.0
//  - playspace and nonplayspace with links
//  - board is created using linked lists
// Keith E. Kelly
// 4/18/2025

#include "checkers.h"

#if !TESTING

int main(void)
{
    int selected_checker_num;
    enum moves move;
    board* brd_ptr = board_factory();

    fill_board(brd_ptr);
    while (!brd_ptr->game_over)
    {
        draw_board(brd_ptr);
        while (!brd_ptr->active_space_ptr)
        {
            selected_checker_num = get_checker_number(brd_ptr);
            if (!locate_checker(brd_ptr, selected_checker_num))
                printf(brd_ptr->status);
            else if (!validate_checker(brd_ptr))
                printf(brd_ptr->status);
        }
        while (brd_ptr->active_space_ptr)
        {
            move = get_user_move();
            move_checker(brd_ptr, move);
            printf(brd_ptr->status);
        }
    }
    
    board_dispose(brd_ptr);
}

int get_checker_number(board* board_ptr)
{
    int checker_num = 0;
    while (checker_num == 0)
    {
        printf("%s's move. Which checker: ", board_ptr->active_player == BLACK ? "Black" : "Red");
        scanf("%d", &checker_num);
        if (!(checker_num>=1 && checker_num<=12))
        {
            printf("Invalid checker number. Try again.");
            checker_num = 0;
        }    
    }
    return checker_num;
}

int get_user_move()
{
    int user_move;
    enum moves move = MOVE_NONE;
    while (move == MOVE_NONE)
    {
        printf("Enter move (7=upleft,9=upright,1=downleft, 3=downright): ");
        scanf("%d", &user_move);
        if (user_move == 1 || user_move == 3 || user_move ==7 || user_move == 9)
            move = (enum moves)user_move;
        else
            printf("That's not a valid direction entry. Enter 1,3,7,or 9. Try again.\n");
    }
    return move;
}
#endif