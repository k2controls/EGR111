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

```console
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

- Create week03 directory
  - Search for sample C code (something simple)
  - Create/copy to week03
  - compile and run
  
- Commit and push all to your remote repo.
- Open your GitHub repo in a browser. Confirm you have pushed all required code. See Assignment section below for required files. It is alway okay if you have extra files that represent work completed during that week.


---

### Assignments

- Push all code to your GitHub Repository. Required files are shown below
  - EGR111
    - +week01
    - -week02
      - c_version
      - c_version.c
      - c-f_convert     (optional)
      - c-f_convert.c   (optional)
      - grocery_bill
      - grocery_bill.c
      - hello
      - hello.c
      - time_convert
      - time_convert.c
    - -week03
      - [your code sample]
      - [your code sample].c
    .gitignore
    README.md

**Be sure to push your updates by the Sunday deadline.**