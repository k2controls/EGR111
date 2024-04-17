---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### [EGR111](../../) - [Sprint 5](../) - Week 13

**Schedule**
- Week 13
  - Session 1 
    - Checkers V2
      - Team standup
      - main() - program design
    
  - Session 2 
    - structs and unions
    - chkrs 3 with dynamic structs (instructor demo only)
- Week 14
  - Session 1 - Linked Lists 
  - Session 2 - OOPS, final project introduction
- Week 15
  - Session 1 - No class, final project working session
  - Session 2 - No class, final project due at end of the day    
  
**Session 1**
- Team standups - Checkers V2 on Kanban
- Checkers V2 - [main pseudocode](chkrsV2_main_pseudo.txt){:target='_blank'}
  - pair coding - V2 main implementation

**Session 2**

- Structures
  - [C Structures](https://www.geeksforgeeks.org/structures-c/?ref=lbp){:target='_blank'}

```C
typedef struct Checker
{
    int index;
    bool is_empty;
    bool is_black;
    bool is_red;
    bool is_king;
    char name[4];

} checker;
```  

- test_checker.c
- checker_factory.c

---

### Assignments
- Checkers V2 with main()

