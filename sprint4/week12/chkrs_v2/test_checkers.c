// EGR111 - unit tests for chkrs_v2
// Keith E. Kelly
// 4/8/2024

#include "checkers.h"

#if TESTING
#include "acutest.h"

void can_make_empty_board(void)
{
    // arrange
    int b[ROW_COUNT][COL_COUNT];
    int *b_ptr = &b[0][0];
    // act
    make_board(b_ptr);
    // assert
    for (int col = 0; col < COL_COUNT; col += 2)
    {
        for (int row = 0; row < ROW_COUNT; row += 2)
        {
            // even rows start with no play cell
            TEST_CHECK(*(b_ptr + row * COL_COUNT + col) == NO_PLAY_CELL_VALUE);
            TEST_CHECK(*(b_ptr + row * COL_COUNT + col + 1) == EMPTY_CELL_VALUE);
        }
        for (int row = 1; row < ROW_COUNT; row += 2)
        {
            // odd rows start with empty cell
            TEST_CHECK(*(b_ptr + row * COL_COUNT + col) == EMPTY_CELL_VALUE);
            TEST_CHECK(*(b_ptr + row * COL_COUNT + col + 1) == NO_PLAY_CELL_VALUE);
        }
    }
}

void can_fill_board(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int *b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);

    int chkr_num, chkr_id;
    int* chkr_ptr;
    int cell_idx;
    int blk_indexes[12] = CHECKER_INDEXES_BLK;
    int red_indexes[12] = CHECKER_INDEXES_RED;
    for (int i=0; i<12; i++)
    {
        chkr_num = i +1;
        //check black
        chkr_id = BLACK | chkr_num;
        chkr_ptr = locate_checker_cell(b_ptr, chkr_id);
        cell_idx = blk_indexes[i];
        TEST_CHECK(chkr_ptr == b_ptr + cell_idx);
        //check red
        chkr_id = RED | chkr_num;
        chkr_ptr = locate_checker_cell(b_ptr, chkr_id);
        cell_idx = red_indexes[i];
        TEST_CHECK(chkr_ptr == b_ptr + cell_idx);
    }
}

void can_check_for_valid_cell_pointer(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    int* cell_ptr1 = b_ptr;                 // first cell is 
    int* cell_ptr2 = cell_ptr1 - 1;         // invalid - out of range
    int* cell_ptr3 = b_ptr + CELL_COUNT-1;  // last cell
    int* cell_ptr4 = b_ptr + CELL_COUNT;    // invalid - out of range

    TEST_CHECK(is_valid_cell_ptr(b_ptr, cell_ptr1) == true);
    TEST_CHECK(is_valid_cell_ptr(b_ptr, cell_ptr2) == false);
    TEST_CHECK(is_valid_cell_ptr(b_ptr, cell_ptr3) == true);
    TEST_CHECK(is_valid_cell_ptr(b_ptr, cell_ptr4) == false);
}

void can_check_if_no_play_cell(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    
    int* cell_ptr1 = b_ptr;                 // first cell is NO_PLAY_CELL
    int* cell_ptr2 = cell_ptr1 + 1;         // second cell is checker cell
    int* cell_ptr3 = b_ptr + CELL_COUNT-1;  // last cell is NO_PLAY_CELL

    TEST_CHECK(is_no_play_cell(cell_ptr1) == true);
    TEST_CHECK(is_no_play_cell(cell_ptr2) == false);
    TEST_CHECK(is_no_play_cell(cell_ptr3) == true);
}

void can_check_if_cell_occupied(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);

    int* cell_ptr1 = b_ptr;                 // first cell is NO_PLAY_CELL
    int* cell_ptr2 = cell_ptr1 + 1;         // second cell is valid
    int* cell_ptr3 = b_ptr + CELL_COUNT-1;  // last cell is NO_PLAY_CELL
    int* cell_ptr4 = b_ptr + 62;            // last valid cell

    TEST_CHECK(is_cell_occupied(cell_ptr1) == false);
    TEST_CHECK(is_cell_occupied(cell_ptr2) == true);
    TEST_CHECK(is_cell_occupied(cell_ptr3) == false);
    TEST_CHECK(is_cell_occupied(cell_ptr4) == true);
}

