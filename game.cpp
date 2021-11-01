/***************************************************************
* Name: William Marks                                                          
* Email: wmark194@mtroyal.ca                                                   
* Course: COMP 1633, 001                                                       
* Assignment: 05 part 3                                                        
* Due date: April 13th, 2021                                                   
* Instructor name: Paul Pospisil                                              
* File name: game.cpp                                                   
* Purpose: To instatiate a Board object, to be much like chess board. In which
           Two players can play a game of chess against each other.

* Details: Creates a board object and fills the bottom and top row with        
           miscellaneous pieces of opposing colours. Infront of each of these 
           rows pawns are placed with the same colour as their prior row      
           counter-part.                 
           With these objects, two users are allowed to play a game agaisnt
           each other locally on a single machine of simplifed chess. Classic 
           rules of normal chess such as castling and  capturing en passant 
           are not present. One player ones the game once they take the other
           players king. 
  
*/
#include "Piece.h"
#include "Board.h"
#include "Pawn.h"
#include "ioutil.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"

using namespace std;

const char promptMoveCurrIntX[50] = "Please enter current X-coordinate: ";
const char promptMoveCurrIntY[50] = "Please enter current Y-coordinate: ";
const char promptMoveNewIntX[50] = "Please enter new X-coordinate: ";
const char promptMoveNewIntY[50] = "Please enter new Y-coordinate: ";

void setUp(Board& b);
bool checkWin(const Board& b);

int main(){
    Board board; //the main board object
    int currX, newX; //current and new x-coordinates
    int currY, newY; //current and new y-coordinates
    bool eof; //eof is true if <ctrl-d> is entered for any input
    bool winCon; //true if one team has one
    bool moved = false; //true when a valid move has occured 
    bool turn = true; //determines if it's white or blacks turn
    bool correct = false; //true when a valid x and y is entered
    bool changeMove = true;
    setUp(board);
   
    while(eof != true && winCon != true && (currX != -1 && currY != -1)){
	operator << (std::cout, board);
	changeMove = true;
	if(turn == WHITE){

	    while(changeMove == true){
		cout << "\n White turn: \n";
		while(correct == false && eof != true && (currX != -1 &&
							  currY != -1)){
		    
		    currX = readInt(promptMoveCurrIntX, eof);
		    if(eof == false){
			currY = readInt(promptMoveCurrIntY, eof);
		    }
		    if(eof == false){
			if(board.getPiece(currX, currY) != NULL){
			    if(board.getPiece(currX, currY)->getColour() ==
			       WHITE){
				correct = true;
			    }else{
				cout << "\nIncorrect Colour try again. \n";
			    }
			}else{
			    cout << "\nIncorrect Coordinates try again. \n";
			}
		    }
		    
		}
	    
		correct = false;
		
		while(moved == false && (currX != -1 && currY != -1) &&
		      eof == false && (newX != -2 && newY != -2)){
		    if(eof == false){
			newX = readInt(promptMoveNewIntX, eof);
		    }
		    
		    if(eof == false){
			newY = readInt(promptMoveNewIntY, eof);
		    }
		    
		    moved = board.move(currX, currY, newX, newY);
		    
		    if(moved != true && newX != -2 && newY != -2){
			cout << "\n invalid coordinates try again. \n";
		    }
		}
		  moved = false;
		  changeMove = false;
		if(newX == -2 && newY == -2){
		    cout << "\n White can now pick it's piece again. \n";
		    changeMove = true;
		    newX = 0;
		    newY = 0;
		}
		
	    }
	}else{
	    while(changeMove == true){
		cout << "\n Black turn: \n";
		while(correct == false && eof != true && (currX != -1 &&
							  currY != -1)){
		    
		    currX = readInt(promptMoveCurrIntX, eof);
		    if(eof == false){
			currY = readInt(promptMoveCurrIntY, eof);
		    }
		    if(eof == false){
			if(board.getPiece(currX, currY) != NULL){
			    if(board.getPiece(currX, currY)->getColour() ==
			       BLACK){
				correct = true;
			    }else{
				cout << "\nIncorrect Colour try again. \n";
			    }
			}else{
			    cout << "\nIncorrect Coordinates try again. \n";
			}
		    }
		    
		}
		
		correct = false;
		
		while(moved == false && (currX != -1 && currY != -1) &&
		      eof == false  && (newX != -2 && newY != -2)){
		    if(eof == false){
			newX = readInt(promptMoveNewIntX, eof);
		    }
		    
		    if(eof == false){
			newY = readInt(promptMoveNewIntY, eof);
		    }
		    
		    moved = board.move(currX, currY, newX, newY);
          
		    if(moved != true){
			cout << "\n invalid coordinates try again. \n";
		    }
            }
		
		moved = false;
		changeMove = false;
                if(newX == -2 && newY == -2){
                    cout << "\n Black can now pick it's piece again. \n";
                    changeMove = true;
                    newX = 0;
                    newY = 0;
                }
	    }
	    
	    
	}
	
	
	
	winCon = checkWin(board);
	
	turn = !turn;
    }

    if(currX == -1 && currY == -1){
	cout << "\n Now exiting program.\n";
    }else if(eof == true){
	cout << "\n Now exiting program.\n";
    }
    
}

