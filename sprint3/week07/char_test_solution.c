// This program gets characters from user
// and tests for upper, lower, and digit characters.
#include <stdio.h>
// #include <ctype.h>
#include <stdbool.h>

char input_char(void);
bool is_in_ascii_range(char min_char, char max_char, char test_char);
bool is_digit(char c);
bool is_upper(char c);
bool is_lower(char c);
bool is_other(char c);

void main(void)
{
    char test_char = '\0'; //null character
    //int digit_count, upper_count, lower_count;
    int digit_count = 0;
    int upper_count = 0;
    int lower_count = 0;
    int other_count = 0;

    printf("This program tests chars entered by user.\n");
    printf("Count of upper, lower, and digits is updated and reported.\n");
    printf("Enter q to quit.\n\n");

    while (test_char != 'q')
    {
        printf("Enter test character: ");
        test_char = input_char();
        if (is_lower(test_char))
            lower_count++;
        else if (is_upper(test_char))
            upper_count++;
        else if (is_digit(test_char))
            digit_count++;
        else if (is_other(test_char))
            other_count++;
        else
            other_count++;
    }
    printf("\n");
    printf("The number of lower characters entered is %d.\n", lower_count);
    printf("The number of upper characters entered is %d.\n", upper_count);
    printf("The number of digit characters entered is %d.\n", digit_count);
    printf("The number of other characters entered is %d.\n\n", other_count);
    
}

char input_char(void)
{
    //This function solves issues with capturing chars with scanf()
    //It does not take any parameters but returns a value.
    //An assignment operator is likely used when calling this function.
    //For example: char grade = input_char();
    char c = ' ';
    char return_char;
    while(c == ' ')             //strip leading spaces
        c =getchar();
    if (c == '\0' || c == '\n') //if null char or new line
        return_char = '\0';     //return null char
    else
        return_char = c;        //capture first character
    while (c != '\n')           //discard others until EOL
        c = getchar();    
    return return_char;
}

bool is_in_ascii_range(char min_char, char max_char, char test_char)
{
    return (min_char <= test_char && test_char <= max_char);
}

bool is_digit(char c)
{
    // return (is_in_ascii_range(0, 9, c));
    return (is_in_ascii_range('0', '9', c));
}

bool is_upper(char c)
{
    return (is_in_ascii_range('A', 'Z', c));
}

bool is_lower(char c)
{
    return (is_in_ascii_range('a', 'z', c));   
}

bool is_other(char c)
{
    return !(is_digit(c) || is_upper(c) || is_lower(c));
}
