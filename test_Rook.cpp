#include "Piece.h"
#include "Board.h"
#include "Rook.h"
#include <fstream>
#include <gtest/gtest.h>

class test_Rook : public testing::Test {
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
    Board board;
};

TEST_F(test_Rook, testDefaultConstructor){
    bool col;
    PiecePtr piece;
    piece = new Rook(WHITE);
    col = piece->getColour();
    EXPECT_EQ(col, WHITE);
}

TEST_F(test_Rook, testGetSymbolWhite){
    char sym;
    PiecePtr piece;
    piece = new Rook(WHITE);
    sym = piece->getSymbol();
    EXPECT_EQ(sym, 'R');
}

TEST_F(test_Rook, testGetSymbolBlack){
    char sym;
    PiecePtr piece;
    piece = new Rook(BLACK);
    sym = piece->getSymbol();
    EXPECT_EQ(sym, 'r');
}

TEST_F(test_Rook, testCanMoveInvalidVertDistanceAndHorizDistanceEqualToOne){
    bool moved;
    PiecePtr piece = new Rook(WHITE);
    board.place(piece, 0, 0);
    moved = board.move(0, 0, 1, 1);
    EXPECT_EQ(moved, false);
}

TEST_F(test_Rook, testCanMoveInvalidPathNotClear){
    bool moved;
    PiecePtr piece = new Rook(WHITE);
    board.place(piece, 0, 0);
    piece = new Rook(WHITE);
    board.place(piece, 0, 2);
    moved = board.move(0, 0, 0, 3);
    EXPECT_EQ(moved, false);
    }

TEST_F(test_Rook, testCanMoveInvalidSameColourDestination){
    bool moved;
    PiecePtr piece = new Rook(WHITE);
    board.place(piece, 0, 0);
    piece = new Rook(WHITE);
    board.place(piece, 0, 2);
    moved = board.move(0, 0, 0, 2);
    EXPECT_EQ(moved, false);
}

TEST_F(test_Rook, testCanMoveValidDifferentColourDestination){
    bool moved;
    PiecePtr piece = new Rook(WHITE);
    board.place(piece, 0, 0);
    piece = new Rook(BLACK);
    board.place(piece, 0, 2);
    moved = board.move(0, 0, 0, 2);
    EXPECT_EQ(moved, true);
}

TEST_F(test_Rook, testCanMoveValidEmptyDestination){
    bool moved;
    PiecePtr piece = new Rook(WHITE);
    board.place(piece, 0, 0);
    moved = board.move(0, 0, 5, 0);
    EXPECT_EQ(moved, true);
}

/*TEST_F(test_Rook, testCanMoveValidTwoMoves){
    bool moved;
    PiecePtr piece = new Rook(WHITE);
    board.place(piece, 0, 0);
    piece = new Rook(WHITE);
    board.place(piece, 1, 0);
    moved = board.move(1, 0, 3, 0);
    moved = board.move(0, 0, 2, 0);
    EXPECT_EQ(moved, true);
}*/

TEST_F(test_Rook, testClone){
    PiecePtr piece, temp;
    piece = new Rook(WHITE);
    temp = piece->clone();
    EXPECT_EQ(piece->getSymbol(), temp->getSymbol());
}



