```C

// Checker - get player
// demonstrates use of function return value
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

const char BLACK = 'b';
const char RED = 'r';
const char BLACK_KING = 'B';
const char RED_KING = 'R';

char get_player()
{
    char return_val = ' ';
    while (return_val != 'b' && return_val != 'r')
    {
        printf("Would you like to be black or red?\n");
        printf("Enter B or R: ");
        scanf(" %c", &return_val); // Notice the space before %c to skip any leftover newline
        return_val = tolower(return_val);
    }
}

void king_me(char player)
{
    // Function parameters are pass by value
    // This one does not work!
    player = toupper(player);
    printf("Player is now a king locally: %c\n", player);
}

char make_king(char player)
{
    return toupper(player);
}

void kinged(char *player_ptr)
{
    // Here we dereference the pointer, changing the value it points to
    *player_ptr = toupper(*player_ptr); // * is used here to "dereference" the pointer
}

bool is_king(char player)
{
    return (player == 'B' || player == 'R');
}

void main()
{
    printf("Functions demo\n\n");

    char player1 = get_player();

    bool king_test = is_king(player1);
    printf("\nIs player king? %d\n\n", king_test);

    king_me(player1);
    king_test = is_king(player1);
    printf("Is player updated to king? %d\n", king_test);
    printf("Player 1 = %c\n\n", player1);

    printf("\nKing player 1!\n");
    player1 = make_king(player1);
    printf("Player 1 = %c\n\n", player1);

    if (is_king(player1))
        printf("You have been Kinged!\n\n");

    // introduction to pointers
    char player2 = 'r';
    char *p_pointer = &player2; // & operator is "the address of"
    kinged(p_pointer);
    if (is_king(player2))
        printf("You have been Kinged!\n\n");
}

```
