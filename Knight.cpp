/***************************************************************               
* Name: William Marks                                                          
* Email: wmark194@mtroyal.ca                                                   
* Course: COMP 1633, 001                                                      
* Assignment: 05 part 3                                                        
* Due date: April 13th, 2021                                                   
* Instructor name: Paul Pospisil                                               
* File name: Knight.cpp                                                   
*                 
*/

#include "Piece.h"
#include "Board.h"
#include "Knight.h"
#include <cmath>

Knight::Knight (bool col) : Piece(col){

    colour = col;
    
}

Knight::~Knight(){

}

char Knight::getSymbol() const{
    char sym; //symbol of current Knight object
    if(colour == WHITE){
	sym = 'N';
    }else{
	sym = 'n';
    }
    return sym;
}
 

bool Knight::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
    const {
    bool move; //true if move is valid, false if not

    if((vertDistance(fromX, toX) == 2 && horizDistance(fromY, toY) == 1) ||
	(vertDistance(fromX, toX) == 1 && horizDistance(fromY, toY) == 2)){

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

PiecePtr Knight::clone() const{
    return new Knight(*this);
}
