```C

// Checker Moves
// Create the required logic to list moves
// See class notes for use of random.
// 2/13/24  - Updated random for clarity. 
//          - Added get_random_checker()
//          - random code is commented out and is
//              activated during class discussion.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char BLACK = 'b';
const char RED = 'r';
const char EMPTY = ' ';

//default board status
char space_home = BLACK;
char space_up1_left1 = EMPTY;
char space_up2_left2 = BLACK;
char space_up1_right1 = RED;
char space_up2_right2 = EMPTY;

void display_board()
{
    printf("---------------------\n");
    printf("| %c |:::|   |:::| %c |\n", space_up2_left2, space_up2_right2 );
    printf("---------------------\n");
    printf("|:::| %c |:::| %c |:::|\n", space_up1_left1, space_up1_right1 );
    printf("---------------------\n");
    printf("|   |:::|[%c]|:::|   |\n", space_home );
    printf("---------------------\n\n");
}

// char get_random_checker()
// {
//     // 33% Black, 33% Red, 33% Empty
//     // rem == 1 is Black, rem = 2 is Red)
//     char checker = EMPTY;
//     int picker;

//     picker = rand();
//     if (picker%3==1)
//         checker = BLACK;
//     else if (picker%3==2)
//         checker = RED;

//     return checker;
// }

// void place_checkers()
// {
//     int picker;
//     // 50-50 black or red in home space
//     srand(time(0)); //seed random number generator
//     picker = rand();
//     space_home = (picker%2)? BLACK : RED;   //Modulus op - checking for odd/even
//     // space_up1_left1 = get_random_checker();
//     // space_up2_left2 = get_random_checker();
//     // space_up1_right1 = get_random_checker();
//     // space_up2_right2 = get_random_checker();
// }

void display_moves()    //TODO
{
    // Inspects values of board spaces and list possible
    // moves for home checker.
    printf("\n*** POSSIBLE MOVES ***\n");
    // TODO - create required logic/selection for valid moves
        printf("Jump left\n");    
        printf("Jump right\n");
        printf("Good move left\n");
        printf("Good move right\n");
        printf("Bad move left\n");
        printf("Bad move right\n");
}

int main()
{
    printf("Checker Moves - move solution demonstrating conditional logic.\n");
    // place_checkers();
    display_board();
    display_moves();
    printf("\n");

    return 0;
}

```