/***************************************************************               
* Name: William Marks                                                          
* Email: wmark194@mtroyal.ca                                                   
* Course: COMP 1633, 001                                                      
* Assignment: 05 part 2                                                        
* Due date: April 13th, 2021                                                   
* Instructor name: Paul Pospisil                                               
* File name: King.cpp                                                         
*                 
*/

#include "Piece.h"
#include "Board.h"
#include "King.h"
#include <cmath>

King::King (bool col) : Piece(col){

    colour = col;
    
}

King::~King(){

}

char King::getSymbol() const{
    char sym; //symbol of the current chess piece
    if(colour == WHITE){
	sym = 'K';
    }else{
	sym = 'k';
    }
    return sym;
}
 

bool King::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
    const {
    bool move; //true if move is valid, false if not
    
    if(vertDistance(fromX, toX) <= 1 && horizDistance(fromY, toY) <= 1){      

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

PiecePtr King::clone() const{
    return new King(*this);
}
