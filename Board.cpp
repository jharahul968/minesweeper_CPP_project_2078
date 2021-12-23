#include "Board.h"
#include <ctime>
#include <cmath>
#include <random>
#include <iomanip>
#include <iostream>
#include "global.h"
#include <cstdlib>


void Board :: boardInitializer (int fxc, int fyc)
{
    
    for (int i =0; i<Global::getglob_board_size(); i++)
    {
        for (int j = 0; j<Global::getglob_board_size(); j++)
        {
            hidden_board[i][j] = '-';
            display_board[i][j] = '-';

        }
        
    }
    srand(time (0));
    while (mines_count< Global::getglob_total_mines())
    {
       
        for (int i =0; i<Global::getglob_board_size(); i++)
        {
            for (int j= 0; j<Global::getglob_board_size(); j++)
            {
                // if (board[i][j] = '')
                // mines_count+=1;
                if (i == fxc && j== fyc)
                continue;
                random = rand()% (Global::getglob_board_size() * Global::getglob_board_size()) + 1;
                if (((random < (Global::getglob_total_mines() + 1)/4) || (random > Global::getglob_board_size()* Global::getglob_board_size() - Global::getglob_total_mines()/2)) &&  hidden_board[i][j]!='*')
                {
                    hidden_board[i][j] = '*';
                    mines_count+=1;
                    if (mines_count == Global::getglob_total_mines())
                    break;
                }
            }
            if (mines_count == Global::getglob_total_mines())
            break;
        }
    }
    //display();
        
 }

 int Board :: neighbouringMinesCount (int x, int y)
 {
/*
                Count all the mines in the 8 adjacent
                cells
        
                    N.W   N   N.E
                    \   |   /
                     \  |  /
                 W-----Cell------E
                      / | \
                     /  |  \
                    S.W    S   S.E
        
                Cell-->Current Cell (row, col)
                N -->  North        (row-1, col)
                S -->  South        (row+1, col)
                E -->  East         (row, col+1)
                W -->  West            (row, col-1)
                N.E--> North-East   (row-1, col+1)
                N.W--> North-West   (row-1, col-1)
                S.E--> South-East   (row+1, col+1)
                S.W--> South-West   (row+1, col-1)
        */


        mines = 0;
        //checking for north
        if (Global::validityChecker (x, y-1) ==1)
        {
            if (hidden_board [x][y-1] == '*')
            mines+=1;
        }
        //checking for north east
            if (Global::validityChecker (x+1, y-1) ==1)
        {
            if (hidden_board [x+1][y-1] == '*')
            mines+=1;
        }
        //checking for nothwest
                if (Global::validityChecker (x-1, y-1) ==1)
        {
            if (hidden_board [x-1][y-1] == '*')
            mines+=1;
        }
        //checking for east
                if (Global::validityChecker (x+1, y) ==1)
        {
            if (hidden_board [x+1][y] == '*')
            mines+=1;
        }
        //checking for west
                if (Global::validityChecker (x-1, y) ==1)
        {
            if (hidden_board [x-1][y] == '*')
            mines+=1;
        }
        //checking for south
                if (Global::validityChecker (x, y+1) ==1)
        {
            if (hidden_board [x][y+1] == '*')
            mines+=1;
        }
        //checking for south west
                if (Global::validityChecker (x-1, y+1) ==1)
        {
            if (hidden_board [x-1][y+1] == '*')
            mines+=1;
        }
        //checking for south east
                if (Global::validityChecker (x+1, y+1) ==1)
        {
            if (hidden_board [x+1][y+1] == '*')
            mines+=1;
        }
        return mines ;
    
 }
bool Board :: gameOverOrNot (int x1, int y1)
{
    if (hidden_board[x1][y1] == '*')
    return 1;
   
    else
    return 0;
}
