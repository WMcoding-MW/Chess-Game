 /***************************************************************              
* Name: William Marks                                                          
* Email: wmark194@mtroyal.ca                                                   
* Course: COMP 1633, 001                                                      
* Assignment: 05 part 3                                                        
* Due date: April 13th, 2021                                                   
* Instructor name: Paul Pospisil                                               
* File name: Pawn.cpp                                                         
*                                                                              
*  bool hasMoved; false unless a Piece has moved once.
*/
#include "Piece.h"
#include "Board.h"
#include "Pawn.h"
#include <cmath>

Pawn::Pawn (bool col) : Piece(col){

    colour = col;
    
}

Pawn::~Pawn(){
}

char Pawn::getSymbol() const{
    char sym; //current Pawn symbol based on colour
    
    if(colour == WHITE){
	sym = 'P';
    }else{
	sym = 'p';
    }
    return sym;
}
 

bool Pawn::canMove(const Board& b, int fromX, int fromY, int toX, int toY)
    const {
    bool move; //true if valid, false if not
    
    if(isForward(fromX, toX) == true ||
       (vertDistance(fromX, toX) == 1 &&
	horizDistance(fromY, toY) == 1)){
	
	if(isPathClear(b, fromX, fromY, toX, toY) == true ||
	   (vertDistance(fromX, toX) == 1 &&
	    horizDistance(fromY, toY) == 1)){
		 
	    if(hasMoved == false && vertDistance(fromX, toX) <= 2 &&
	       horizDistance(fromY, toY) == 0){
	       
		move = true;
		
	    }else if(hasMoved == true && vertDistance(fromX, toX)  == 1 &&
		     horizDistance(fromY, toY) == 0){
		
		move = true;
		
	    }else if((vertDistance(fromX, toX) == 1 &&
		      horizDistance(fromY, toY) == 1) &&
		     (b.getPiece(toX, toY) != NULL) &&
		     (b.getPiece(toX, toY)->getColour() != this->colour)){
		move = true;				    
		
	    }else {
		
		move = false;
		    
	    }
	    
	    
	}else{
	    
	    move = false;
	    
	}
	
    }else{
	
	move = false;
	
    }
    
    return move;
    
}

PiecePtr Pawn::clone() const{
    return new Pawn(*this);
}

void Pawn::notifyMoved(){
     
    hasMoved = true;
}

