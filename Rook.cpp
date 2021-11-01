/***************************************************************               
* Name: William Marks                                                          
* Email: wmark194@mtroyal.ca                                                   
* Course: COMP 1633, 001                                                      
* Assignment: 05 part 3                                                        
* Due date: April 13th, 2021                                                   
* Instructor name: Paul Pospisil                                               
* File name: Rook.cpp                                                         
*                      
*/

#include "Piece.h"
#include "Board.h"
#include "Rook.h"
#include <cmath>
Rook::Rook (bool col) : Piece(col){

    colour = col;
    
}

Rook::~Rook(){

}

char Rook::getSymbol() const{
    char sym;
    if(colour == WHITE){
	sym = 'R';
    }else{
	sym = 'r';
    }
    return sym;
}
 

bool Rook::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
    const {
    bool move = true;
    
    if(isVertical(fromX, toX, fromY, toY) == true ||
       isHorizontal(fromX, toX, fromY, toY) == true){
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

PiecePtr Rook::clone() const{
    return new Rook(*this);
}
