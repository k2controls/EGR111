#include <stdio.h>
// #define CONVERT_FACTOR 9.0/5.0
// #define CONVERT_OFFSET 32 

int main() 
{
    float celsius, fahrenheit;
    
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9.0/5.0) + 32;
    fahrenheit = celsius * 9.0/5.0 + 32;
    fahrenheit = celsius * 9/5 + 32;
    fahrenheit = 9/5 * celsius + 32; //wrong - int/int = int
    // fahrenheit = celsius * CONVERT_FACTOR + CONVERT_OFFSET;
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);

    return 0;
}