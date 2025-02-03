---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### [EGR111](../../) - [Sprint 1](../) - Week 04

**Session 1**
- grocery_bill.c - code review
  - syle
  - variable declaration and use
  - data types and format specifiers.
  - Yes! All pushed to remote GitHub repository.

- [Steps for C Program Execution](https://www.slideshare.net/rummanansari7355/steps-for-c-program-execution){:target="_blank"}
  
  1. **Introduction to Compilation and Program Execution**
  2. **The Compilation Process**
  3. **Linking Process**
  4. **Program Execution**
  5. **Debugging and Errors**

- C Language
  - GCC compiler is installed by default in RPi OS
    - gcc --version
    - compilation in the VS Code IDE - see task.json in the .vscode directory
    - Demo: using breakpoints and the debugger

- Variables and Operators - resources
  - Chapter Two: [VARIABLES & ARITHMETIC](../../resources/Essentials_C_v1.pdf){:target="_blank"}
  - [Operators in C](https://www.geeksforgeeks.org/operators-in-c/){:target="_blank"}
  - [Operator Precedence and Associativity in C](https://www.geeksforgeeks.org/operator-precedence-and-associativity-in-c/){:target="_blank"}

- Variables and Operators - Outline
### **1. Introduction to Variables in C**
   - **Data types**: 
     - **Primitive Types**: Integer (`int`), floating-point (`float`, `double`), and character (`char`).
     - **Modifiers**: `signed`, `unsigned`, `short`, `long`, and their impact on variable storage.
   - Syntax for declaring variables in C (e.g., `int x;`).
   - **Variable Initialization**:
   
### **2. Variable Scope and Lifetime**
   - **Local Variables**: Defined inside functions, scope limited to the function.
   - **Global Variables**: Defined outside functions, available throughout the program.
   - More on this later

### **3. Arithmetic Operators in C**
   - **Basic Arithmetic Operators**: (`+`, `-`, `*`, `/`, `%`).
   - **Precedence and Associativity**:
   - **Increment and Decrement Operators**: (`++`, `--`).
     - Difference between pre-increment (`++x`) and post-increment (`x++`).
  - See [Operators in C](https://www.geeksforgeeks.org/operators-in-c/){:target="_blank"}  

### **4. Type Conversion and Casting**
  - Revisit f-c_convert
    - **Implicit Type Conversion**: Automatic conversion by the compiler (e.g., from `int` to `float`).
      - fahrenheit = 68;
  - **Integer Division**
    - int temp_f = 72;
    - float temp_c = (temp_f -32) * 5/9;
   - **Explicit Type Casting**: Manually changing a variable’s type).
    - float temp_c = (temp_f -32) * (float)5/9;
   - **Potential issues**: Loss of precision when casting from `float` to `int`.

  - One more look at data types and conversion/casting.

```
wget https://k2controls.github.io/EGR111/sprint2/week04/c-f_convert.c
```
   
### **Pair coding using Live Share**
- Time Conversion
  - review operators
  - create time_convert.c in your week04 directory
  - Set breakpoints and use debugger
  - The following pairs as assigned
    - Shane, Nick, Christian
    - Alex, Lily
    - Ellington, Drew
    - Sahil, Jaron
    - Dylan?

    -Time Conversion
      - time_convert.c
      - use preprocessor #define to specify 
        - SECONDS_PER_MINUTE
        - MINUTES_PER_HOUR
      - **Prompt:** Write a program that asks the user to enter a large number of seconds (e.g., 5000 seconds) and then converts and displays this time in the format of hours, minutes, and seconds. For example, 3665 seconds would be converted to 1 hour, 1 minute, and 5 seconds. -->
  

**Session 2**
- 

---

### Assignments 
Push week04 updates to your remote repo
- EGR111
  - week02 
  - week03
  - week04
      - c-f_convert
      - c-f_convert.c
      - time_convert
      - time_convert.c
      - office_space_calc
      - office_space_calc.c
      - smallest_bills
      - smallest_bills.c
      - tictactoe_brd
      - tictactoe_brd.c





