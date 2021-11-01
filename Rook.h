/***************************************************************               
* Name: William Marks                                                          
* Email: wmark194@mtroyal.ca                                                   
* Course: COMP 1633, 001                                                       
* Assignment: 05 part 3                                                        
* Due date: April 13th, 2021                                                   
* Instructor name: Paul Pospisil                                               
* File name: Rook.h                                                         
*                                                                              
* PUBLIC METHOD SPECIFICATIONS:

*  Rook:
     Input: a boolean value indicating colour
     Actions: initalizes a Rook object by setting the colour to White or black
     Assumptions: none

*  getSymbol:
     Input: none
     Actions: returns the char symbol of the current piece
     Assumptions: Rook has been initialized

*  canMove:
     Input: current board object, old and new x-coordinates, old and new 
            y-coordinates
     Actions: checks if a rook on the board is allowed to move from it's
              current position into the new position proposed. This is all
              of course depending on the rules of chess. 
     Assumptions: Rook and Board objects are initialized
*  clone:                                                                      
     Input: None                                                               
     Actions: duplicates the current Rook object and returns a pointer to    
              the new one                                                      
     Assumptions: Rook is initilaized     
*/
#ifndef ROOK_H
#define ROOK_H

class Piece;
#include "Board.h"
#include "Piece.h"
#include <iostream>
using namespace std;
#define WHITE true
#define BLACK false

class Rook: public Piece
{
public:
    Rook (bool col);
    ~Rook();
    char getSymbol() const; 
    bool canMove(const Board& b, int fromX, int fromY, int toX, int toY) const;
    PiecePtr clone() const;
};  

#endif
