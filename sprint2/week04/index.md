---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### [EGR111](../../) - [Sprint 1](../) - Week 04

**Session 1**
- grocery_bill.c - code review
  - style
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

- Variables and Operators 

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
    - The modulus operator in C is used to find the remainder of the division of two integers
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
- Session 1 review
  - [Structure and Style](https://en.wikibooks.org/wiki/C_Programming/Structure_and_style){:target="_blank"}

- *Assigned:* time_convert.c
    - Use #define preprocessor directive as specified
    - Upper case used for constants. Lower case used for variables
    - Underscore character `_` used to separate words
    - Section code using white space
    - Brackets `{}` aligned at same tab 
    - Indentation used to identify code blocks

- Learn to Code with C (see Tools on Moodle)
  - CHAPTER TWO - VARIABLES & ARITHMETIC
  - Review!
  - Data Types in C
    - AI Prompt: "What data types are available in the C programming language?"
    - AI Prompt: "How many bytes of storage is used for an int data type in C language?"
  - scanf() review
    - [Simple Input and Output](https://en.wikibooks.org/wiki/C_Programming/Simple_input_and_output){:target="_blank"}
  - [Basic Operators](https://www.log2base2.com/C/operator/operator-in-c.html){:target="_blank"}

- *Assigned:* Tic Tac Toe Board solution
  - use the wget instruction below to copy the starter code into the directory. Complete the coding as directed.
    - wget https://k2controls.github.io/EGR111/sprint2/week04/tictactoe_brd.c

- *Assigned:* Smallest Bills solution
  - Create a solution that prompts the user to enter a dollar amount and then displays how to pay that amount using the smallest number of $20, $10, $5, and $1 bills.
  - You are using integers and integer division throughout, not floating-point numbers. 
  - Use the following to download starter code
    - wget https://k2controls.github.io/EGR111/sprint2/week04/smallest_bills.c

- **In-class Activity**
  - The instructor will review the Office Space Calculator found [here](https://www.squarefoot.com/office-space-calculator){:target="_blank"}.
  - The instructor will divide the class into teams using the Zoom breakout room feature.
  - Review the Calculator site with your team member
  - Have one team member create the solution file and then invite your partner to join using a Live Share link in the Zoom chat feature.
  - Create the office_space.c solution that reproduces the service of the office space calculator.
  - Add comments at the beginning identifying the project and listing the team member names.
  - Use the **#define** preprocessor macro and use this to specify space requirements for work space, private office, conference room, kitchen, and utility room. 
  - Set the space per employee to the Spacious value shown in the drop down.
  - Run and test your code. Use the website to validate your results.
  - Be sure both partners have a copy of the final code in this week's directory in the EGR111 workspace. 

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