void can_check_if_empty_cell(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    int* cell_ptr1 = b_ptr;                 // first cell is NO_PLAY_CELL
    int* cell_ptr2 = b_ptr + 1;             // second cell is full
    int* cell_ptr3 = b_ptr + 24;            // first empty
    int* cell_ptr4 = b_ptr + 39;            // last empty
    int* cell_ptr5 = b_ptr + 62;            // last valid cell is full

    TEST_CHECK(is_empty_cell(cell_ptr1) == false);
    TEST_CHECK(is_empty_cell(cell_ptr2) == false);
    TEST_CHECK(is_empty_cell(cell_ptr3) == true);
    TEST_CHECK(is_empty_cell(cell_ptr4) == true);
    TEST_CHECK(is_empty_cell(cell_ptr5) == false);
}

void can_check_if_black_cell(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    int* cell_ptr1 = b_ptr;                 // first cell is NO_PLAY_CELL
    int* cell_ptr2 = b_ptr + 1;             // is BLACK cell
    int* cell_ptr3 = b_ptr + 24;            // is empty EMPTY_CELL
    int* cell_ptr4 = b_ptr + 62;            // is RED cell

    TEST_CHECK(is_black_cell(cell_ptr1) == false);
    TEST_CHECK(is_black_cell(cell_ptr2) == true);
    TEST_CHECK(is_black_cell(cell_ptr3) == false);
    TEST_CHECK(is_black_cell(cell_ptr4) == false);
}    

void can_check_if_red_cell(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    int* cell_ptr1 = b_ptr;                 // first cell is NO_PLAY_CELL
    int* cell_ptr2 = cell_ptr1 + 1;         // is BLACK cell
    int* cell_ptr3 = b_ptr + 24;            // is empty EMPTY_CELL
    int* cell_ptr4 = b_ptr + 62;            // is RED cell

    TEST_CHECK(is_red_cell(cell_ptr1) == false);
    TEST_CHECK(is_red_cell(cell_ptr2) == false);
    TEST_CHECK(is_red_cell(cell_ptr3) == false);
    TEST_CHECK(is_red_cell(cell_ptr4) == true);
}

void can_check_if_king_cell(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    int* cell_ptr0 = b_ptr;                 // is NO_PLAY_CELL
    int* cell_ptr1 = b_ptr + 1;             // is BLACK cell
    int* cell_ptr2 = b_ptr + 3;             // is BLACK cell
    int* cell_ptr3 = b_ptr + 60;            // is RED cell
    int* cell_ptr4 = b_ptr + 62;            // is RED cell
    int* cell_ptr5 = b_ptr + 24;            // is EMPTY_CELL

    *cell_ptr2 = *cell_ptr2 | KING_FLAG;    // use bitwise OR to set bit 4
    *cell_ptr4 = *cell_ptr2 | KING_FLAG;    // use bitwise OR to set bit 4

    TEST_CHECK(is_king_cell(cell_ptr0) == false);
    TEST_CHECK(is_king_cell(cell_ptr1) == false);
    TEST_CHECK(is_king_cell(cell_ptr2) == true);
    TEST_CHECK(is_king_cell(cell_ptr3) == false);
    TEST_CHECK(is_king_cell(cell_ptr4) == true);
    TEST_CHECK(is_king_cell(cell_ptr5) == false);
}

void can_check_if_foe_cell(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    int* cell_ptr1 = b_ptr;                 // first cell is NO_PLAY_CELL
    int* cell_ptr2 = cell_ptr1 + 1;         // is BLACK cell
    int* cell_ptr3 = b_ptr + 24;            // is empty EMPTY_CELL
    int* cell_ptr4 = b_ptr + 62;            // is RED cell

    TEST_CHECK(is_foe_cell(cell_ptr1, BLACK) == false);
    TEST_CHECK(is_foe_cell(cell_ptr2, BLACK) == false);
    TEST_CHECK(is_foe_cell(cell_ptr2, RED) == true);
    TEST_CHECK(is_foe_cell(cell_ptr3, BLACK) == false);
    TEST_CHECK(is_foe_cell(cell_ptr3, RED) == false);
    TEST_CHECK(is_foe_cell(cell_ptr4, BLACK) == true);
    TEST_CHECK(is_foe_cell(cell_ptr4, RED) == false);
}

