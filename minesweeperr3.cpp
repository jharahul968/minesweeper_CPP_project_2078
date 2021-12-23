#include <iostream>
#include "global.h"
#include "Board.h"
#include "TheGame.h"
#include <iomanip>
#include <cmath>
#include <conio.h>
// #include <math.h>

bool Global::flag1 = false;
int Global::glob_board_size = 0;
int Global::glob_total_mines = 0;                   //gotta see this


 void  gameTutorial ()
 {
     std::cout <<std::endl<<std::endl<<std::endl<<"                                  -------------------------------------------------GAME TUTORIAL----------------------------------------"<<std::endl<<std::endl;
     std::cout <<"                                1   To select the mine enter the co-ordinate (row number followed by column number)."<<std::endl<<std::endl;
     std::cout <<"                                2   If you want to select mine in 10th row and 14th column, simply enter 10 followed by 14"<<std::endl<<std::endl;
     std::cout <<"                                3   For example, If you want to flag any cell, simply enter the negative row number and the column number of the mine you want to flag."<<std::endl<<std::endl;
     std::cout <<"                                4   For example, if you want to flag cell at 17th row and 1st column, then you may enter any of the following co-ordinate"<<std::endl<<std::endl;
     std::cout <<"                                        -17 followed by 1 or "<<std::endl;     
     std::cout <<"                                         17 followed by -1 or"<<std::endl;
     std::cout <<"                                        -17 followed by -1"<<std::endl<<std::endl;
     std::cout <<"                                5   You can't flag any cell in the first input."<<std::endl<<std::endl;
     std::cout <<"                                6   You have 3 lives."<<std::endl<<std::endl;
     std::cout <<"                                7   You can enter any string or character to quit the game at any stage which is absolutely discouraged."<<std::endl<<std::endl;

     std::cout <<"                                -------------------------------------------------Enjoy the game. All the best--------------------------------------"<<std::endl<<std::endl<<std::endl;
 }

 void showDisplayBoard (Board dispBboardy)   //friend function of Board
 {

     std::cout <<std::endl;

     std::cout <<"    ";
     for (int i=0; i<Global::getglob_board_size(); i++)

     {
         std::cout <<std::setw(8)<<i+1;
     }
     std::cout <<std::endl<<std::endl;
     for (int i = 0; i<Global:: getglob_board_size(); i++)
     {
         std::cout<<std::setw(3)<<i+1<<"   ";
         for (int j = 0; j<Global::getglob_board_size(); j++)
         {
             std::cout <<"|";
             std::cout <<"   "<<dispBboardy.display_board[i][j]<<"   ";
         }
         std::cout <<"|";
         std::cout <<std::endl;
         std::cout <<std::setw(7);
         for (int j = 0; j<(Global::getglob_board_size() +1); j++)
         {
             std::cout <<"|"<<"       ";

         }

         std::cout <<std::endl;

     }
 }
 void showHiddenBoard (Board hidBoardy)
 {
     std::cout <<"    ";
     for (int i=0; i<Global::getglob_board_size(); i++)

     {
         std::cout <<std::setw(8)<<i+1;
     }
     std::cout <<std::endl<<std::endl;
     for (int i = 0; i<Global::getglob_board_size(); i++)
     {
         std::cout<<std::setw(3)<<i+1<<"   ";
         for (int j = 0; j<Global::getglob_board_size(); j++)
         {
             std::cout <<"|";
             std::cout <<"   "<<hidBoardy.hidden_board[i][j]<<"   ";
         }
         std::cout <<"|";
         std::cout <<std::endl;
         std::cout <<std::setw(7);
         for (int j = 0; j<(Global::getglob_board_size()+1); j++)
         {
             std::cout <<"|"<<"       ";

         }

         std::cout <<std::endl;

     }
 }
 void valueAssigner (Board &brd, int p, int q, char chh='b') //default argument
 {

     if (p>=0 && q>=0 && Global::getflag1() ==0)
     {
         // std::cout <<"hami yaha xau"<<std::endl;
         brd.display_board[p][q] = chh;
         brd.hidden_board [p][q] = chh;
     }
     else
     {
         if (brd.display_board[abs(p)][abs(q)] == '-')
         {
             brd.display_board[abs(p)][abs(q)] = chh;
         }

         // board [abs(p)-1][abs(q)-1] = chh;
         else if (brd.display_board[abs(p)][abs(q)] == 'b')
         {
             brd.display_board[abs(p)][abs(q)] = '-';
         }
         else
         {
             std::cout <<"It makes no sense to flag cell"<<std::endl;
         }
     }
 }


int main ()
{
    // for first coordinate
    int fxcor=0, fycor=0, mines_no;
    char cha;
    User prat;
    TheGame game;
    gameTutorial();
    int lvl = prat.chooseLevel ();
    Board msb1 (lvl);
    prat.takeFirstInput(&fxcor, &fycor);
    msb1.boardInitializer(fxcor, fycor);
    //showHiddenBoard(msb1);
    mines_no = msb1.neighbouringMinesCount (fxcor , fycor);
    cha = char (mines_no + 48);
    valueAssigner (msb1, fxcor, fycor, cha);
    showDisplayBoard(msb1);
    
    // NOW IT STARTS IN A LOOP
    game.playGame(prat, msb1);
    
    system ("pause");
    return 0;
}