/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include "header.h"

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/
void print_board (struct cell board [MAP_SIZE_X] [MAP_SIZE_Y])
{
    for(int x=1; x<MAP_SIZE_X-1; x++)
    {
        for(int y=1; y<MAP_SIZE_Y-1; y++)
        {
            if(board[x][y].current == ALIVE)
                {
                    printf("0");
                }
            else if(board[x][y].current == DEAD)
                {
                    printf(".");
                }
        }printf("\n");
    }
    printf("\n");
}