/***************************************************************************
 *   Copyright (C) 2021 by Jere Takala
 *   e1900491@edu.vamk.fi
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************
*
* 1.  NAME
*       game_of_life.c
*
* 2.  DESCRIPTION
*       
*
* 3.  VERSIONS
*       Original:
*         17.4.2021 / jere
*
*       Version history:
*       $Log$
*
**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include "header.h"

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/
int main (void)
{
    FILE *fp;
    char state_c;
    int x, y, c, r;
    int state, future;
    struct cell board [MAP_SIZE_X] [MAP_SIZE_Y] = {0,0}; //x,y
    
    /*board[4][1].current = 1;
    board[2][3].current = 1;
    board[3][3].current = 1;
    board[4][4].current = 1;
    board[5][4].current = 1;
    board[4][5].current = 1;
    board[5][5].current = 1;*/
    c=0;    r=0;
    fp = fopen("game.txt", "r");
    while (!feof(fp)) 
    {
        fscanf(fp,"%c", &state_c);
        state = state_c - '0';

        board[r][c].current = state;
        c++;

        if (c > MAP_SIZE_Y)
            {
            r++;
            c = 0;
                        /* reads the newline characters away */
           /* fscanf(fp,"%c",&state_c); /* reads newline from file */

            //#ifdef WINDOWS

            //fscanf(fp,"%c",&state_c); /* reads carriage return from file in case of Windows */
            //#endif
            }
    }

    for(int i=1; i<10; ++i)
    {
        print_board(board);
        count_neighbors(board);
        for(int x=1; x<MAP_SIZE_X-1; x++)
        {
            for(int y=1; y<MAP_SIZE_Y-1; y++)
            {
                board[x][y].current = board[x][y].future;
            }
        }
        //print_board(board);
        
        sleep(2);
    }

    return 0;
}/* end of main */