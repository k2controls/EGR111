---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### [EGR111](../../) - [Sprint 1](../) - Week 02

**Session 1**
- Note: No class next Monday, Jan 27. KEK is at a conference.

- Week 01 review - [number systems](https://www.log2base2.com/number-system/decimal-number-system.html){:target="_blank"} 
  - use programmer calculator
  - Convert binary 0000 0100 1100 1001 to decimal
  - Convert octal 000 177 to decimal
  - Covert hexadecimal FA to decimal
  - Distinct binary numbers given n bits?  2<sup>n</sup>
  - Largest binary number? 2<sup>n</sup> - 1
  - **Assigned:** - [Number systems worksheet](hexadecimaloctalnumbersystems.docx)

- A first look a C code
  - [https://replit.com/languages/c](https://replit.com/languages/c){:target="_blank"}

<!-- #include <stdio.h>

int main() 
{
  printf("Keith says...");
  printf("Hello World\n");
  // the is a comment
  /* the is a multi line comment
  a second line*/  
  return 0;
} -->

resources/CreatingARemoteConnection.pdf
- Raspberry Pi Startup
  - [Creating A Remote Connection](../../resources/CreatingARemoteConnection.pdf){:target="_blank"} 
    - Note: RealVNC VNC Viewer is no longer used
    - See Creating a Remote Connection for updated TigerVNC connection
    - Connection status? - report-out

- [Introduction to Linux](007.LinuxIntro.pdf){:target="_blank"} (Instructor Demo Only)

- [Introduction to VS Code](008.VSCodeIntro.pdf){:target="_blank"} 

- Git, GitHub introduction
  - [https://github.com/](https://github.com/){:target="_blank"}
  - [Git Hub Introduction and Setup](Git_GitHub.pdf){:target="_blank"}





**Session 2**
  

<!-- 

- computer system review - loading OS, software


- [RPi Startup](../week01/006.RPiStartup.pdf){:target="_blank"}
  - hostname is raspberrypi.local (assuming Ethernet connection)
  - usename = pi, password = changeme
  - Update hostname - example EGR_SP24
  - Change password (if you forget, you start over!)
  - Reboot and reconnect with save password checked
- Linux terminal - directories and files
  - create EGR111_temp  (mkdir)
  - move to EGR111_temp  (cd)
  - create week01 and week02 subdirectories
- [Steps for C Program Execution](https://www.slideshare.net/rummanansari7355/steps-for-c-program-execution){:target="_blank"}
  - [Preprocessing](https://www.log2base2.com/C/basic/preprocessor-in-c.html)
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

---

### Assignments 
- Number systems worksheet - submit to Moodle link
- Workspace on Pi *(not submitted at this time)*
  - EGR111_temp
    - week01
    - week02
      - c_version
      - c_version.c
      - hello
      - hello.c
      - grocery_bill
      - grocery_bill.c
      - time_convert
      - time_convert.c



