// tic tac toe using array values
//       O | X | O
//      -----------
//       O | X | X
//      -----------
//       X | O | X
//
//  Name: Keith E. Kelly
//  Date: 1/21/23
//**********************************************

#include <stdio.h>

int main(void)
{

    printf("Board 3c\n");
    
    char c1, c2, c3, c4, c5, c6, c7, c8, c9;
    c1 = c3 = c4 = c8 = 'O';
    c2 = c5 = c6 = c7 = c9 = 'X';

    printf(
        "\t\t %c | %c | %c\n"
        "\t\t-----------\n"
        "\t\t %c | %c | %c\n"
        "\t\t-----------\n"
        "\t\t %c | %c | %c\n"
        , c1, c2, c3, c4, c5, c6, c7, c8, c9);

    return 0;
}    


