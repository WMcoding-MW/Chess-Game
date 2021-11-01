/***************************************************************               
* Name: William Marks                                                         
* Email: wmark194@mtroyal.ca                                           
* Course: COMP 1633, 001                                                       
* Assignment: 05 part 3                                              
* Due date: April 13th, 2021                              
* Instructor name: Paul Pospisil                                   
* File name: Board.cpp                                                
*                                                                   
* PRIVATE METHOD SPECIFICATIONS:

*  initBoard:
     Input: nothing
     Action: creates a board based on MAXCOLS and MAXROWS
             and fills each position of the grid array
             with NULL.
     Assumptions: Board has not already been initialized

*  clearBoard:
     Input: nothing
     Action: sets every position to NULL in the grid array
             and deletes any position that is not NULL.
     Assumptions: Board has been initialized

*  copyBoard:
     Input: another board object to be copied from
     Action: copies the inputted board onto the 
             current board.
     Assumption: Board to be copied is initialized
 
* PRIVATE DATA MEMBERS:

*  grid[][]: a grid of size MAXROWS x MAXCOLS containing 
             pointers to Piece objects.
     
*/

#include "Piece.h"
#include "Board.h"
#include <fstream> 
#include <cmath>
Board::Board(){
    initBoard();
}

Board::Board(const Board& other){
    copyBoard(other);
}

Board::~Board(){
    std::ofstream outfile; //file for positions to be printed to
    outfile.open("final_board.txt");
    for(int i = 0; i < MAXROWS; i++){
        for(int j = 0; j < MAXCOLS; j++){
	    if(grid[j][i] != NULL){
		outfile << "P " << j << " " << i << "\n";
	    }
	}
    }
    clearBoard();
    outfile.close();
}

bool Board::move(int fromX, int fromY, int toX, int toY){
    bool moved; //true if moved, false if not
    
    if(grid[fromX][fromY] == NULL){
        moved = false;
	}else{ 
       if(grid[fromX][fromY]->canMove(*this, fromX, fromY, toX, toY) == true){
	   
	if(getPiece(toX, toY) != NULL){
		delete grid[toX][toY];
	         grid[toX][toY] = grid[fromX][fromY];
		 grid[fromX][fromY] = NULL;
		 moved = true;
	}else{
//	    grid[fromX][fromY]->notifyMoved();    
	    grid[toX][toY]=grid[fromX][fromY];
	    grid[toX][toY]->notifyMoved();
	    grid[fromX][fromY] = NULL;
	    moved = true;
	}
	            
	}else{
//        std::cout << "38922389" << moved;    
	moved = false;
	 }
    }

//    std::cout << "Board Moved: " << moved;
    return moved;
}

bool Board::place (const PiecePtr& p, int x, int y){
    bool placed; //true is placed, false if not
    
    if(x < MAXCOLS && x >= 0){

	if(y < MAXCOLS && y >= 0){
	    
	    if(grid[x][y] == NULL){
		grid[x][y] = p;
		placed = true;
	    }else{
		placed = false;
	    }
	   
	}else{
	    placed = false;
	}
	
    }else{
	placed = false;
    }
    
	    return placed;
}

bool Board::remove (int x, int y){
    bool removed; //true if removed, false if not

    if(grid[x][y] != NULL){
        delete grid[x][y];
	grid[x][y] = NULL;
	removed = true;
    }else{
	removed = false;
    }

    return removed;
}

void Board::write (ostream& out) const{
    
    out << "    0   1   2   3   4   5   6   7\n";
    out << "  +---+---+---+---+---+---+---+---+\n";

    for(int i = 0; i < MAXROWS; i++){

	out << i << " |";

	for(int j = 0; j < MAXCOLS; j++){

	    if(grid[i][j] == NULL){
		out << "   |";
	    }else{
		out << " " << grid[i][j]->getSymbol() << " |";
	    }

	}

	out << "\n  +---+---+---+---+---+---+---+---+\n";

    }
}

Board& Board::operator= (const Board& other){

    for(int i = 0; i < MAXROWS; i++){

	for(int j = 0; j < MAXCOLS; j++){

	    if(grid[j][i] != NULL){
		delete grid[i][j];
		grid[j][i] = NULL;
	    }

	}

    }

    copyBoard(other);
    return *this;
    }


void Board::initBoard(){

    for(int i = 0; i < MAXROWS; i++){

	for(int j = 0; j < MAXCOLS; j++){
            grid[j][i] = NULL;
	}

    }

}

void Board::clearBoard(){

    for(int i = 0; i < MAXROWS; i++){

	for(int j = 0; j < MAXCOLS; j++){

	    if(grid[j][i] != NULL){
		delete grid[j][i];
	    }

	    grid[j][i] = NULL;

	}

    }

}

void Board::copyBoard(const Board& other){
    PiecePtr temp; //temporary pointer at a Piece object

    for(int i = 0; i < MAXROWS; i++){

	for(int j = 0; j < MAXCOLS; j++){

	    if(other.grid[j][i] == NULL){
		grid[j][i] = NULL;
	    }else{
		temp = grid[j][i]->clone();
		*temp = *other.grid[j][i];
		grid[j][i] = temp;
	    }

	}	

    }

    }

bool Board::isOccupied (int x, int y) const{
    bool taken; //true if a piece occupies, false if not
    
    if(getPiece(x,y) == NULL){
	taken = false;
    }else{
	taken = true;
    }
    return taken;
    
}

ostream& operator<< (ostream& out, const Board& b){
    b.write(out);
    return out;
}

PiecePtr Board::getPiece(int x, int y) const{
    PiecePtr temp; //temporary pointer to a piece object
    temp = grid[x][y];
    return temp;
}


