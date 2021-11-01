/***************************************************************               
* Name: William Marks                                                          
* Email: wmark194@mtroyal.ca                                                   
* Course: COMP 1633, 001                                                       
* Assignment: 05 part 3                                                        
* Due date: April 13th, 2021                                                   
* Instructor name: Paul Pospisil                                               
* File name: Piece.h                                                         
*                                                                              
* PUBLIC METHOD SPECIFICATIONS:

*  Piece:
     Input: a boolean value indicating colour
     Actions: initalizes a Piece object by setting the colour to White or black
     Assumptions: none

*  getSymbol:
     Input: none
     Actions: returns the char symbol of the current piece
     Assumptions: Piece has been initialized

*  getColour:                                                                
     Input: none                                                               
     Actions: returns the boolean colour of the current piece           
     Assumptions: Piece has been initialized                                   
                                                
*  setHasMoved:
     Input: true or false, boolean value
     Actions: updates the hasMoved boolean of the current piece object
     Assumptions: Piece has been initialized

*  canMove:
     Input: current board object, old and new x-coordinates, old and new 
            y-coordinates
     Actions: checks if a piece on the board is allowed to move from it's
              current position into the new position proposed. This is all
              of course depending on the rules of chess. 
     Assumptions: Piece and Board objects are initialized
*/
#ifndef PIECE_H
#define PIECE_H

class Piece;
#include "Board.h"
#include <iostream>
using namespace std;
#define WHITE true
#define BLACK false

class Piece
{
public:
    Piece (bool col);
    virtual ~Piece();
    virtual char getSymbol() const = 0; 
    bool getColour() const;
     virtual void notifyMoved();
    virtual PiecePtr clone() const = 0;
    virtual bool canMove(const Board& b, int fromX, int fromY, int toX, int toY) const = 0;
protected:
    bool colour;
    bool hasMoved;
    bool isVertical (int fromX, int fromY, int toX, int toY) const;
    bool isHorizontal (int fromX, int fromY, int toX, int toY) const;
    bool isDiagonal (int fromX, int fromY, int toX, int toY) const;
    bool isForward (int fromX, int toX) const;
    int vertDistance (int fromX, int toX) const;
    int horizDistance (int fromY, int toY) const;
    bool isPathClear (const Board& b, int fromX, int fromY, int toX, int toY)
	const;
    bool checkDiagonal(const Board& b, int fromX, int fromY, int toX,
		       int toY) const;
    bool checkVerticalHorizontal(const Board& b, int fromX, int fromY,
                                    int toX, int toY) const;

};  

#endif
