// Checkers in C
// Version 2.0 pseudocode

//main

    // create board, checkers, players
    // while play again is true
        //make board
        //fill board
        //player is black
        //while not game over
            // draw board
            // check if board has jump
            // get valid checker from user
            // get valid move vector from user
            // if has jump
                //jump
            // else
                //move
            // check for second jump
            // if jump and has second jump
                // player continues
            // else
                // next player

        // show winner
        // check play again    


int* get_selected_checker_from_user(int* brd_ptr, int player, bool has_jump)

    // while not valid checker
        // get checker number
        // locate checker
        // if has_jump and cell has jump
            // return pointer to cell/checker
        // else if has and cell doe not have jump
            // inform user to select a different checker
        // else if cell has move
            // return pointer to cell/checker
        // else
            // no possible moves for checker. Select a different checker


int get_selected_move_vector_from_user(int* brd_ptr, int*chkr_ptr, bool has_jump)

    // while not valid move
        // get move vector from user
        // if has jump and is a valid jump
            // return move vector
        // else if has jum
            // inform use of invalid. A jump is required.
        // else if valid move
            // return move vector
        // else
            // inform use of invalid. A jump is required.
