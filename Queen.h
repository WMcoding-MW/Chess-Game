/***************************************************************               
* Name: William Marks                                                          
* Email: wmark194@mtroyal.ca                                                   
* Course: COMP 1633, 001                                                       
* Assignment: 05 part 3                                                        
* Due date: April 13th, 2021                                                   
* Instructor name: Paul Pospisil                                               
* File name: Queen.h                                                         
*                                                                              
* PUBLIC METHOD SPECIFICATIONS:

*  Queen:
     Input: a boolean value indicating colour
     Actions: initalizes a Queen object by setting the colour to White or black
     Assumptions: none

*  getSymbol:
     Input: none
     Actions: returns the char symbol of the current piece
     Assumptions: Queen has been initialized

*  canMove:
     Input: current board object, old and new x-coordinates, old and new 
            y-coordinates
     Actions: checks if a Queen on the board is allowed to move from it's
              current position into the new position proposed. This is all
              of course depending on the rules of chess. 
     Assumptions: Queen and Board objects are initialized

*  clone:                                                                      
     Input: None                                                               
     Actions: duplicates the current Queen object and returns a pointer to    
              the new one                                                      
     Assumptions: Queen is initilaized     
*/
#ifndef QUEEN_H
#define QUEEN_H

class Piece;
#include "Board.h"
#include "Piece.h"
#include <iostream>
using namespace std;
#define WHITE true
#define BLACK false

class Queen: public Piece
{
public:
    Queen (bool col);
    ~Queen();
    char getSymbol() const; 
    bool canMove(const Board& b, int fromX, int fromY, int toX, int toY) const;
    PiecePtr clone() const;
};  

#endif
