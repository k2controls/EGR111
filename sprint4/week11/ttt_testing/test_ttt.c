#include "tictactoe.h"

#if TESTING
#include "acutest.h"

void test_can_reset_board(void)
{
    //arrange
    char board[9];
    char* brd_ptr = &board[0];
    *(brd_ptr+4) = PLAYER_X;

    //act
    reset_board(brd_ptr);
    
    //assert
    for (int i=0; i<9; i++)
        TEST_CHECK(*(brd_ptr+i) == OPEN);
}

// show_directions not testable
// display_board not testable
// display_first_board();

void test_can_select_first_player()
{
    char player;
    player = select_first_player();
    TEST_CHECK(player==PLAYER_O || player==PLAYER_X);
}

void test_can_get_next_player()
{
    //Arrange
    char p1 = PLAYER_O;
    //Act
    char p2 = get_next_player(p1);
    //Assert
    TEST_CHECK(p2 == PLAYER_X);
    //Act
    p1 = get_next_player(p2);
    //Assert
    TEST_CHECK(p1 == PLAYER_O);
}

void test_check_is_win()
{
    char brd[9] =
    {
        PLAYER_X,PLAYER_O,PLAYER_O,
        PLAYER_X,PLAYER_O,PLAYER_O,
        PLAYER_O,PLAYER_X,PLAYER_X
    };
    TEST_CHECK(is_winner(&brd[0],PLAYER_X)==false);
    TEST_CHECK(is_winner(&brd[0],PLAYER_O)==false);
    brd[6] = PLAYER_X;
    TEST_CHECK(is_winner(&brd[0],PLAYER_X));
}

void test_is_hor_win()
{
    char brd[9] =
    {
        PLAYER_X,PLAYER_O,PLAYER_O,
        PLAYER_X,PLAYER_O,PLAYER_O,
        PLAYER_X,PLAYER_X,PLAYER_X
    };
    TEST_CHECK(is_hor_winner(&brd[0],PLAYER_X));
    brd[6] = PLAYER_O;
    brd[0] = PLAYER_O;
    TEST_CHECK(is_hor_winner(&brd[0],PLAYER_O));
    brd[0] = PLAYER_X;
    brd[3] = PLAYER_O;
    TEST_CHECK(is_hor_winner(&brd[0],PLAYER_O));
}

void test_is_ver_win()
{
    char brd[9] =
    {
        PLAYER_X,PLAYER_O,PLAYER_O,
        PLAYER_X,PLAYER_O,PLAYER_O,
        PLAYER_X,PLAYER_X,PLAYER_X
    };
    TEST_CHECK(is_ver_winner(&brd[0],PLAYER_X));
    brd[6] = PLAYER_O;
    brd[7] = PLAYER_O;
    TEST_CHECK(is_ver_winner(&brd[0],PLAYER_O));
    brd[7] = PLAYER_X;
    brd[8] = PLAYER_O;
    TEST_CHECK(is_ver_winner(&brd[0],PLAYER_O));
}

void test_is_diag_win()
{
    //arrange
    char brd[9] =
    {
        PLAYER_X,PLAYER_O,PLAYER_O,
        PLAYER_X,PLAYER_O,PLAYER_O,
        PLAYER_O,PLAYER_X,PLAYER_X
    };
    TEST_CHECK(is_diag_winner(&brd[0],PLAYER_O));
    brd[4] = PLAYER_X;
    TEST_CHECK(is_diag_winner(&brd[0],PLAYER_X));
}

void test_is_board_full()
{
    //arrange
    char brd[9] =
    {
        PLAYER_X,PLAYER_O,PLAYER_X,
        PLAYER_O,PLAYER_O,PLAYER_X,
        PLAYER_O,PLAYER_X,OPEN
    };
    //act
    TEST_CHECK(is_board_full(&brd[0])==false);
    brd[8] = PLAYER_O;
    TEST_CHECK(is_board_full(&brd[0])== true);
}

void test_is_valid_space()
{
    for (int row=0; row<3; row++)
        for (int col=0; col<3; col++)
            TEST_CHECK(is_space_valid(row*col));
}

void test_is_empty()
{
    //arrange
    char brd[9] =
    {
        OPEN,OPEN,OPEN,
        OPEN,OPEN,OPEN,
        OPEN,OPEN,OPEN
    };
    //act
    TEST_CHECK(is_space_empty(&brd[0],1));
    brd[1] = PLAYER_O;
    TEST_CHECK(is_space_empty(&brd[0],1)==false);
}

// is_valid_move tested by is_valid_space and is_empty
// play not testable
// show_cat not testable
// show_winner not testable

// List of tests - key, value pairs with {NULL, NULL} termination.
TEST_LIST = {
    { "can clear board", test_can_reset_board },
    { "can select first player", test_can_select_first_player },
    { "can get next player", test_can_get_next_player },
    { "can check for win", test_check_is_win },
    { "can check for row win", test_is_hor_win },
    { "can check for col win", test_is_ver_win },
    { "can check for diag win", test_is_diag_win },
    { "can check for cat", test_is_board_full },
    { "can test is valid space", test_is_valid_space },
    { "can test is space empty", test_is_empty },
    { NULL, NULL }
};

#endif