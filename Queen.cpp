/***************************************************************               
* Name: William Marks                                                          
* Email: wmark194@mtroyal.ca                                                   
* Course: COMP 1633, 001                                                      
* Assignment: 05 part 3                                                        
* Due date: April 13th, 2021                                                   
* Instructor name: Paul Pospisil                                               
* File name: Queen.cpp                                                         
*                 
*/

#include "Piece.h"
#include "Board.h"
#include "Queen.h"
#include <cmath>

Queen::Queen (bool col) : Piece(col){

    colour = col;
    
}

Queen::~Queen(){

}

char Queen::getSymbol() const{
    char sym;
    if(colour == WHITE){
	sym = 'Q';
    }else{
	sym = 'q';
    }
    return sym;
}
 

bool Queen::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
    const {
    bool move;
    if(isPathClear(b, fromX,fromY, toX, toY) == true){      
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
    
    return move;
}

PiecePtr Queen::clone() const{
    return new Queen(*this);
}
