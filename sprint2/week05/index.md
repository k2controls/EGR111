---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### [EGR111](../../) - [Sprint 2](../) - Week 05

**Session 1**

- *Enable Auto-Fetch:* VS Code has a setting to automatically fetch changes from the remote repository. Go to File > Preferences > Settings (or press Ctrl+,), then search for git.autofetch and enable it.

- Unable to sync? Enter the following at the terminal prompt.

```console
git pull --rebase
git push --force
```

- Week 4 review
  - Tic Tac Toe Board solution
  - Smallest Bills solution
  - Office Space Calculator solution

- [Implicit and Explicit Type Conversion (typecasting)](https://www.guru99.com/c-type-casting.html){:target='_blank'}

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

- Use of the #define macro and the *const* qualifier.
  - [https://www.freecodecamp.org/news/constants-in-c-explained-how-to-use-define-and-const-keyword/](https://www.freecodecamp.org/news/constants-in-c-explained-how-to-use-define-and-const-keyword/){:target='_blank'}

- [Selection Structure](https://www.log2base2.com/C/control/if-statement-in-c.html){:target='_blank'}
  - Chapter 3 - see text in Tools
  - [Grading solution](https://www.log2base2.com/C/control/nested-if-else-statement-in-c.html){:target='_blank'} - refactor
       - refactor letter grade

```
 wget https://k2controls.github.io/EGR111/sprint2/week05/letter_grade.c
```

  - Refactor Office Space

- This week assignments
  - [Solar Panel Calculator](SolarPanelCalculator.pdf){:target="_blank"}
  - break-out - discuss requirements and approach to Solar Panel Calculator


**Session 2**

- Program Structure - Flow Controls - continued
  - Chapter 4 in text - see Tools section
  - Selection (conditional)
  - if/else - see Session 1
    - Grading solution
  - [switch structure](https://www.log2base2.com/C/control/switch-statement-in-c.html){:target='_blank'}
    - [switch](switch.md){:target='_blank'}
    - [office_space_v2](office_space_v2.md){:target='_blank'}   
      - refactored selection - version 2
  - [Ternary operator](https://www.log2base2.com/C/control/ternary-operator-in-c.html){:target='_blank'} 

- [Iteration/Looping in C](https://www.thegeekstuff.com/2012/12/c-loops-examples){:target='_blank'}
  - [While loop](http://tpcg.io/1I3AXC){:target='_blank'}
  - [Do while](http://tpcg.io/CNWW6K){:target='_blank'}  
  - [For loop](http://tpcg.io/2FTSN7){:target='_blank'}

- **In-class Pair Coding** 

- [RGB Converter Project](RGBConverter.pdf){:target='_blank'}
  - in-class, partner activity
  - Partner(s) - be sure to download solution into your EGR111 workspace
  - Review format specifiers for scanf() (Hex input)
    - Consider this line of code.

```C
scanf("%c%02x%02x%02x", &rgb_delimiter, &r, &g, &b);
```     

---

### Assignments 
Push week05 updates to your remote repo
  - EGR111
    - +week01
    - +week02
    - +week03
    - +week04
    - -week05
      - letter_grade
      - letter_grade.c
      - rgb_color_convert
      - rgb_color_convert.c
      - solar_panel_calc
      - solar_panel_calc.c
    - gitignore
    - README.md





