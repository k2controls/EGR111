#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef TESTING

#define TESTING false


//*********** data definitions ****************/
typedef struct PlaySpace
{
    int space_index;        //0 through 63
    nonplayspace* l_nps;    //left nonplayspace
    nonplayspace* r_nps;    //right nonplayspace

    playspace* ur_ps;       //up right playspace
    playspace* ul_ps;       //up left playspace
    playspace* dr_ps;       //down right playspace
    playspace* dl_ps;       //down left playspace
    
    checker* owner;         //pointer to checker on ps
} playspace;

typedef struct NonePlaySpace
{
    int space_index;        //0 through 63
    playspace* r_ps;        //right playspace
    playspace* l_ps;        //left playspace
} nonplayspace;

typedef struct Checker
{
    int board_index;
    int number;
    bool is_empty;
    bool is_black;
    bool is_red;
    bool is_king;
    char name[4];
    int action_count;
    int actions[4];
    int move_count;
    struct Checker** move_cell_ptrs[4];
    int jump_count;
    struct Checker** jump_cell_ptrs[4];

} checker;

//*********** functions ****************/
nonplayspace** board_factory();
void* row_factory(int row_index);

nonplayspace* nonplayspace_factory(int space_index, playspace* left_playspace, playspace* right_playspace);
void nonplayspace_dispose(nonplayspace* nonplayspace_ptr);
playspace* playspace_factory(int space_index, nonplayspace* left_nonplayspace, nonplayspace* right_nonplayspace);
void playspace_dispose(playspace* playspace_ptr);


#endif

