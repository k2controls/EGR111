## Here are three very basic functions in C. 

1. **A function with no parameters and returns `void`:**

```c
#include <stdio.h>

// Function with no parameters and returns void
void greet() {
    printf("Hello, World!\n");
}
```

2. **A function with parameters but still returns `void`:**

```c
// Function with parameters and returns void
void printSum(int a, int b) {
    int sum = a + b;
    printf("The sum of %d and %d is: %d\n", a, b, sum);
}
```

3. **A function with parameters that returns a value:**

```c
// Function with parameters and returns a value
int multiply(int a, int b) {
    return a * b;
}
```

### Full example program using all three functions:

```c
#include <stdio.h>

// Function with no parameters and returns void
void greet() {
    printf("Hello, World!\n");
}

// Function with parameters and returns void
void printSum(int a, int b) {
    int sum = a + b;
    printf("The sum of %d and %d is: %d\n", a, b, sum);
}

// Function with parameters and returns a value
int multiply(int a, int b) {
    return a * b;
}

int main() {
    // Calling the function that returns void and has no parameters
    greet();

    // Calling the function that returns void and has parameters
    printSum(5, 3);

    // Calling the function that returns a value
    int result = multiply(4, 6);
    printf("The result of multiplying is: %d\n", result);

    return 0;
}
```

### Explanation:
- `greet()` prints a simple greeting message with no input parameters and returns `void`.
- `printSum()` takes two integer parameters, calculates their sum, and prints it, but it returns `void`.
- `multiply()` takes two integer parameters and returns their product as an integer.
