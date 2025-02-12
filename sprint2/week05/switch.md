```C
// switch statement 
#include <stdio.h>

void main()
{
    double point_grade;
    
    printf("Please enter grade value: ");
    scanf("%lf", &point_grade);
    
    printf("*** if selection ***\n");
    if (point_grade == 4.0)
        printf("Excellent");
    else if (point_grade == 3.5)
        printf("Very Good");
    else if (point_grade == 3.0)
        printf("Good");
    else if (point_grade == 2.5)
        printf("Above Average");
    else if (point_grade == 2.0)
        printf("Average");
    else if (point_grade == 1.5)
        printf("Below Average");
    else if (point_grade == 1.0)
        printf("Poor");
    else if (point_grade == 0.0)
        printf("Failing");
    else
        printf("Invalid Grade");
    
    printf("\n*** switch statement ***\n");
    // switch (point_grade) // error - must switch on int value. No double. No string.
    int grade = (int)point_grade;    //cast to int
    switch(grade)
    {
        case 4:
            printf("Excellent");
            break;
        case 3:
            printf("Good");
            break;
        case 2:
            printf("Average");
            break;
        case 1:
            printf("Poor");
            break;
        case 0:
            printf("Failing");
            break;
        default:
            printf("Invalid Grade");
    }

    printf("\n*** switch statement with fall through ***\n");
    switch (grade)
    {
        case 4:
        case 3:
        case 2:
        case 1:
            printf("Passing");
            break;
        case 0:
            printf("Failing");
            break;
        default:
            printf("Invalid Grade");
    }
    printf.5
    ("\n");
}
```