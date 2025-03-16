---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### [EGR111](../../) - [Sprint 4](../) - Week 10

**Session 1**

- Review of Week 09
  - Modified tasks.json and launch.json
  - use of makefile
    - issue/error if no bin directory or bin empty or bin in use
    - makefile - revised with new clean: functionality

```console
wget https://k2controls.github.io/EGR111/resources/makefile
```

- **Tic Tac Toe** - solution review
  - instructor will review implementation of functions specified during last week's session.
  - Q/A - how did you implement? Issues?

- **Tic Tac Toe with Board Pointer** 
  - In general, global variables should not be used.
    - Your goal should be to control access and modification
    - Ideally, all code is tested using Unit Tests. Tests cannot be constructed for functions that rely on global values.
- ttt_w_ptr
  - Instructor demo
  - Mult-file solution
  - Refactored prior Tic Tac Toe solution to use board pointers

- Week 10 project - Checkers
  - Requirement: Create a first version of checkers enabling Black and Red players to move their checkers to open spaces. **No Jump move required!**
  - Process:
    1. Download starter files
    2. Work with your partner to analyze starter solution. Add comments. Be prepared to share.
    3. Work on your own to implement code required for method stubs.

  - Install - create a chkrs directory in a week10 directory.
  - Copy the following starter code

```
wget https://k2controls.github.io/EGR111/sprint4/week10/chkrs/main.c
wget https://k2controls.github.io/EGR111/sprint4/week10/chkrs/checkers.h
wget https://k2controls.github.io/EGR111/sprint4/week10/chkrs/checkers.c

```

- Here's a video showing game play for this early version. Note that jumping is not implemented.
  <video src="chk_starter_video.mp4" controls title="Checkers Game Play"></video>

- Here's a [graphic](chkr_brd.pdf){:target='_blank'} showing checker starting positions and cell indexes. Note red position does not match existing code.
- Edit your make file and run the code. The B12 checker is moved. 
- Single step the code and not the methods provide as well as stub code used to move checker B12.
- Step 1 - The instructor will break you into teams. Complete the code review with your team member adding significant comments describing the code function.
- Step 2 - Implement a version 1 of the game that enables each player to select a checker and move it to an open space. See video for an example.
        
**Session 2**

<!-- - chkrs - version 1: move to open spaces
  - status/report out  
  - [chkr_brd.pdf](chkr_brd.pdf){:target='_blank'}
  - function review

- Unit testing
  - [Why Testable Code Matters](https://www.toptal.com/qa/how-to-write-testable-code-and-why-it-matters){:target='_blank'}
  - A very simple testing framework
    - [acutest](https://github.com/mity/acutest){:target='_blank'}
    - wget https://k2controls.github.io/EGR111/resources/acutest.h
  
  - A First Look: last week's *multiple_files*
    - copy week09's multi_files to week10
    - Use *wget* above to add acutest.h to *multi_files* folder
    - Modify the functions.h header file to the following
    - Always include the TESTING definition in the header. This allows you to easily switch between test mode and the normal run of main().
  
```C
#include <stdio.h>
#include <stdbool.h>

#define TESTING false

void function1();
void function2();
int add_two_nums(int a, int b);
```

3. Add the following definition to functions.c

```C
int add_two_nums(int a, int b)
{
    // int z = a + b;
    int z = a + b + 1;   //make this fail
    return z;
}
```

4. add test_functions.c

```C
#include "functions.h"

#if TESTING
#include "acutest.h"

void test_add_two(void)
{
    //arrange
    int m = 2;
    int n = 3;
    int p = 0;
    //act
    p = add_two_nums(m, n);
    //assert
    TEST_CHECK(p == 5);
}

// List of tests - key, value pairs with {NULL, NULL} termination.
TEST_LIST = {
    { "can_add_two", test_add_two },
    { NULL, NULL }
};

#endif
```

5. Modify main.c as shown below. You are making the main compilation conditional on the TESTING flag. This prevent multipl main() functions from being defined.
   
```C
#include "functions.h"

#if !TESTING    //not TESTING

int main()
{
    function1();
    function2();
    int z = add_two_nums(1,3);
    printf("%d\n", z);

    return 0;
}

#endif 
``` 

- Run solution with TESTING flag set to true
  - modify add function to pass
- Run solution with TESTING flag set to false --> -->

---

### Assignments
- Checkers - version 1 - basic checker moves

<!-- - Multiple Files with acutest testing   -->
