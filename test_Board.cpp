
#include "Piece.h"
#include "Board.h"
#include "Pawn.h"
#include <fstream>
#include <gtest/gtest.h>
class test_Board : public testing::Test {
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
    Board board;
};

TEST_F(test_Board, testDefaultConstructor)
{
    stringstream ss;
    ifstream output;
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
   output.close();
    EXPECT_EQ(ss.str(),"");
}

/*TEST_F(test_Board, testCopyConstructor){
    stringstream ss;
    PiecePtr tempPiece = new Pawn(0);
    ifstream output;
    board.place(tempPiece, 3, 3);
    Board temp(board);
    temp.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(),"P 3 3\n");
    }*/

TEST_F(test_Board, testEmptyDestructor){
    stringstream ss;
    ifstream output;
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(),"");
}

TEST_F(test_Board, testOnePieceDestructor){
    stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(0);
    bool placed;
    placed = board.place(tempPiece, 1, 1);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "P 1 1\n");
    EXPECT_EQ(placed, true);
}

TEST_F(test_Board, testPlaceValidMultiplePieces){
    stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(0);
    PiecePtr tempPiece2 = new Pawn(0);
    bool placed;
    placed = board.place(tempPiece, 1, 1);
    placed = board.place(tempPiece2, 3, 4);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "P 1 1\nP 3 4\n");
    EXPECT_EQ(placed, true);
}

TEST_F(test_Board, testPlaceInvalidX){
    stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(0);
    bool placed;
    placed = board.place(tempPiece, 100, 7);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "");
    EXPECT_EQ(placed, false);
}

TEST_F(test_Board, testPlaceInvalidY){
    stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(0);
    bool placed;
    placed = board.place(tempPiece, 7, 100);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "");
    EXPECT_EQ(placed, false);
}


TEST_F(test_Board, testMoveValidForward1){
     stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(0);
    bool moved;
    board.place(tempPiece, 3, 3);
     moved = board.move(3, 3, 4, 3);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "P 4 3\n");
    EXPECT_EQ(moved, true);
    }

TEST_F(test_Board, testMoveValidForward2){
    stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(0);
    bool moved;
    board.place(tempPiece, 3, 3);
     moved = board.move(3, 3, 5, 3);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "P 5 3\n");
    EXPECT_EQ(moved, true);
    }


TEST_F(test_Board, testMoveInvalidToXY){
    stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(0);
    bool moved;
    board.place(tempPiece, 3, 3);
    moved = board.move(3, 3, 3, 4);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "P 3 3\n");
    EXPECT_EQ(moved, false);
}


TEST_F(test_Board, testMoveInvalidFromXY){
    stringstream ss;
    ifstream output;
    bool moved;
    moved = board.move(3, 3, 3, 4);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "");
    EXPECT_EQ(moved, false);
}

TEST_F(test_Board, testMoveValidTakePieceBlack){
    stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(0);
    bool moved;
    board.place(tempPiece, 3, 3);
    tempPiece = new Pawn(1);
    board.place(tempPiece, 4, 4);
    moved = board.move(3, 3, 4, 4);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "P 4 4\n");
    EXPECT_EQ(moved, true);
}

TEST_F(test_Board, testMoveValidTakePiece){
    stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(0);
    bool moved;
    board.place(tempPiece, 3, 3);
    tempPiece = new Pawn(1);
    board.place(tempPiece, 4, 4);
    moved = board.move(3, 3, 4, 4);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "P 4 4\n");
    EXPECT_EQ(moved, true);
}

TEST_F(test_Board, testMoveInvalidTakePieceWhite){
    stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(BLACK);
    bool moved;
    board.place(tempPiece, 0, 1);
    tempPiece = new Pawn(WHITE);
    board.place(tempPiece, 1, 0);
    board.write(std::cout);
    moved = board.move(1, 0, 0, 1);
    board.write(std::cout);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "P 0 1\n");
    EXPECT_EQ(moved, true);
}


