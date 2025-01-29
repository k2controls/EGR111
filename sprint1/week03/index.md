---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### [EGR111](../../) - [Sprint 1](../) - Week 03

**Session 1**
- Note: No class next Monday, Jan 27. KEK is at a conference.

**Session 2**
- Week 02 review 
  - Number systems binary, decimal, hex
  - Creating A Remote Connection - see Tools or Week02
    - hostname is nmc-pi.local with point to point Ethernet connection
    - hostname is nmc-pi with network connection
    - hostname can be changed by user but this is option
  - usename = pi, default password = changeme
    - pi is always the user
    - password should be changed for security

- Linux terminal - directories and files
  - create a directory: mkdir (example: mkdir my_temp_d)
  - move to a directory: cd   (example: cd my_temp_d)
  - move to parent: cd ..

- GitHub remote repository
  - See week02 link
  - Several still need to push week02 code
  - See Keith's local repositories

### **Visual Studio Code Workflow**
- VS Code 
  - create, run, debug, commit, and push
  - Open VS Code in your EGR111 workspace by entering the following in a terminal window.

```console
cd EGR111
code .
```
  - Synchronize changes with your remote. Your grading sheet should be viewable.

---

### **Introduction to C Programming Concepts**
  - Use Explorer to create week03 folder
  - Open a Terminal window in VS Code using the menu
  - Move to the week03 directory - *cd week03*
  - Pull sample code from the course site using *wget* below

```
wget https://k2controls.github.io/EGR111/sprint1/week03/f-c_convert.c
```

- Goal of the program: converting a temperature value from Fahrenheit to Celsius.

### **Code Review Outline**

**Code Formatting and Style**
  - use `alt-shift-f` to auto format
    - On a Mac, `Option + Shift + F` (or **`⌥ + ⇧ + F`**)