/***************************************************************************** 
  Name: setUp                                                           
                                                                              
  Purpose: initializes the game board with corresponding chess pieces
                                                                              
  Details: Creates a chess board by filling the bottom and top row with
           miscellaneous of opposing colours. Infront of each of these rows
           pawns are placed with the same colour as their prior row
           counter-part.

  Input Parameters: Board:
                        b; the game board

  Output Parameters: Board:
                        b; updated game board

******************************************************************************/
void setUp(Board& b){
    PiecePtr temp;
    temp = new Rook(BLACK);
    b.place(temp, 0, 0);
    temp = new Rook(BLACK);
    b.place(temp, 0, MAXROWS-1);
    temp = new Bishop(BLACK);
    b.place(temp, 0, 2);
    temp = new Bishop(BLACK);
    b.place(temp, 0, 5);
    temp = new Knight(BLACK);
    b.place(temp, 0, 1);
    temp = new Knight(BLACK);
    b.place(temp, 0, 6);
    temp = new King(BLACK);
    b.place(temp, 0, 4);
    temp = new Queen(BLACK);
    b.place(temp, 0, 3);
    for(int i = 0; i < MAXROWS; i++){
	temp = new Pawn(BLACK);
	b.place(temp, 1, i);
    }

    

    temp = new Rook(WHITE);
    b.place(temp, MAXCOLS-1, 0);
    temp = new Rook(WHITE);
    b.place(temp, MAXCOLS-1, MAXROWS-1);
    temp = new Bishop(WHITE);
    b.place(temp, MAXCOLS-1, 2);
    temp = new Bishop(WHITE);
    b.place(temp, MAXCOLS-1, 5);
    temp = new Knight(WHITE);
    b.place(temp, MAXCOLS-1, 1);
    temp = new Knight(WHITE);
    b.place(temp, MAXCOLS-1, 6);
    temp = new King(WHITE);
    b.place(temp, MAXCOLS-1, 4);
    temp = new Queen(WHITE);
    b.place(temp, MAXCOLS-1, 3);
    for(int i = 0; i < MAXROWS; i++){
	temp = new Pawn(WHITE);
        b.place(temp, MAXROWS-2, i);
	}
     cout << "\n If you'd like to leave the game at any time enter (-1) as " <<
	 "both current x and y coordinates. If you'd like to change the " <<
	 "Piece you have originally entered, enter (-2) as both the new x and"
	  << " y coordinates. The goal of the game is to capture the " <<
	 "Opposing players king. \n";
     cout << "LEGEND: \n";
     cout << "n/N = Knight \n";
     cout << "r/R = Rook \n";
     cout << "k/K = King \n";
     cout << "q/Q = Queen \n";
     cout << "b/B = Bishop \n";
     cout << "p/P = Pawn \n";
     cout << "White is uppercase, Black is lowercase \n \n";
	 
     
}

/***************************************************************************** 
  Name: checkWin                                                           
                                                                               
  Purpose: To determine if a team as won the game.                             
                                                                               
  Details: checks whether each team has a Piece still on the board. If a team
           has no King left on the board, the opposing team is declared
           the winner and a message of victory printed and a boolean
           of true is returned. If no one has one, then nothing is printed and
           a boolean of false os returned. 

  Input Parameters: Board:
                    const b; current board

  Output parameters: Board:
                     const b; the checked board object

  Returns: boolean, true or false depending on if someone has won. True if
                    a winner, false if not. 
             
******************************************************************************/

bool checkWin(const Board& b){
    bool whiteLeft = false; //true if any white king is left 
    bool blackLeft = false; //true if black king is left
    bool victor; //true if one team as won
    PiecePtr temp; //temporary pointer to a piece object
    
    for(int i = 0; i < MAXROWS; i++){

	for(int j = 0; j < MAXCOLS; j++){
	    
	    temp = b.getPiece(i, j);

	    if(temp != NULL){

		if(temp->getSymbol() == 'K'){
		   
		    whiteLeft = true;

		}else if(temp->getSymbol() == 'k'){
	
		    blackLeft = true;

		}
	    }
	}
    }
       
    if(whiteLeft == false){
	
	cout << "\nBlack wins! \n";
	victor = true;
	
    }else if(blackLeft == false){

	cout << "\nWhite wins! \n";
	victor = true;
	
    }else{

	victor = false;
	
    }
    
    return victor;
}	