void can_check_if_valid_checker_number(void)
{
    // valid checker nums are 1 through 12 (user values). 
    // color flag (+/-) is internal
    // king flag (0x10) is internal
    int chk_num1 = 0;       // invalid
    int chk_num2 = 1;       // valid
    int chk_num3 = 12;      // valid
    int chk_num4 = 13;       // invalid

    TEST_CHECK(is_valid_checker_num(chk_num1) == false);
    TEST_CHECK(is_valid_checker_num(chk_num2) == true);
    TEST_CHECK(is_valid_checker_num(chk_num3) == true);
    TEST_CHECK(is_valid_checker_num(chk_num4) == false);
}

void can_check_if_valid_checker_id(void)
{
    // valid checker nums are 1 through 12
    // but ID adds color bit and possibly KING_FLAG 
    int chk_num1 = 0;       // invalid
    int chk_num2 = 1;       // valid
    int chk_num3 = 12;      // valid
    int chk_num4 = 13;      // invalid
 
    // check black id
    TEST_CHECK(is_valid_checker_id(chk_num1 | BLACK) == false);
    TEST_CHECK(is_valid_checker_id(chk_num2 | BLACK) == true);
    TEST_CHECK(is_valid_checker_id(chk_num3 | BLACK) == true);
    TEST_CHECK(is_valid_checker_id(chk_num4 | BLACK) == false);
    // check red id
    TEST_CHECK(is_valid_checker_id(chk_num1 | RED) == false);
    TEST_CHECK(is_valid_checker_id(chk_num2 | RED) == true);
    TEST_CHECK(is_valid_checker_id(chk_num3 | RED) == true);
    TEST_CHECK(is_valid_checker_id(chk_num4 | RED) == false);

    // check black king id
    TEST_CHECK(is_valid_checker_id(chk_num1 | BLACK | KING_FLAG) == false);
    TEST_CHECK(is_valid_checker_id(chk_num2 | BLACK | KING_FLAG) == true);
    TEST_CHECK(is_valid_checker_id(chk_num3 | BLACK | KING_FLAG) == true);
    TEST_CHECK(is_valid_checker_id(chk_num4 | BLACK | KING_FLAG) == false);
    // check red king id
    TEST_CHECK(is_valid_checker_id(chk_num1 | RED | KING_FLAG) == false);
    TEST_CHECK(is_valid_checker_id(chk_num2 | RED | KING_FLAG) == true);
    TEST_CHECK(is_valid_checker_id(chk_num3 | RED | KING_FLAG) == true);
    TEST_CHECK(is_valid_checker_id(chk_num4 | RED | KING_FLAG) == false);
}

void can_check_if_checker_is_on_board(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    int chkr_id_blk =  1 | BLACK;
    int chkr_id_red = 12 | RED;
    int chkr_id_blk_king = chkr_id_blk | KING_FLAG;
    int chkr_id_red_king = chkr_id_red | KING_FLAG;

    TEST_CHECK(is_checker_on_board(b_ptr, chkr_id_blk) == true);
    TEST_CHECK(is_checker_on_board(b_ptr, chkr_id_red) == true);
    TEST_CHECK(is_checker_on_board(b_ptr, chkr_id_blk_king) == false);
    TEST_CHECK(is_checker_on_board(b_ptr, chkr_id_red_king) == false);
    // king first checker
    *(b_ptr+1) = *(b_ptr+1) | KING_FLAG;
    TEST_CHECK(*(b_ptr+1) == chkr_id_blk_king);
    TEST_CHECK(is_checker_on_board(b_ptr, chkr_id_blk_king) == true);
    // remove first checker
    *(b_ptr+1) = EMPTY_CELL_VALUE;
    TEST_CHECK(is_checker_on_board(b_ptr, chkr_id_blk) == false);
    TEST_CHECK(is_checker_on_board(b_ptr, chkr_id_blk_king) == false);
}