This will automatically format the code in the currently active file according to the formatting rules specified in your settings. Let me know if you need further clarification or help with other shortcuts!
  - code "style" or conventions
    - our standard for {} code block is to have { on the line following main. See auto format.
    - add white space between code sections. See instructor's sample.

1. **Line 1: `#include <stdio.h>`**
  - **Concept**: Preprocessor Directives
  - **Explanation**: The `#include` directive is used to include external libraries. Here, we include `stdio.h`, which contains functions for input/output operations like `printf()` and `scanf()`.
  - See [Preprocessing](https://www.log2base2.com/C/basic/preprocessor-in-c.html)

2. **Line 3: `int main()`**
   - **Concept**: Main Function
   - **Explanation**: Every C program must have a `main()` function, which is the entry point of the program. The return type `int` indicates that this function returns an integer value.

3. **Line 5: `float fahrenheit, celsius;`**
   - **Concept**: Variable Declaration
   - **Explanation**: Variables are declared with a specified data type. Here, `fahrenheit` and `celsius` are both declared as `float`, indicating that they will store decimal values.

4. **Line 7: `printf("Enter temperature in Fahrenheit: ");`**
   - **Concept**: Output (printf)
   - **Explanation**: The `printf()` function is used to print output to the console. The string inside the parentheses is displayed to the user, prompting them to enter a temperature in Fahrenheit.

5. **Line 8: `fahrenheit = 68.0;  //todo replace with scanf()`**
   - **Concept**: Variable Assignment and Commenting
   - **Explanation**: Here, we assign the value 68.0 to the `fahrenheit` variable. The `//todo` comment indicates that this line should be replaced with a user input method (like `scanf()`).
   - **Discussion**: Talk about `float` as a data type for decimal numbers and why `68.0` is used instead of `68` to make it clear that the variable can store fractional numbers.

6. **Line 10: `celsius = (fahrenheit - 32) * 5.0/9.0;`**
   - **Concept**: Arithmetic Operations and Order of Operations
   - **Explanation**: This line calculates the temperature in Celsius using the formula:  
     \[
     \text{Celsius} = \left(\text{Fahrenheit} - 32\right) \times \frac{5.0}{9.0}
     \]
     - Discuss the use of subtraction, multiplication, and division in the expression.
     - Explain how `5.0/9.0` is used to force floating-point division (otherwise, integer division would be performed).

7. **Line 12: `printf("Temperature in Celsius: %.2f\n", celsius);`**
   - **Concept**: Formatted Output (printf with format specifiers)
   - **Explanation**: The `%.2f` format specifier is used to print the `celsius` value with two decimal places. The `\n` at the end ensures that the output moves to the next line after displaying the result.
   - **Discussion**: Explain how to format floating-point numbers and the significance of `%.2f` (showing 2 decimal places).

8. **Line 13: `return 0;`**
   - **Concept**: Returning from `main`
   - **Explanation**: The `return 0;` statement indicates that the program executed successfully. The return value of `0` is commonly used to indicate that the program finished without errors.

9. **End of Program**
   - **Concept**: Program Structure
   - **Explanation**: The closing brace `}` marks the end of the `main()` function and the program.

### **Key Points to Emphasize During the Talk**
- **Data Types**: `int` vs. `float` and how they store different kinds of values.
- **Operators**: Arithmetic operators (`+`, `-`, `*`, `/`) and their precedence in expressions.
- **Functions**: `printf()` for output, and later, the potential for `scanf()` for input.
- **Comments**: The role of comments (like `//todo`) in guiding code improvement or keeping track of tasks.
  
### **Next Steps for the Class**
- Replace the hard-coded Fahrenheit value with a user input using `scanf()`.

### **Introduction to `scanf()` in C**

`scanf()` is a standard library function used for taking input from the user. It reads data from the standard input (usually the keyboard) and stores it in the specified variables.

### **Basic Syntax:**
```c
scanf("format specifier", &variable);
```

- The first argument is a **format specifier**, which tells `scanf()` the type of input expected.
- The second argument is the **memory address** of the variable where the input will be stored. This is why we use the address-of operator `&`.

### **Common Format Specifiers:**
1. **`%d`**: Reads an integer value.
   - Example: 
     ```c
     int age;
     printf("Enter your age: ");
     scanf("%d", &age);
     printf("You entered: %d\n", age);
     ```

2. **`%f`**: Reads a floating-point number (e.g., `float` or `double`).
   - Example: 
     ```c
     float temperature;
     printf("Enter temperature in Fahrenheit: ");
     scanf("%f", &temperature);
     printf("You entered: %.2f\n", temperature);
     ```

### **Example: Replacing the Hardcoded Temperature Value**
In your temperature conversion program, we previously hardcoded the Fahrenheit value. Here's how to replace it with `scanf()` to allow the user to input their own value:

```c
printf("Enter temperature in Fahrenheit: ");
scanf("%f", &fahrenheit);
```

- This allows the user to enter a floating-point value, and the program will store it in the `fahrenheit` variable.


---

### **Steps to Install Visual Studio Code Live Share Extension**

1. **Access the Extensions Marketplace**:
   - On the left-hand side, click on the **Extensions** icon.

2. **Search for "Live Share"**:
   - In the Extensions Marketplace search bar, type "Live Share."

3. **Install the Live Share Extension**:
   - Find **"Live Share"** in the search results and click the **Install** button next to it.

7. **Sign In**:
   - After installation, you can sign in with your **GitHub** account to sync your settings and share sessions more easily.

8. **Start a Live Share Session**:
   - To begin pair coding, open your project in VS Code.
   - Click the **Live Share** button on the status bar (bottom-left) and select **Start Collaboration Session**.
   - Use Zoom chat to share the session link with your partner (students or collaborators).

---

### **Joining a Live Share Session:**
- If you're joining a session, your partner will share the link with you.
- Click the link, and it will open the session in your VS Code, where you'll be able to code together in real-time.

---

### **Pair coding using Live Share**
- Grocery Bill Estimator
  - create grocery_bill.c in your week03 directory
  - The following pairs as assigned
    - Christian, Dylan
    - Shane, Nick
    - Alex, Lily
    - Ellington, Drew
    - Sahil, Jaron
    
  - **Prompt:** Create a program where users can enter the quantity and price of various grocery items (like apples, bread, milk). The program should calculate and display the total cost, including a sales tax rate of 6%.

  - Determine which partner (Partner 1) will create the session and which will be joining the share (Partner 2 and 3?).
  - Follow along as the instructor demonstrates the shared coding experience.
  - Complete the required coding as directed.
  - The solution output must be similar to the following

```console
Enter the quantity of apples: 4
Enter the quantity of bread: 2
Enter the quantity of milk: 3

Grocery Bill Breakdown:
Apples: $6.00
Bread: $4.00
Milk: $9.75
Sales Tax (6%): $0.90
Total Cost: $20.65
```
- Final shared code will need to be copied to Partner 2's repo. The instructor will demonstrate.

---

### Assignments 
Push week03 updates to your remote repo
- EGR111
  - week02 
  - week03
      - grocery_bill
      - grocery_bill.c
      - f-c_convert
      - f-c_convert.c

