/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include "header.h"

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/
int count_neighbors (struct cell board [MAP_SIZE_X] [MAP_SIZE_Y])
{
    int x, y;
    int neighbour=0, populated=1, unpopulated=0;
    
    for(x=1; x<MAP_SIZE_X-1; x++)
    {
        for(y=1; y<MAP_SIZE_Y-1; y++)
        {
            neighbour = board[x+1][y].current +    //Checks if cell has any cells around him in 3x3 area
                         board[x+1][y+1].current +
                         board[x][y+1].current +
                         board[x-1][y+1].current +
                         board[x-1][y].current +
                         board[x-1][y-1].current +
                         board[x][y-1].current +
                         board[x+1][y-1].current;
            //printf("%d",neighbour);
            
            if(board[x][y].current == populated)    //Space that is populated
            {
                if(neighbour == 1 || neighbour == 0)    //If 1 or 0 neighbors, dies to loneliness
                {
                    board[x][y].future = DEAD;
                }

                else if(neighbour >= 4)     //If 4 or more neighbors, dies to overpopulation
                {
                    board[x][y].future = DEAD;
                }
                
                else if(neighbour == 3 || neighbour == 2)     //If 2 or 3 neighbors, survives
                {
                    board[x][y].future = ALIVE;
                }
            }

            if(board[x][y].current == unpopulated && neighbour == 3)    //Space that is empty or unpopulated
                {
                    board[x][y].future = ALIVE;
                }
        }
    }
}