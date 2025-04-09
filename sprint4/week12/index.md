---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### [EGR111](../../) - [Sprint 4](../) - Week 12


**Session 1**
- Week 11 - chkrs version 1
  - Required implementation of moves
    - get_checker_number
    - get_checker_position
    - has_moves
    - get_move_direction
    - get_next_position
    - etc
  - no unit testing used.

- Week 11 - Unit testing using acutest.h
  - ttt_testing

- Week 11 - [Strings in C](strings.md){:target='_blank'}

**Checkers with Jump(version 2)**
- Review of [game rules](checkers_rules.md){:target='_blank'}

- Version 2.0
  - includes jump and testing
  - kings moves implemented
  - kinging not implemented

  - [version 2 pseudo code](checkers_v2_pseudocode.md){:target='_blank'}


```
wget https://k2controls.github.io/EGR111/sprint4/week12/chkrs_v2/checkers.c
wget https://k2controls.github.io/EGR111/sprint4/week12/chkrs_v2/checkers.h
wget https://k2controls.github.io/EGR111/sprint4/week12/chkrs_v2/main.c
wget https://k2controls.github.io/EGR111/sprint4/week12/chkrs_v2/test_checkers.c
``` 

<!-- - Unit Tests
    - void can_make_checker_string(void)
    - void can_make_king_checker_string(void)
- Complete tests on your own - -->

- For Wednesday
  - Run game
  - Run tests (error at *can_jump_checker()*)
  - Complete/implement *is_valid_jump()*
  


**Session 2**

- **Checkers V2**
  - Review current game play
  - Review unit tests
    - Fails
      - jump not implemented - #TODO
      - comment out line 452,456 for now
      - 3 of 24 unit tests fail


- bitwise operations
```
      X	Y	||  X&Y	X|Y	X^Y
      0	0	||  0	  0	  0
      0	1	||  0	  1	  1
      1	0	||  0	  1	  1
      1	1	||  1	  1	  0
```

https://www.programiz.com/c-programming/bitwise-operators

- Review bitwise operations
  - [BitwiseDiscussion.xlsx](BitwiseDiscussion.xlsx)
  - Review checker flags - BLACK,RED, KING, NO_PLAY_CELL

```C
#define EMPTY_CELL_VALUE 0x00   // value for empty space
#define NO_PLAY_CELL_VALUE 0x80 // bit 7 flags no play space
#define KING_FLAG 0x40          // bit 6 is king flag
#define RED 0x20                // bit 5 is red flag
#define BLACK 0x10              // bit 4 is black flag
#define CHECKER_NUM_MIN 0x01    // first checker number is checker 1
#define CHECKER_NUM_MAX 0x0C    // last checker number is checker 12
// example: checker_id for last red as a king is 0x6C or 0110 1100
```

  - example: checker_id for last red (checker number 12) as a king is 0x6C or 0110 1100
    - 12 or'd with red or'd with king
    - 0x0C | 0x10 | 0x40
      -  0000 1100
      -  0010 0000
      -  0100 0000
      - *0110 1100*

  - Review fill black, fill red, is red, is black functions
  - Review can_check_if_king_cell

- chkrs_v2 requirements
  - Review move_checker function
  - Enter comments as required in checkers.c. Include initials.
  - Implement is_valid_jump function
  - Implement jump_checker function
  - Determine make_king requirements
  - Implement make_king function
  - Validate make_king() function using unit tests
    - Create can_make_red_king unit test
    - Create can_make_black_king unit test
- Assign v2 tasks to team members
- Team scrum/stand-up/status report next Monday

---

### Assignments
- - Checkers version 2 (with jump) - in progress 


