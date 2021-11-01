# Name: William Marks                                                          
# Email: wmark194@mtroyal.ca                                                   
# Course: COMP 1633, 001                                                       
# Assignment: 05 part 3                                                        
# Due date: April 13th, 2021                                                   
# Instructor name: Paul Pospisil                                               
# File name: makefile                                                          
TESTINGB=test_Board
TESTINGP=test_Pawn
TESTINGR=test_Rook
TESTINGBISHOP=test_Bishop
TESTINGKNIGHT=test_Knight
TESTINGKING=test_King
TESTINGQUEEN=test_Queen
TESTINGPIECE=test_Piece
TARGET=GAME
MODULES1=test_Board.o Piece.o Board.o Pawn.o
MODULES3=test_Pawn.o Piece.o Board.o Pawn.o
MODULES4=test_Rook.o Piece.o Board.o Rook.o
MODULES5=test_Bishop.o Piece.o Board.o Bishop.o
MODULES6=test_Knight.o Piece.o Board.o Knight.o
MODULES7=test_King.o Piece.o Board.o King.o
MODULES8=test_Queen.o Piece.o Board.o Queen.o
MODULES9=test_Piece.o Piece.o Board.o Pawn.o Queen.o Rook.o
MODULESPIECES=Piece.o Pawn.o Rook.o Bishop.o Knight.o King.o Queen.o
MODULESTEST1=test_Piece.o test_Board.o test_Bishop.o test_Knight.o
MODULESTEST2=test_Rook.o test_King.o test_Queen.o 
MODULES2=game.o Board.o ioutil.o $(MODULESPIECES)
ALLOFILES=game.o Board.o $(MODULESTEST1) $(MODULESTEST2) $(MODULESPIECES)
CPPFLAGS=-ansi -pedantic-errors -Wall -Wconversion
GCOVFLAGS=-fprofile-arcs -ftest-coverage
GTFLAGS=-lgtest -lpthread -lgtest_main
GCOVFILE=Board
GCOVFILE2=Pawn
GCOVFILE3=Rook
GCOVFILE4=Bishop
GCOVFILE5=Knight
GCOVFILE6=King
GCOVFILE7=Queen
GCOVFILE8=Piece
TESTINGALL1=$(TESTINGB) $(TESTINGP) $(TESTINGR) $(TESTINGBISHOP)
TESTINGALL2=$(TESTINGKNIGHT) $(TESTINGKING) $(TESTINGQUEEN) $(TESTINGPIECE)
TESTINGALLCOMPLETE=$(TESTINGALL1) $(TESTINGALL2)

$(TESTINGB): $(MODULES1)
	g++ $(GTFLAGS) $(MODULES1) $(GCOVFLAGS) -o $(TESTINGB)
	$(TESTINGB)
	gcov $(GCOVFILE).cpp 2> /dev/null | grep -A 1 $(GCOVFILE).cpp

$(TESTINGP): $(MODULES3)
	g++ $(GTFLAGS) $(MODULES3) $(GCOVFLAGS) -o $(TESTINGP)
	$(TESTINGP)
	gcov $(GCOVFILE2).cpp 2> /dev/null | grep -A 1 $(GCOVFILE2).cpp

$(TESTINGR): $(MODULES4)	
	g++  $(GTFLAGS) $(MODULES4) $(GCOVFLAGS) -o $(TESTINGR)
	$(TESTINGR)
	gcov $(GCOVFILE3).cpp 2> /dev/null | grep -A 1 $(GCOVFILE3).cpp

$(TESTINGBISHOP): $(MODULES5)
	g++ $(GTFLAGS) $(MODULES5) $(GCOVFLAGS) -o $(TESTINGBISHOP)
	$(TESTINGBISHOP)
	gcov $(GCOVFILE4).cpp 2> /dev/null | grep -A 1 $(GCOVFILE4).cpp

$(TESTINGKNIGHT): $(MODULES6)
	g++ $(GTFLAGS) $(MODULES6) $(GCOVFLAGS) -o $(TESTINGKNIGHT)
	$(TESTINGKNIGHT)
	gcov $(GCOVFILE5).cpp 2> /dev/null | grep -A 1 $(GCOVFILE5).cpp

