---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### [EGR111](../../) - [Sprint 2](../) - Week 06

**Session 1**

- grading form update
- Any issues with sync? *Recall this fix from last week.*
  > *Enable Auto-Fetch:* VS Code has a setting to automatically fetch changes from the remote repository. Go to File > Preferences > Settings (or press Ctrl+,), then search for git.autofetch and enable it.

```console
git pull --rebase
git push --force
```

- Week 5 review
  - solar_panel_calc.c
  - rgb_color_convert.c

- [CHAPTER SIX] - Functions (Textbook -see link in Moodle right pane)

  - [Functions - an introduction](https://www.log2base2.com/C/function/functions-in-c.html){:target='_blank'}  

    - Function Declaration: Before you can use a function, you must declare it. This tells the compiler about the function's name, return type, and parameters (if any).

    - Function Definition: This is where the actual code of the function resides. It specifies what the function does.

    - Function Call: To use a function, you call it from another function (like the main() function or another user-defined function). When called, the execution of the program jumps to the function definition, executes the code inside it, and returns to the point from where it was called.

  - [Example Functons](functions.md){:target='_blank'}

- **Checker Moves**
  - Move solution demonstrating conditional logic.
  - Instructor will use starter code to discuss functions
  - Create the required logic structure for correct move list.
 - [chkr_moves](chkr_moves.md){:target='_blank'}

```console
    wget https://k2controls.github.io/EGR111/sprint2/week06/chkr_moves.c
```

- **boolean** (bool or _Bool) datatype
  - AI Prompt: Please provide an overview of using the bool data type in C language.

[bool example](boolean.md)


**Session 2**

- [Functions - continued](https://www.geeksforgeeks.org/c-functions/){:target='_blank'}  

- Review **chkr_move.c** assignment - more
  - random number function
  - odd/even using Modulo operator
    - See [Modulo Operator (%)](https://www.geeksforgeeks.org/modulo-operator-in-c-cpp-with-examples/){:target='_blank'} for more. Note the selection between C++ and C demo code.
  - ternary operations used to determien RED, BLACK, and EMPTY
  - demo - debugger use
  - Checker Moves code both declares and defines functions prior to main()

- Separating function **declaration** and **definition** - demo 
  - [dec_bin_convert.c](dec_bin_convert.md){:target='_blank'}
  - wget https://k2controls.github.io/EGR111/sprint2/week06/dec_bin_convert.c


- **max_of_three.c**
  - Create a max_of_three.c file in this week's directory.
  - Declare a max_of_three function. (**before** your main() function)
  - Define a max_of_three function. (**after** your main() function)
  - The function accepts three integers as parameters.
  - The function determines the maximum value and returns this to the calling function.
  - *main()* - Call this function three times in your main() function using different arguments as specified below.
    1. Use the function to determine the maximum value of -99, -50, and -1.
    2. Use the function to determine the maxium value of characters z, Z, and ~. Be sure to display your result as character data.
    3. Review the use of the random number creation in checker_moves. Create three random numbers pass to your max function to determine the max value. Be sure to *seed* the random number generator using the time library. Again, see the checker code.


- **Solar Panel Functions- *Solar Panel Calc Refactored!***
  -[Solar Panel Functions](solar_panel_functions.md){:target='_blank'}
  - main() function is provided and identifies required functions.
  - Create the required function prototypes/declarations prior to main().
  - Create the required function definitions after main.

```console  
wget https://k2controls.github.io/EGR111/sprint2/week06/solar_panel_functions.c
```

---

### Assignments 
Push week05 updates to your remote repo
  - EGR111
    - +week01
    - +week02
    - +week03
    - +week04
    - +week05
    - -week06
      - chkr_moves
      - chkr_moves.c
      - max_of_three
      - max_of_three.c
      - solar_panel_functions
      - solar_panel_functions.c

    - gitignore
    - README.md





