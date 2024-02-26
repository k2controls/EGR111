// function prototypes
#include <stdio.h>
#include <math.h>

void my_function1(void)
{
    // printf("This could be declared as 'void my_function1()'\n");
    // printf("This function does not take any input (parameters).\n");
    // printf("This function does not return any value to the caller.\n");
    // printf("No return statement at the end.\n");
    printf("Testing!\n");
}

void max_char(char character1, char character2)
{
    //This function has two parameters of type char.
    //It requires that two char arguments be passed in when called.
    //Recall that parameters are passed by value (copies).
    //Parameters have local scope. They only exist inside the function.
    char max_char, min_char;
    if (character1 > character2)
    {
        max_char = character1;
        min_char = character2;
    }
    else
    {
        max_char = character2;
        min_char = character1;   
    }   
    printf("The value of character %c is greater than the value of character %c.\n", max_char, min_char);
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

double hypotenuse(double x, double y) 
{
    //This function accepts two parameters and returns a value.
    //Again, an assignment operator is likely used
    //A variable will need to store the result
    // *** linker error for math.h (searched VS Code linking math.h)
    // see https://stackoverflow.com/questions/60579406/how-do-i-build-and-run-c-files-that-use-math-h-functions-in-vscode
    // add -lm to tasks.json
    double z = sqrt(x * x + y * y);
    return z;
}

void swap_does_not_work(int a, int b)
{
    //FROM LAST WEEK - params are passed by value!
    //Classic demo of incorrect assumptions with params
    int c = a;
    a = b;
    b = c;
}

void main(void)
{
    my_function1();
    my_function1();
    printf("\n");

    max_char('$', '^');
    printf("\n");
    
    printf("Input a character: ");
    char c1 = input_char();
    printf("Input a second character: ");
    char c2 = input_char();
    max_char(c1, c2);
    printf("\n");

    double a, b, c;
    a = 3.0;
    b = 4.0;
    c = hypotenuse(a, b);
    printf("Hypotenuse of a right triangle with legs (%lf, %lf) is %lf\n\n", a, b, c);

    int m = 999;
    int n = 111;
    printf("m=%d, n=%d\n", m, n);
    swap_does_not_work(m, n);
    printf("swapped? - m=%d, n=%d\n\n", m, n);

}