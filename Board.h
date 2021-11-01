/***************************************************************     
* Name: William Marks                                                  
* Email: wmark194@mtroyal.ca                                            
* Course: COMP 1633, 001                                              
* Assignment: 05 part 3                                              
* Due date: April 13th, 2021                                         
* Instructor name: Paul Pospisil                                              
* File name: Board.h                                                  
*                                                                         
* PUBLIC METHOD SPECIFICATIONS:                                       

*  Board:
    Input: Nothing
    Actions: Initilizes a grid of size MAXROWS x MAXCOLS
    Assumptions: Nothing

*  Board:
    Input: A Board object
    Actions: Deep copies the board inputted onto the current board
    Assumptions: Board inputted is initialized

*  ~Board:
    Input: nothing
    Actions: Deallocates all pointer objects and sets every 
             position in the grid to NULL. Also prints each
             Position of a Piece in the format of "P <x> <y>"
    Assumptions: Board is initialized

*  move: 
    Input: current x and y values, and the new x and y
    Actions: if the inputted current positions are NULL
             then nothing is moved. If the new x and y
             is currently occupied then nothing is moved.
             if the new position is NULL, then current is
             set to NULL and the position is updated. 
   Assumptions: Board is initialized

*  place: 
    Input: a pointer to a Piece object, and the x and y where it will go
    Actions: if the x and y position in the grid is NULL, then a 
             The piece is placed there, if not then it is not. 
    Assumptions: Board is initalized

*  remove: 
    Input: x and y coordinates to be removed
    Actions: removes and deletes a pointer at the given position
             if the position is not NULL, if it is NULL, then 
             nothing gets removed.
    Assumptions: Board is initalized

*  write: 
    Input: an output steam
    Actions: Displays the grid to the user in neat and readable
             format.
    Assumption: board is initalized

*  Board& operator =:
     Input: a board object
     Actions: deletes and resets the current board object, 
              then make its equal to the inputted board
              through a deep copy.
     Assumptions: both boards are initialized 

*  isOccupied: 
     Input: an x and y coordinates, both of type integer
     Actions: Checks if a current spot on the board is occupied given an x 
              and y coordinate pair.
     Assumptions: Board is initialized

*  getPiece:
     Input: an x and y coordinates, both of type integer
     Actions: Checks if the current spot on the board is occupied and if so 
              returns a Pointer to the piece occupying that spot. If nothing is
              present NULL is returned.
     Assumptions: Board is initalized 

*/

#ifndef BOARD_H
#define BOARD_H

class Board;
#include "Piece.h"
#include <iostream>
using namespace std;
#define MAXROWS 8
#define MAXCOLS 8
typedef Piece* PiecePtr;

class Board
{
public:
    Board();
    Board (const Board& other);
    ~Board();
    bool move (int fromX, int fromY, int toX, int toY);
    bool place (const PiecePtr& p, int x, int y);
    bool remove (int x, int y);
    void write (ostream& out) const;
    bool isOccupied (int x, int y) const;
    PiecePtr getPiece(int x, int y) const;
    Board& operator= (const Board& other);
private:
    PiecePtr grid[MAXROWS][MAXCOLS];
    void initBoard();
    void clearBoard();
    void copyBoard(const Board& other);
};

ostream& operator<< (ostream& out, const Board& b);

#endif