TEST_F(test_Board, testMoveInvalidPieceAlreadyOccupy){
    stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(0);
    PiecePtr tempPiece2 = new Pawn(0);
    bool moved;
    board.place(tempPiece, 1, 1);
    board.place(tempPiece2, 2, 1);
    moved = board.move(1,1,2,1);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "P 1 1\nP 2 1\n");
    EXPECT_EQ(moved, false);
}

TEST_F(test_Board, testMoveInvalidForwardTwoSpacesTwoDifferentTimes){
    stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(0);
    bool moved;
    board.place(tempPiece, 1, 1);
    moved = board.move(1, 1, 3, 1);
    moved = board.move(3, 1, 5, 1);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "P 3 1\n");
    EXPECT_EQ(moved, false);
    }

TEST_F(test_Board, testMoveValidWhite){
    stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(WHITE);
    bool moved;
    board.place(tempPiece, 7, 0);
    moved = board.move(7, 0, 6, 0);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "P 6 0\n");
    EXPECT_EQ(moved, true);
    }

/*
TESTF(test_Board, testMoveInvalidMoveTwoSpacesTwoTimes){
  stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Piece(0);
    bool moved;
    board.place(tempPiece, 1, 1);
}*/

/*
TEST_F(test_Board, testMoveInvalidFromXY){
    stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Piece(0);
    bool moved;
    board.place(tempPiece, 3, 3);
    moved = board.move(4, 4, 3, 3);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "P 3 3\n");
    EXPECT_EQ(moved, false);
}
*/
TEST_F(test_Board, testRemoveValid){
 stringstream ss;
    ifstream output;
    PiecePtr tempPiece = new Pawn(0);
    bool removed;
    board.place(tempPiece, 3, 3);
    removed = board.remove(3,3);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "");
    EXPECT_EQ(removed, true);
}

TEST_F(test_Board, testRemoveInvalidDoesntExist){
    stringstream ss;
    ifstream output;
    bool removed;
    removed = board.remove(1,1);
    board.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "");
    EXPECT_EQ(removed, false);
}


/*TEST_F(test_Board, testCopyOperator){
    stringstream ss;
    Board temp;
    ifstream output;
    PiecePtr tempPiece = new Pawn(0);
    board.place(tempPiece, 1, 1);
    temp = board;
    std::cout << "Temp before deleting board: \n";
    temp.write(std::cout);
    board.~Board();
    std::cout << "\nTemp after deleting board: \n";
    temp.write(std::cout);
    temp.~Board();
    output.open("final_board.txt");
    ss << output.rdbuf();
    output.close();
    EXPECT_EQ(ss.str(), "P 1 1\n");
    }*/

TEST_F(test_Board, testOverloadedPrintOperator){
    PiecePtr tempPiece = new Pawn(0);
    board.place(tempPiece, 1, 1);
    operator <<(std::cout, board);
    EXPECT_EQ(true, true);
}

TEST_F(test_Board, testIsOccupied){
    PiecePtr tempPiece = new Pawn(0);
    bool taken;
    board.place(tempPiece, 1, 1);
    taken = board.isOccupied(1,1);
    EXPECT_EQ(true, taken);
}

TEST_F(test_Board, testIsOccupiedNot){
    PiecePtr tempPiece = new Pawn(0);
    bool taken;
    board.place(tempPiece, 1, 1);
    taken = board.isOccupied(6,3);
    EXPECT_EQ(false, taken);
}

TEST_F(test_Board, testGetPieceValid){
    PiecePtr temp = new Pawn(0);
    PiecePtr temp2;
    board.place(temp, 1, 1);
    temp2 = board.getPiece(1,1);
    EXPECT_EQ(temp,temp2);
}

TEST_F(test_Board, testGetPieceInvalid){
    PiecePtr temp;
    temp = board.getPiece(1,2);
    EXPECT_EQ(NULL,temp);
}


