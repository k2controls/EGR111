// EGR111 - unit tests for chkrs_linked
// Keith E. Kelly
// 4/19/2024

#include "checkers.h"

#if TESTING
#include "acutest.h"

void can_make_empty_board(void)
{
    board* brd_ptr = board_factory();
    
    space row1space1 = *brd_ptr->first_space_ptr;
    space row8space4 = *brd_ptr->last_space_ptr;
    TEST_CHECK(row1space1.row_num == 1);
    TEST_CHECK(row8space4.row_num == 8);
    
    board_dispose(brd_ptr);
}

void can_navigate_spaces(void)
{
    board* brd_ptr = board_factory();
    
    space row2space1 = *(brd_ptr->first_space_ptr
                            ->next_space_ptr
                            ->next_space_ptr
                            ->next_space_ptr
                            ->next_space_ptr);
    TEST_CHECK(row2space1.row_num == 2);
    space row7space4 = *(brd_ptr->last_space_ptr
        ->prior_space_ptr
        ->prior_space_ptr
        ->prior_space_ptr
        ->prior_space_ptr);
    TEST_CHECK(row7space4.row_num == 7);
    
    board_dispose(brd_ptr);
}

void can_access_adjacent_spaces(void)
{
    board* brd_ptr = board_factory();
    
    space* row1space1_ptr = brd_ptr->first_space_ptr;
    space* row1space2_ptr = brd_ptr->first_space_ptr->next_space_ptr;
    space row2space2 = *(brd_ptr->first_space_ptr
        ->next_space_ptr
        ->next_space_ptr
        ->next_space_ptr
        ->next_space_ptr
        ->next_space_ptr);
    TEST_CHECK(row2space2.adj_space_ul == row1space1_ptr);
    TEST_CHECK(row2space2.adj_space_ur == row1space2_ptr);
    
    space* row8space4_ptr = brd_ptr->last_space_ptr;
    space* row8space3_ptr = brd_ptr->last_space_ptr->prior_space_ptr;
    space  row7space3= *(brd_ptr->last_space_ptr
        ->prior_space_ptr
        ->prior_space_ptr
        ->prior_space_ptr
        ->prior_space_ptr
        ->prior_space_ptr);
    TEST_CHECK(row7space3.adj_space_dl == row8space3_ptr);
    TEST_CHECK(row7space3.adj_space_dr == row8space4_ptr);
    
    board_dispose(brd_ptr);
}

void can_fill_board(void)
{
    board* brd_ptr = board_factory();
    fill_board(brd_ptr);  

    space* row1space1_ptr = brd_ptr->first_space_ptr;
    checker checker1 = *row1space1_ptr->owner;
    TEST_CHECK(strcmp(checker1.name, " b1")==0);

    space* row1space2_ptr = brd_ptr->first_space_ptr->next_space_ptr;
    checker checker2 = *row1space2_ptr->owner;
    TEST_CHECK(strcmp(checker2.name, " b2")==0);

    space* row8space4_ptr = brd_ptr->last_space_ptr;
    checker checker3 = *row8space4_ptr->owner;
    TEST_CHECK(strcmp(checker3.name, " r1")==0);
    
    board_dispose(brd_ptr);
}

void can_locate_checker(void)
{
    board* brd_ptr = board_factory();
    fill_board(brd_ptr);  

    char chkr_name1[4] = "b12";
    locate_checker(brd_ptr, chkr_name1);
    TEST_CHECK(strcmp(brd_ptr->active_space_ptr->owner->name, "b12")==0);

    
    board_dispose(brd_ptr);
}

// List of tests - key, value pairs with {NULL, NULL} termination.
TEST_LIST = {
    // {"can make empty board", can_make_empty_board},
    // {"can navigate spaces", can_navigate_spaces},
    // {"can access adjacent spaces", can_access_adjacent_spaces},
    // {"can fill board", can_fill_board},
    {"can locate checker", can_locate_checker},

    {NULL, NULL}};

#endif