void can_check_if_player_checker_is_on_board(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    int chkr_num1 = 1;
    int chkr_num2 = 12;
    int player = BLACK;
    
    TEST_CHECK(is_player_checker_on_board(b_ptr, player, chkr_num1) == true);
    TEST_CHECK(is_player_checker_on_board(b_ptr, player, chkr_num2) == true);
    *(b_ptr+1) = *(b_ptr+1) | KING_FLAG; // king first checker
    TEST_CHECK(is_player_checker_on_board(b_ptr, player, chkr_num1) == true);
    TEST_CHECK(is_player_checker_on_board(b_ptr, player, chkr_num2) == true);
    *(b_ptr+1) = EMPTY_CELL_VALUE;     // remove first checker
    TEST_CHECK(is_player_checker_on_board(b_ptr, player, chkr_num1) == false);
    TEST_CHECK(is_player_checker_on_board(b_ptr, player, chkr_num2) == true);
    player = RED;
    TEST_CHECK(is_player_checker_on_board(b_ptr, player, chkr_num1) == true);
    TEST_CHECK(is_player_checker_on_board(b_ptr, player, chkr_num2) == true);
}

void can_locate_checker_cell(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    int chkr_num = 1;
    // check black
    int chkr_id= BLACK | chkr_num;
    int* chkr_ptr = locate_checker_cell(b_ptr, chkr_id);
    TEST_CHECK(chkr_ptr == b_ptr+1);
    // check red    
    chkr_id = RED | chkr_num; 
    chkr_ptr = locate_checker_cell(b_ptr, chkr_id);
    TEST_CHECK(chkr_ptr == b_ptr+62);
    // check black king
    *(b_ptr+1) = *(b_ptr+1) | KING_FLAG; // king first checker
    chkr_id = KING_FLAG | BLACK | chkr_num;
    chkr_ptr = locate_checker_cell(b_ptr, chkr_id);
    TEST_CHECK(chkr_ptr == b_ptr+1);
    // check red king (no red king = NULL value returned)
    chkr_id = KING_FLAG | RED | chkr_num;
    chkr_ptr = locate_checker_cell(b_ptr, chkr_id); //no red king
    TEST_CHECK(chkr_ptr == INVALID_CELL_PTR); //NULL value - not on board
}

void can_locate_player_checker_cell(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    int chkr_num = 1;
    int player = BLACK;

    int* chkr_ptr = locate_player_checker_cell(b_ptr, player, chkr_num);
    TEST_CHECK(chkr_ptr == b_ptr+1);
    player = RED;
    chkr_ptr = locate_player_checker_cell(b_ptr, player, chkr_num);
    TEST_CHECK(chkr_ptr == b_ptr+62);
    player = BLACK;
    *(b_ptr+1) = *(b_ptr+1) | KING_FLAG; // king first checker
    chkr_ptr = locate_player_checker_cell(b_ptr, player, chkr_num);
    TEST_CHECK(chkr_ptr == b_ptr+1);
}

void can_get_cell_owner(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);

    int owner1 = get_cell_owner(b_ptr+0);    //no play cell - no owner
    int owner2 = get_cell_owner(b_ptr+1);    //black owner
    int owner3 = get_cell_owner(b_ptr+24);   //empty - no owner
    int owner4 = get_cell_owner(b_ptr+62);    // red owner

    TEST_CHECK(owner1==0);
    TEST_CHECK(owner2==BLACK);
    TEST_CHECK(owner3==0);
    TEST_CHECK(owner4==RED);
}

