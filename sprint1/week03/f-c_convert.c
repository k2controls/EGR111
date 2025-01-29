#include <stdio.h>

int main() {
    float fahrenheit, celsius;
    printf("Enter temperature in Fahrenheit: ");
    fahrenheit = 68.0;  //todo replace with scanf()
    celsius = (fahrenheit - 32) * 5.0/9.0;
    printf("Temperature in Celsius: %.2f\n", celsius);
    return 0;
}
