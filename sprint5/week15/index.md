---
layout: default
---
## EGR 111 - Introduction to Computer Science (C Programming)n

### [EGR](../../) - [Sprint 5](../) - Week 15

**Revised schedule**
- Week 15
  - Session 1 - No class, final project working session
  - Session 2 - No class, final project due at end of the day    

**Final Project - Simple BlackJack**
- [About BlackJack](about_blackjack.md)
- Simple BlackJack solution
  - Only 1 hit allowed so hand has maximum of 3 cards.
  - Player presses spacebar to "hit", taking the third card.
  - Dealer must "hit" (take third card) if hand value is 16 or under.
  
- Create a sblackjack folder in a week15 folder of your code repository.
- Copy the code provided to the sblackjack directory.
    
```
wget https://k2controls.github.io/EGR111/sprint5/week15/sblackjack/main.c
wget https://k2controls.github.io/EGR111/sprint5/week15/sblackjack/sblackjack.c
wget https://k2controls.github.io/EGR111/sprint5/week15/sblackjack/sblackjack.h
wget https://k2controls.github.io/EGR111/sprint5/week15/sblackjack/test_sblackjack.c

```
 
- add/copy acutest.h to the sblackjack solution directory.

- Review the solution files provided.
  - The sblackjack.h file provides all required declarations including the TESTING flag used to swap between the main and test code.
  - The sblackjack.c file contains required function definitions but many have #TODO requiring you to create the code required for implementation.
  - The test_sblackjack file contains unit tests for all functions declared in the sblackjack.h file. This file is complete and does not require additions or modification.
  - The main.c file contains most of the main code to play the Simple BlackJack game. It **does not** include the "hit" code required for both player and dealer. See TODO comments.
  - Directions
    - Access the sblackjack.c file and define/create the required code.
    - Test your sblackjack functions using the unit tests provided in the test_sblackjack.c file. See [SBlackJack Videos](sbj_videos.md){:target='_blank'} page for a video of the unit tests being successfully run.
    - With the required sblackjack functions defined, switch to the main function to test initial game play. The solution functions but is missing the "hit" operations for both player and dealer. See See [SBlackJack Videos](sbj_videos.md){:target='_blank'} page for a video of the initial game play without the required hit operations added.
    - Extend the main solution to implement the required "hit" operations. The player's hand is "hit" (a third card added) if he or she presses the space bar when prompted. The dealer is "hit" if the dealer's hand value is less than 17. See See [SBlackJack Videos](sbj_videos.md){:target='_blank'} page for a video of final game play with hit functions included.
    - Your completed final solutions must be pushed to your GitHub repository by the end of the day of Week 15 Session 2.
    - There are no class sessions during Week 15. This time is provided to complete the final project.


---

### Assignments

- The final project is assigned and is your final exam. 
    - You must do your own work. Respond to the Ethics Check in Moodle Week 15.
    - It must be pushed by Week 15 Session 2. 
    - Week 15 Session 1 is working session - no class.
    - You must complete the NMC course evaluation. See your NMC email.