void can_get_next_cell_pointer(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    int* current_cell_ptr;
    int* next_cell_up_left;
    int* next_cell_up_right;
    int* next_cell_down_left;
    int* next_cell_down_right;
    
    current_cell_ptr = b_ptr + 10;
    next_cell_up_left = get_next_cell_ptr(b_ptr, current_cell_ptr, MOVE_UP_LEFT);
    next_cell_up_right = get_next_cell_ptr(b_ptr, current_cell_ptr, MOVE_UP_RIGHT);
    next_cell_down_left = get_next_cell_ptr(b_ptr, current_cell_ptr, MOVE_DOWN_LEFT);
    next_cell_down_right = get_next_cell_ptr(b_ptr, current_cell_ptr, MOVE_DOWN_RIGHT);
    TEST_CHECK(next_cell_up_left == current_cell_ptr-9);
    TEST_CHECK(next_cell_up_right == current_cell_ptr-7);
    TEST_CHECK(next_cell_down_left == current_cell_ptr+7);
    TEST_CHECK(next_cell_down_right == current_cell_ptr+9);

    current_cell_ptr = b_ptr + 56;  //corner cell
    next_cell_up_left = get_next_cell_ptr(b_ptr, current_cell_ptr, MOVE_UP_LEFT);
    next_cell_up_right = get_next_cell_ptr(b_ptr, current_cell_ptr, MOVE_UP_RIGHT);
    next_cell_down_left = get_next_cell_ptr(b_ptr, current_cell_ptr, MOVE_DOWN_LEFT);
    next_cell_down_right = get_next_cell_ptr(b_ptr, current_cell_ptr, MOVE_DOWN_RIGHT);
    TEST_CHECK(next_cell_up_left == INVALID_CELL_PTR);
    TEST_CHECK(next_cell_up_right == current_cell_ptr-7);
    TEST_CHECK(next_cell_down_left == INVALID_CELL_PTR);
    TEST_CHECK(next_cell_down_right == INVALID_CELL_PTR);
}

void can_move_checker(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    int* current_cell_ptr = b_ptr+46;
    int cell_value = *current_cell_ptr;
    int* new_cell_ptr = move_checker(b_ptr, current_cell_ptr, MOVE_UP_RIGHT);
    TEST_CHECK(new_cell_ptr==b_ptr+39);
    TEST_CHECK(*current_cell_ptr == EMPTY_CELL_VALUE);
    TEST_CHECK(*new_cell_ptr==cell_value);
    //check no move
    current_cell_ptr = b_ptr+39;
    cell_value = *current_cell_ptr;
    new_cell_ptr = move_checker(b_ptr, current_cell_ptr, MOVE_UP_RIGHT);
    TEST_CHECK(new_cell_ptr == INVALID_CELL_PTR); //no move
    TEST_CHECK(*current_cell_ptr == cell_value);
}    

void can_jump_checker(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    int* attack_cell_ptr = b_ptr+23;
    int attacker_value = *attack_cell_ptr;
    int* foe_cell_ptr = b_ptr+46;
    int* blocker_cell_ptr = b_ptr+44;
    foe_cell_ptr = move_checker(b_ptr, foe_cell_ptr, MOVE_UP_RIGHT);
    foe_cell_ptr = move_checker(b_ptr, foe_cell_ptr, MOVE_UP_LEFT);   //foe
    blocker_cell_ptr = move_checker(b_ptr, blocker_cell_ptr, MOVE_UP_RIGHT);
    TEST_CHECK(is_black_cell(attack_cell_ptr));
    TEST_CHECK(is_red_cell(foe_cell_ptr));      //foe
    TEST_CHECK(is_red_cell(blocker_cell_ptr));  //foe blocker
    int* new_position_ptr = jump_checker(b_ptr, attack_cell_ptr, MOVE_DOWN_LEFT);
    TEST_CHECK(new_position_ptr == INVALID_CELL_PTR);  //blocked
    move_checker(b_ptr, blocker_cell_ptr, MOVE_UP_LEFT); //remove blocker
    new_position_ptr = jump_checker(b_ptr, attack_cell_ptr, MOVE_DOWN_LEFT);
    TEST_CHECK(new_position_ptr == blocker_cell_ptr);
    TEST_CHECK(*attack_cell_ptr == EMPTY_CELL_VALUE);
    TEST_CHECK(*foe_cell_ptr == EMPTY_CELL_VALUE);
    TEST_CHECK(*new_position_ptr==attacker_value);
}  

void can_check_checker_for_move(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    TEST_CHECK(cell_has_move(b_ptr, b_ptr+1) == false);
    TEST_CHECK(cell_has_move(b_ptr, b_ptr+12) == false);
    TEST_CHECK(cell_has_move(b_ptr, b_ptr+23) == true);
    TEST_CHECK(cell_has_move(b_ptr, b_ptr+46) == true);
    //block move
    int* blocker = b_ptr+46;
    blocker = move_checker(b_ptr, blocker, MOVE_UP_RIGHT);
    blocker = move_checker(b_ptr, blocker, MOVE_UP_LEFT);
    TEST_CHECK(cell_has_move(b_ptr, b_ptr+23) == false);
    TEST_CHECK(cell_has_move(b_ptr, blocker) == false);
    //king red checker blocker and check for move
    *blocker = *blocker | KING_FLAG;
    TEST_CHECK(cell_has_move(b_ptr, blocker) == true);
}

