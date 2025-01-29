---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### [EGR111](../../) - [Sprint 1](../) - Week 03

**Session 1**
- Note: No class next Monday, Jan 27. KEK is at a conference.

- Week 02 review 
  - Number systems binary, decimal, hex
  - [RPi Startup](../week01/006.RPiStartup.pdf){:target="_blank"}
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
    - Christian, Shane, Nick
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


<!-- 
- [Steps for C Program Execution](https://www.slideshare.net/rummanansari7355/steps-for-c-program-execution){:target="_blank"}
  
- [Visual Studio Code Introduction](../week01/008.VSCodeIntro.pdf){:target="_blank"}
  - wget https://k2controls.github.io/EGR111/sprint1/week02/hello.c
  - wget https://k2controls.github.io/EGR111/sprint1/week02/c_version.c
  - Complete the activity and verify the following files are in your week02 directory
    - c_version
    - c_version.c
    - hello
    - hello.c
  - Why use the RPi in EGR111
    - C/C++ is supported natively on the Raspberry Pi
    - Uses Linux operating system (OS)
      - ![Linux Market Share](LinuxMarketShare.png)
      - [Does Mac OS X use Linux?](https://stackoverflow.com/questions/24888954/does-mac-os-x-use-linux){:target="_blank"}
      - [What is Windows Subsystem for Linux](https://learn.microsoft.com/en-us/windows/wsl/about){:target="_blank"}
- VS Code on your workstation?
  -  [Visual Studio Code download](https://code.visualstudio.com/download){:target="_blank"}
  - [C/C++ for Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp){:target="_blank"}

**Session 2**

  - Chapter Two: [VARIABLES & ARITHMETIC](../../resources/Essentials_C_v1.pdf){:target="_blank"}
  - [Operators in C](https://www.geeksforgeeks.org/operators-in-c/){:target="_blank"}
  - [Operator Precedence and Associativity in C](https://www.geeksforgeeks.org/operator-precedence-and-associativity-in-c/){:target="_blank"}

  - The instructor will demo creating, running, and debugging the following using the [Replit](https://replit.com/~){:target="_blank"} site.
  - Prompt: Develop a program that converts temperature from Fahrenheit to Celsius and vice versa. The user should be able to choose the conversion direction and enter the temperature value.
  - Using scanf() function for user input
    - ChatGPT prompt: Please provide a basic overview of using the scanf function in C.
    - Operators 
    - Specific extension of int/int will be demonstrated.
    - left to right Associativity will be demonstrated.  
  - Code will be extended to use preprocessor #define 
  - Specific extension of int/int will be demonstrated.  

- The instructor will review the RPi setup from session 1
  - VNC Remote Access
    - new host name (kek used EGR)
    - new password
    - Using Ethernet? Add .local to host name (example EGR.local)
    - Via Network/Wi-Fi? (example EGR)
    - Click save password option for easy access

  - C Lanugage
    - GCC compiler is installed by default in RPi OS
    - gcc --version

  - Visual Studio Code
    - Use the following command at a terminal prompt
      - code .
      - the "dot" refers to *this directory*

- The instructor will demonstrate copying repl code to this week's directory on Pi. VS code edit, compile, run, and debug will be demonstrated.

- Pair coding using Zoom Breakouts
  - Grocery Bill Estimator
    - grocery_bill.c
    - use preprocessor #define to specify pricing for items
    - **Prompt:** Create a program where users can enter the quantity and price of various grocery items (like apples, bread, milk). The program should calculate and display the total cost, including a sales tax rate of 6%.

    -Time Conversion
      - time_convert.c
      - use preprocessor #define to specify 
        - SECONDS_PER_MINUTE
        - MINUTES_PER_HOUR
      - **Prompt:** Write a program that asks the user to enter a large number of seconds (e.g., 5000 seconds) and then converts and displays this time in the format of hours, minutes, and seconds. For example, 3665 seconds would be converted to 1 hour, 1 minute, and 5 seconds. -->

<!-- - Week 02 Review
  - ChatGPT?
  - number systems worksheet

- Review of RPi setup
  - VNC Remote Access
    - new host name (kek used EGR)
    - new password
    - Using Ethernet? Add .local to host name (example EGR.local)
    - Via Network/Wi-Fi? (example EGR)
    - Click save password option for easy access

- C Lanugage
  - GCC compiler is installed by default in RPi OS

- Visual Studio Code
  - Use the following command at a terminal prompt
    - code .
    - the "dot" refers to *this directory*

- [GitHub Account Setup](Git_GitHub.pdf){:target="_blank"} 
  - Work through this procedure with the instructor to set up your Git repository
  - Use this document to review concepts, instructions, and actions.

- Hello.c review from Week 02
  - commit week02 directory with hello and hello.c when complete
    - open integrated VS Code terminal
    - Move to wee02
    - Get hello code
      - wget https://k2controls.github.io/EGR111/sprint1/week02/hello.c
    - add comments as directed
    - commit
    - push
    - verify on GitHub site
- Create week03
  - Get c_version.c
    - wget https://k2controls.github.io/EGR111/sprint1/week02/c_version.c
  - commit and push
  
- [Structure and Style](https://en.wikibooks.org/wiki/C_Programming/Structure_and_style){:target="_blank"}
  - Use the wget instruction below to copy the starter code into the directory.
  -   wget https://k2controls.github.io/EGR111/sprint1/week03/style.c
   -->



