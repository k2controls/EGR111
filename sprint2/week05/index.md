---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### [EGR111](../../) - [Sprint 2](../) - Week 05 

## Session 1 ##

- pull grading form
 
- Week 04 Review
  - Office Calculator
    - student demo
    - instructor demo
  - Solar Panel Calculator
    - explicit casting of float to int
    - if/else structure for decision
    - student demo
    - instructor demo

- [explicit cast to int](https://www.guru99.com/c-type-casting.html){:target='_blank'}
- [selection structure for best fit](https://www.log2base2.com/C/control/if-statement-in-c.html){:target='_blank'}
- [format specifiers for float and double](https://stackoverflow.com/questions/35096537/c-printf-format-for-float){:target='_blank'}

- What's next - Program structure - statements
  - Selection (conditional)
    - if/else
    - switch
  - Interation (looping)
    - while, do, for
  - Jump
    - return
    - break, continue
    - goto  //DO NOT USE THIS


- Selection (conditional)
  - if/else, switch, ternary
  - [Grading solution](https://www.log2base2.com/C/control/nested-if-else-statement-in-c.html){:target='_blank'} - refactor
    - wget https://k2controls.github.io/EGR111/sprint2/week05/letter_grade.c
    - refactor letter grade
  - [switch structure](https://www.log2base2.com/C/control/switch-statement-in-c.html){:target='_blank'}
    - [switch](switch.md){:target='_blank'}
    - office_space_calc_v2 - refactored selection - version 2
  - [Ternary operator](https://www.log2base2.com/C/control/ternary-operator-in-c.html){:target='_blank'} 
    - solar_panel_calc_v2 - refactored for res/com selection

- [Iteration/Looping in C](https://www.thegeekstuff.com/2012/12/c-loops-examples){:target='_blank'}
  - [While loop](http://tpcg.io/1I3AXC){:target='_blank'}
  - [Do while](http://tpcg.io/CNWW6K){:target='_blank'}  
  - [For loop](http://tpcg.io/2FTSN7){:target='_blank'}

## Session 2 ##

- Session 1 Review
  - Selection/decisions - if/else
    - nested if, else if, else
    - logic operators - example if gender is male and age is greater than 18 then selective service registration required.
  - Iteration/looping
    - while
    - do while
    - for

- Textbook (see link in Moodle right pane)
  - [CHAPTER FOUR] - More advanced flow control
    - break
    - continue
  - [CHAPTER SIX] - Functions

  - [Functions - an introduction](https://www.log2base2.com/C/function/functions-in-c.html){:target='_blank'}  

    - Function Declaration: Before you can use a function, you must declare it. This tells the compiler about the function's name, return type, and parameters (if any).

    - Function Definition: This is where the actual code of the function resides. It specifies what the function does.

    - Function Call: To use a function, you call it from another function (like the main() function or another user-defined function). When called, the execution of the program jumps to the function definition, executes the code inside it, and returns to the point from where it was called.

 
- **Checker Move**
  - Move solution demonstrating conditional logic.
  - Instructor will use starter code to discuss functions
  - Create the required logic structure for correct move list.
 - [chkr_moves.c](chkr_moves.c)

```console
    wget https://k2controls.github.io/EGR111/sprint2/week05/chkr_moves.c
```

- boolean (bool or _Bool) datatype
  - AI Prompt: Please provide an overview of using the bool data type in C language.

```C
#include <stdbool.h> 
#include <stdio.h>
int main() 
{ 
  // review - true and false values
  int x;
  if (x)
    printf("true");
  x = -99;
  if (x)
    printf("true");
  x = 0;
  if (x)
    printf("true");
  else
    printf("false");

  bool a = true;
  bool b = false;
  if(a == 1)
    printf("It is true");
  if(b == 0)
    printf("B is false");
  if(a)
    printf("It is true");
  if(!b)
    printf("B is false");
  if(a && !b)
    printf("Is it true");
  return 0; 
}
``` 

- **In-class Pair Coding** 

- [RGB Converter Project](RGBConverter.pdf){:target='_blank'}
  - in-class, partner activity
  - use repl to create solution
  - download and test in your EGR111 environment

  
---

### Assignments
  - EGR111
    - +week01
    - +week02
    - +week03 (see week03 for required files)
    - +week04
    - -week05
      - chkr_moves
      - chkr_moves.c
      - letter_grade
      - letter_grade.c
      - rgb_color_convert
      - rgb_color_convert.c
    - gitignore
    - README.md

-  **Be sure to push your updates by the Sunday deadline.**