void can_check_checker_for_jump(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);
    
    int* attacker = b_ptr+23;
    int* foe = b_ptr+46;
    int* blocker = b_ptr+44;
    TEST_CHECK(cell_has_jump(b_ptr, attacker) == false);
    //move foe to position
    foe = move_checker(b_ptr, foe, MOVE_UP_RIGHT);
    foe = move_checker(b_ptr, foe, MOVE_UP_LEFT);
    blocker = move_checker(b_ptr, blocker, MOVE_UP_RIGHT);
    TEST_CHECK(cell_has_jump(b_ptr, attacker) == false);
    // move blocker
    blocker = move_checker(b_ptr, blocker, MOVE_UP_LEFT);
    TEST_CHECK(cell_has_jump(b_ptr, attacker) == true);
}

void can_check_board_for_move(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);

    TEST_CHECK(board_has_move(b_ptr, BLACK) == true);
    TEST_CHECK(board_has_move(b_ptr, RED) == true);
    *(b_ptr+24) = RED;
    *(b_ptr+26) = RED;
    *(b_ptr+28) = RED;
    *(b_ptr+30) = RED;
    TEST_CHECK(board_has_move(b_ptr, BLACK) == false);
    TEST_CHECK(board_has_move(b_ptr, RED) == true);
}

void can_check_board_for_jump(void)
{
    int b[ROW_COUNT][COL_COUNT];
    int* b_ptr = &b[0][0];
    make_board(b_ptr);
    fill_board(b_ptr);

    TEST_CHECK(board_has_jump(b_ptr, BLACK) == false);
    TEST_CHECK(board_has_jump(b_ptr, RED) == false);
    move_checker(b_ptr, b_ptr+46, MOVE_UP_RIGHT);
    move_checker(b_ptr, b_ptr+39, MOVE_UP_LEFT);
    TEST_CHECK(board_has_jump(b_ptr, BLACK) == true);
    TEST_CHECK(board_has_jump(b_ptr, RED) == false);
}


// List of tests - key, value pairs with {NULL, NULL} termination.
TEST_LIST = {
    {"can make empty board", can_make_empty_board},
    {"can fill board", can_fill_board},
    { "can check for valid cell pointer", can_check_for_valid_cell_pointer },
    { "can_check_if_no_play_cell", can_check_if_no_play_cell },
    { "can_check_if_cell_occupied", can_check_if_cell_occupied },
    { "can_check_if_empty_cell", can_check_if_empty_cell },
    { "can_check_if_black_cell", can_check_if_black_cell },
    { "can_check_if_red_cell", can_check_if_red_cell },
    { "can_check_if_king_cell", can_check_if_king_cell },
    { "can_check_if_foe_cell", can_check_if_foe_cell },
    { "can_check_if_valid_checker_number", can_check_if_valid_checker_number },
    { "can_check_if_valid_checker_id", can_check_if_valid_checker_id },
    { "can_check_if_checker_is_on_board", can_check_if_checker_is_on_board },
    { "can_check_if_player_checker_is_on_board", can_check_if_player_checker_is_on_board },
    { "can_locate_checker_cell", can_locate_checker_cell },
    { "can_locate_player_checker_cell", can_locate_player_checker_cell },
    { "can_get_cell_owner", can_get_cell_owner },
    { "can_get_next_cell_pointer", can_get_next_cell_pointer },
    { "can_move_checker", can_move_checker },
    { "can_jump_checker", can_jump_checker },
    { "can_check_checker_for_move", can_check_checker_for_move },
    { "can_check_checker_for_jump", can_check_checker_for_jump },
    { "can_check_board_for_move", can_check_board_for_move },
    { "can_check_board_for_jump", can_check_board_for_jump },
    {NULL, NULL}};

#endif
