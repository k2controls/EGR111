#include <stdio.h>

// Swap using pass by value (does NOT work)
void swap_by_value(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    printf("Inside swap_by_value: x = %d, y = %d\n", x, y);  // Values are swapped locally inside the function
}

// Swap using pointers (works)
void swap_by_pointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("Inside swap_by_pointer: *x = %d, *y = %d\n", *x, *y);  // Values are swapped in memory, affecting the original variables
}

int main() {
    int a = 5, b = 10;

    // Demonstrate the failed swap by value
    printf("Before swap_by_value: a = %d, b = %d\n", a, b);
    swap_by_value(a, b);  // This won't change a or b
    printf("After swap_by_value: a = %d, b = %d\n\n", a, b);

    // Demonstrate the successful swap by pointer
    printf("Before swap_by_pointer: a = %d, b = %d\n", a, b);
    swap_by_pointer(&a, &b);  // This will change a and b using pointers
    printf("After swap_by_pointer: a = %d, b = %d\n", a, b);

    return 0;
}
