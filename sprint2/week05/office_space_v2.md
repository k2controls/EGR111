```C
// Assignment 3 - office space calculator --kek solution
//
// Reproduce the service available at https://www.squarefoot.com/office-space-calculator
// Use preprocessor macros to set the space requirements for work space, private office, 
// conference room, kitchen, and utility room. 
// Set the space per employee to the Spacious value shown in the drop down.
// Use the website to validate your solution.
//
// Keith E. Kelly
// 1/27/2023
#include <stdio.h>

int main(void)
{
    #define ECONOMY 100
    #define AVERAGE 150
    #define SPACIOUS 200

    // #define EMPLOYEE_SPACE SPACIOUS
    #define PRIVATE_OFFICE 150
    #define CONFERENCE_ROOM 250
    #define KITCHEN 200
    #define UTILITY_ROOM 300

    int num_of_employee, num_of_office, num_of_conf, num_of_kitchen, num_of_utility;
    int work_space, conf_space, office_space, kitchen_space, utility_space, total_space;
    int employee_space;
    char space_choice;

    printf("Office Space Calculator\n\n");

    printf("Enter E for economy office space, A for average office space, and S for spacious office space.\n");
    space_choice = getchar();
    switch (space_choice)
    {
        case 'E':
            employee_space = ECONOMY;
            break;
        case 'A':
            employee_space = AVERAGE;
            break;
        case 'S':
            employee_space = SPACIOUS;
            break;
        default:
            employee_space = -10000;
    }
    printf("Office space is set to %d sq ft.\n", employee_space);

    printf("Enter the number of each office asset required. Enter 0 if not required.\n\n");

    // input
    printf("Number of Employees: ");
    scanf("%d", &num_of_employee);
    printf("Private Office: ");
    scanf("%d", &num_of_office);
    printf("Conference Room: ");
    scanf("%d", &num_of_conf);
    printf("Kitchen: ");
    scanf("%d", &num_of_kitchen);
    printf("Utility Room: ");
    scanf("%d", &num_of_utility);

    // process
    // work_space = num_of_employee * EMPLOYEE_SPACE;
    work_space = num_of_employee * employee_space;
    office_space = num_of_office * PRIVATE_OFFICE;
    conf_space = num_of_conf * CONFERENCE_ROOM;
    kitchen_space = num_of_kitchen * KITCHEN;
    utility_space = num_of_utility * UTILITY_ROOM;
    total_space = work_space + office_space + conf_space + kitchen_space + utility_space;

    // output
    printf("\n");
    printf("Recommended Space: %d sqft\n\n", total_space);
    printf("Work Space: %d sqft\n", work_space);
    printf("Private Office (%d): %d sqft\n", num_of_office, office_space);
    printf("Conference Room (%d): %d sqft\n", num_of_conf, conf_space);
    printf("Kitchen (%d): %d sqft\n", num_of_kitchen, kitchen_space);
    printf("Utility Room (%d): %d sqft\n", num_of_utility, utility_space);
    printf("\n");

    return 0;
}
```