$(TESTINGKING): $(MODULES7)
	g++ $(GTFLAGS) $(MODULES7) $(GCOVFLAGS) -o $(TESTINGKING)
	$(TESTINGKING)
	gcov $(GCOVFILE6).cpp 2> /dev/null | grep -A 1 $(GCOVFILE6).cpp

$(TESTINGQUEEN): $(MODULES8)
	g++ $(GTFLAGS) $(MODULES8) $(GCOVFLAGS) -o $(TESTINGQUEEN)
	$(TESTINGQUEEN)
	gcov $(GCOVFILE7).cpp 2> /dev/null | grep -A 1 $(GCOVFILE7).cpp

$(TESTINGPIECE): $(MODULES9)
	g++ $(GTFLAGS) $(MODULES9) $(GCOVFLAGS) -o $(TESTINGPIECE)
	$(TESTINGPIECE)
	gcov $(GCOVFILE8).cpp 2> /dev/null | grep -A 1 $(GCOVFILE8).cpp

$(TARGET): $(MODULES2)
	g++ $(CPPFLAGS) $(MODULES2) $(GCOVFLAGS) -o $(TARGET)


clean:
	/bin/rm -f $(ALLOFILES) $(TESTINGALLCOMPLETE) $(TARGET) *.*~ *.g* *.txt

all:	clean $(TESTINGALLCOMPLETE) $(TARGET)
	$(TESTINGB)
	gcov $(GCOVFILE).cpp 2> /dev/null | grep -A 1 $(GCOVFILE).cpp
	$(TESTINGP)
	gcov $(GCOVFILE2).cpp 2> /dev/null | grep -A 1 $(GCOVFILE2).cpp
	$(TESTINGR)
	gcov $(GCOVFILE3).cpp 2> /dev/null | grep -A 1 $(GCOVFILE3).cpp
	$(TESTINGBISHOP)	
	gcov $(GCOVFILE4).cpp 2> /dev/null | grep -A 1 $(GCOVFILE4).cpp
	$(TESTINGKNIGHT)
	gcov $(GCOVFILE5).cpp 2> /dev/null | grep -A 1 $(GCOVFILE5).cpp
	$(TESTINGKING)
	gcov $(GCOVFILE6).cpp 2> /dev/null | grep -A 1 $(GCOVFILE6).cpp
	$(TESTINGQUEEN)
	gcov $(GCOVFILE7).cpp 2> /dev/null | grep -A 1 $(GCOVFILE7).cpp
	$(TESTINGPIECE)
	gcov $(GCOVFILE8).cpp 2> /dev/null | grep -A 1 $(GCOVFILE8).cpp
	$(TARGET)

$(TESTINGB).o: $(TESTINGB).cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(TESTINGB).cpp             

$(TESTINGP).o: $(TESTINGP).cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(TESTINGP).cpp

$(TESTINGR).o: $(TESTINGR).cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(TESTINGR).cpp

$(TESTINGBISHOP).o: $(TESTINGBISHOP).cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(TESTINGBISHOP).cpp

$(TESTINGKNIGHT).o: $(TESTINGKNIGHT).cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(TESTINGKNIGHT).cpp

$(TESTINGKING).o: $(TESTINGKING).cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(TESTINGKING).cpp

$(TESTINGQUEEN).o: $(TESTINGQUEEN).cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(TESTINGQUEEN).cpp

$(TESTINGPIECE).o: $(TESTINGPIECE).cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c $(TESTINGPIECE).cpp

Piece.o: Piece.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Piece.cpp                

Board.o: Board.cpp
	g++ $(CPPFLAGS)  $(GTFLAGS) $(GCOVFLAGS) -c Board.cpp

Pawn.o: Pawn.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Pawn.cpp

Rook.o: Rook.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Rook.cpp

Bishop.o: Bishop.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Bishop.cpp

Knight.o: Knight.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Knight.cpp

King.o: King.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c King.cpp

Queen.o: Queen.cpp
	g++ $(CPPFLAGS) $(GTFLAGS) $(GCOVFLAGS) -c Queen.cpp
