/***************************************************************               
* Name: William Marks                                                          
* Email: wmark194@mtroyal.ca                                                   
* Course: COMP 1633, 001                                                      
* Assignment: 05 part 3                                                        
* Due date: April 13th, 2021                                                   
* Instructor name: Paul Pospisil                                               
* File name: Piece.cpp                                                         
*                                                                              
*/
#include "Piece.h"
#include "Board.h"
#include "Bishop.h"
#include <cmath>

Bishop::Bishop (bool col) : Piece(col){

    colour = col;
    
}

Bishop::~Bishop(){

}

char Bishop::getSymbol() const{
    char sym; //symbol of the respected piece
    if(colour == WHITE){
	sym = 'B';
    }else{
	sym = 'b';
    }
    return sym;
}
 

bool Bishop::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
    const {
    bool move; //true is move is valid, false if not
    
    if(isDiagonal(fromX, fromY, toX, toY) == true){

	if(isPathClear(b, fromX, fromY, toX, toY) == true){

	    if(b.getPiece(toX, toY) == NULL){
		move = true;
	    }else{

		if(b.getPiece(toX,toY)->getColour() == colour){
		    move = false;
		}else{
		    move = true;
		}
	    }

	}else{
	    move = false;
	}

    }else{
	move = false;
    }

    return move;
}

PiecePtr Bishop::clone() const{
    return new Bishop(*this);
}
