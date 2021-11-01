/***************************************************************               
* Name: William Marks                                                          
* Email: wmark194@mtroyal.ca                                                   
* Course: COMP 1633, 001                                                      
* Assignment: 05 part 3                                                        
* Due date: April 13th, 2021                                                   
* Instructor name: Paul Pospisil                                               
* File name: Piece.cpp                                                         
*                                                                              
* PRIVATE METHOD SPECIFICATIONS:                                               
                                                                               
*  isVertical:                                                                 
     Input: current x and y coordinates, and new x and y coordinates          
     Action: determines whether a given move is a verticle move or not. 
             As in for ex: (1,0) -> (4,0)
     Assumptions: An initalized piece object

*  isHorizontal:                                                              
     Input: current x and y coordinates, and new x and y coordinates           
     Action: determines whether a given move is a Horizontal move or not.      
             As in for ex: (1,0) -> (1,4)                                      
     Assumptions: An initalized piece object 

*  isDiagonal:                                                                 
     Input: current x and y coordinates, and new x and y coordinates           
     Action: determines whether a given move is a diagonal move or not.        
             As in for ex: (1,1) -> (4,4) or (3,2) -> (2,1)                    
     Assumptions: An initalized piece object 

*  isForward:                                                                 
     Input: current x and y coordinates, and new x and y coordinates           
     Action: determines whether a given move is a forward move or not.        
             As in for ex: (0,1) -> (2,1) or (0,1) -> (1,1). Only applies for 
             moves of 1-2 spaces in front.
     Assumptions: An initalized piece object

*  vertDistance: 
     Input: the current and new x values
     Action: determines the value of the difference between the two x values
     Assumptions: An initalized piece object    

*  horizDistance:                                                              
     Input: the current and new y values                                       
     Action: determines the value of the difference between the two y values   
     Assumptions: An initalized piece object     

*  isPathClear:
     input: the current board object, old and new x coordinates, old and new y
            coordinates
     Action: checks on the board between the current and next coordinates if
             a piece is in the way. If a piece is infact in the way, then false
             is returned. If the path to the new coordinate is clear, then
             true is returned.
     Assumption: board and piece objects are initialized

*  PRIVATE CLASS VARIBLES:

*  bool colour, the current colour of the Piece (Black or white).

*  bool hasMoved; false unless a Piece has moved once.
*/
#include "Piece.h"
#include "Board.h"
#include <cmath>
#include <string>
#include <typeinfo>
Piece::Piece (bool col){

    colour = col;
    
}

Piece::~Piece(){

}
 
bool Piece::getColour() const{
    return colour;
}

bool Piece::isVertical (int fromX, int fromY, int toX, int toY) const{
    bool valid;
    int vertDist = vertDistance(fromX, toX);
	if(fromY == toY){
	    if(vertDist < MAXCOLS){
		valid = true;
	    }else{
		valid = false;
	    }
	}else{
	    valid = false;
	}
	return valid;
}


bool Piece::isHorizontal (int fromX, int fromY, int toX, int toY) const{
    bool valid;
    int horzDist = horizDistance(fromY, toY);
    if(fromX == toX){
	if(horzDist < MAXCOLS){
	    valid = true;
	}else{
	    valid = false;
	}
    }else{
	valid = false;
    }
    return valid;
}

bool Piece::isDiagonal (int fromX, int fromY, int toX, int toY) const{
    bool valid;
    int vDis = vertDistance(fromX, toX);
    int hDis = horizDistance(fromY, toY);
    if(vDis == hDis){
	    valid = true;
	}else{
	    valid = false;
	}
	return valid;
}

bool Piece::isForward (int fromX, int toX) const{
    bool valid;
    if(this->colour == BLACK){
	if(fromX == toX-1 || fromX == toX-2){
	    valid = true;
	}else{
	    valid = false;
	}
    }else if(this->colour == WHITE){
	 if(fromX == toX+1 || fromX == toX+2){
	     valid = true;
	}else{
            valid = false;
        }
    }
    return valid;
}
int Piece::vertDistance (int fromX, int toX) const{
    int ans;
    ans = abs(fromX-toX);
    return ans;
}
int Piece::horizDistance (int fromY, int toY) const{
    int ans;
    ans = abs(fromY-toY);
    return ans;
}
bool Piece::isPathClear (const Board& b, int fromX, int fromY, int toX,
			 int toY) const{
    int x = fromX;
    int y = fromY;
    int factor;
    bool clear = true; 
    if(getSymbol() == 'P' || getSymbol() == 'p'){
	if(hasMoved == true){
	    factor = 1;
	}else{
	    factor = 2;
	}
	while(factor != 0){
	    if(this->colour == WHITE){
		x=x-1;
	    }else{
		x=x+1;
	    }
	    if(b.isOccupied(x,y) == true){
		clear = false;
	    }
	    factor--;
	}
	
    }else if(getSymbol() == 'R' || getSymbol() == 'r'){
	
	clear =	checkVerticalHorizontal(b, fromX, fromY, toX, toY);
	
    }else if(getSymbol() == 'B' || getSymbol() == 'b'){
	
	clear = checkDiagonal(b, fromX, fromY, toX, toY);

    }else if(getSymbol() == 'Q' || getSymbol() == 'q'){

	if(horizDistance(fromY, toY) == vertDistance(fromX, toX)){
	    clear = checkDiagonal(b, fromX, fromY, toX, toY);
	}else{
	    clear = checkVerticalHorizontal(b, fromX, fromY, toX, toY);
	}
	
    }else{
	clear = false;
    }

    return clear;
}


void Piece::notifyMoved(){
  
}

bool Piece::checkDiagonal(const Board& b, int fromX, int fromY, int toX,
			  int toY) const{
    int x = fromX;
    int y = fromY;
    bool clear = true;
      if((fromX-toX) > 0 && (fromY - toY) > 0){
            x--;
            y--;
            while(x != toX){
                if(b.isOccupied(x,y) == true){
                    clear = false;
                }
                x--;
                y--;
            }
        }else if((fromX-toX) < 0 && (fromY - toY) < 0){
            x++;
            y++;
            while(x != toX){
                if(b.isOccupied(x,y) == true){
                    clear = false;
                }
                x++;
                y++;
            }

        }else if((fromX-toX) > 0 && (fromY - toY) < 0){
            x--;
            y++;
            while(x != toX){
                if(b.isOccupied(x,y) == true){
                    clear = false;
                }
                x--;
                y++;
            }
      }else if((fromX-toX) < 0 && (fromY - toY) > 0){
	  x++;
	  y--;
	  while(x != toX){
	      if(b.isOccupied(x,y) == true){
		  clear = false;
	      }
	      x++;
	      y--;
	  }
      }
      return clear;
}


bool Piece::checkVerticalHorizontal(const Board& b, int fromX, int fromY,
				    int toX, int toY) const{
    int factor;
    bool clear = true;
    if(vertDistance(fromX, toX) == 0){
	 if(fromY > toY){
            factor = fromY-1;
        }else{
            factor = fromY+1;
        }
            while(factor != toY){
                if(b.isOccupied(toX,factor) == true){
		    clear = false;
                }
                if(factor > toY){
                    factor--;
                }else{
                    factor++;
                }
            }
	    
    }else if(horizDistance(fromY, toY) == 0){
	if(fromX > toX){
	    factor = fromX-1;
	}else{
	    factor = fromX+1;
	}
	while(factor != toX){
	    if(b.isOccupied(factor,toY) == true){
		clear = false;
                }
                if(factor > toX){
                    factor--;
                }else{
                    factor++;
                }
	}
    }else{
	clear = false;
    }


      return clear;
}
