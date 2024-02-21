// Solar Panel Calculator - Version 2.0
// Refactors V1 solution to use functions
// main() function is provided. You create others as defined in main.
// Name: 
// Date: 
#include <stdio.h>
#include <ctype.h>  //research toupper()

const char BUILD_TYPE_RESIDENTIAL = 'R';
const char BUILD_TYPE_COMMERCIAL = 'C';
const int SIDEWALL_MIN = 30;
const int SIDEWALL_MAX = 120;
const int ENDWALL_MIN = 20;
const int ENDWALL_MAX = 60;

// TODO declare your functions here.
// Tell the compiler that each is a valid thing and specify its signature


void main(void)
{
    // Main function is provided. 
    // **No edits here.** The code is functional if you declare and define required functions.
    const int PANEL_WIDTH = 39;         // inches
    const int PANEL_HEIGHT_RES = 65;    // inches
    const int PANEL_HEIGHT_COM = 78;    // inches
    const int PANEL_WEIGHT_RES = 42;    // pounds
    const int PANEL_WEIGHT_COM = 50;    // pounds
    
    double sidewall, endwall;
    int panel_height, panel_weight;
    char build_type;
    int panel_count_vert, panel_count_hor, panel_count;

    printf("Solar Panel Calculator\n");
    printf("\n");

    sidewall = get_sidewall(); //valid user input using min and max
    endwall = get_endwall();  //valid user input using min and max
    
    build_type = get_build_type();
    panel_height = (build_type == BUILD_TYPE_COMMERCIAL)?PANEL_HEIGHT_COM:PANEL_HEIGHT_RES;
    panel_weight = (build_type == BUILD_TYPE_COMMERCIAL)?PANEL_WEIGHT_COM:PANEL_WEIGHT_RES; 
    
    panel_count_vert = get_panel_count(sidewall, endwall/2, PANEL_WIDTH, panel_height);
    panel_count_hor = get_panel_count(sidewall, endwall/2, panel_height, PANEL_WIDTH);

    panel_count = (panel_count_vert>=panel_count_hor)?panel_count_vert:panel_count_hor;
    double total_weight = 1.05 * panel_count * panel_weight;   // add 5% for mounting hardware
    double load = total_weight/(sidewall * endwall / 2 );
    
    display_output(panel_count, total_weight, load);
}

// TODO define your functions here.
