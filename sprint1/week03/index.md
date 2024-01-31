---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### [EGR111](../../) - [Sprint 1](../) - Week 03 

**Session 1**
No class - kek at MICEC Conference



**Session 2**

- Week 02 Review
  - number systems worksheet

  - Review of RPi setup
    - VNC Remote Access
      - new host name (kek used EGR-SP24)
      - new password
      - Using Ethernet? Add .local to host name (example EGR.local)
      - Via Network/Wi-Fi? (example EGR-SP24)
      - Click save password option for easy access

  - C Lanugage
    - GCC compiler is installed by default in RPi OS

```console
  gcc --version
```

  - Visual Studio Code
    - Install on Pi os by kek
    - Here is bash command to install on new device

````console
  sudo apt install code
```
    
    - Use the following commands at a terminal prompt to launch vs code in the EGR111 workspace

```console
  cd EGR111
  code .
```
    - the "dot" refers to *this directory*

- Week 02 Pair Coding 
  - grocery_bill.c
  - time_convert.c


- [GitHub Account Setup](Git_GitHub.pdf){:target="_blank"} 
  - Work through this procedure with the instructor to set up your Git repository
  - Use this document to review concepts, instructions, and actions.

- Week 02 Pair Coding
  - Review existing code is either in Repl or EGR111_temp directory
    - grocery_bill.c
    - time_convert.c
  - create week01 and week02 directories in new EGR111 directory
  - copy existing coding to new EGR111/week02 directory

```console
cd EGR111_temp/week02
cp hello.c ~/EGR111/week02/hello.c
cp hello.c ../../EGR111/week02/c-f_convert.c
cp grocery_bill* ../EGR111/week02

```
  - stage, commit, and push week02 code
  - verify commit on GitHub site

<!-- -   
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
  


- Structure and Style (continued - see Session 1) 

- [Input and Output](https://www.log2base2.com/C/basic/printf-function-in-c.html){:target="_blank"}
  - printf statement
  - escape sequence
  - data types
  - variables
  - scanf
    - **Assigned:** - use the wget instruction below to copy the starter code into the directory. Complete the coding as directed.
      - wget https://k2controls.github.io/EGR111/sprint1/week03/tictactoe_brd.c 

- **Assigned**  
  - Use Google or other search to locate either a F->C or C->F temperature conversion program written in C.
  - create a temp_convert.c file in week03 and copy the code that you found.
  - Run the sample code in the IDE. Did it compile and run? Do you see the temp_convert binary?

- Commit and push all to your remote repo.
- Open your GitHub repo in a browser. Confirm you have pushed all required code. See Assignment section below for required files. It is alway okay if you have extra files that represent work completed during that week.
   -->


---

### Assignments

- Push all code to your GitHub Repository. Required files are shown below
  - EGR111
    - +week01
    - -week02
      - c_version
      - c_version.c
      - hello
      - hello.c
      - grocery_bill
      - grocery_bill.c
      - time_convert
      - time_convert.c
    - -week03
      - grocery_bill
      - grocery_bill.c (refactored)
      - time_convert
      - time_convert.c (refactored)
    .gitignore
    README.md

**Be sure to push your updates by the Sunday deadline.**