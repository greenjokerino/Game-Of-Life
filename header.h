/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES                                                *
*--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */
#define MAP_SIZE_X 11
#define MAP_SIZE_Y 26

enum status {DEAD,ALIVE};
/* Globaal variables */

/* Globaal structures */
struct cell
{
    int current;    /* Current situation, which is visible on screen */
    int future;     /* Temporary calculation area for next round calculation */
    int neighbour;  /* Neighbours of the cell */
};

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void print_board (struct cell board [MAP_SIZE_X] [MAP_SIZE_Y]);
int count_neighbors (struct cell board [MAP_SIZE_X] [MAP_SIZE_Y]);
int calculate_game (struct cell board [MAP_SIZE_X] [MAP_SIZE_Y]);