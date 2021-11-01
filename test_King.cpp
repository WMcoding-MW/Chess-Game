#include "Piece.h"
#include "Board.h"
#include "King.h"
#include <fstream>
#include <gtest/gtest.h>

class test_King : public testing::Test {
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
    Board board;
};

TEST_F(test_King, testDefaultConstructor){
    bool col;
    PiecePtr piece;
    piece = new King(WHITE);
    col = piece->getColour();
    EXPECT_EQ(col, WHITE);
}

TEST_F(test_King, testGetSymbolWhite){
    char sym;
    PiecePtr piece;
    piece = new King(WHITE);
    sym = piece->getSymbol();
    EXPECT_EQ(sym, 'K');
}

TEST_F(test_King, testGetSymbolBlack){
    char sym;
    PiecePtr piece;
    piece = new King(BLACK);
    sym = piece->getSymbol();
    EXPECT_EQ(sym, 'k');
}

TEST_F(test_King, testCanMoveInvalidNonValidCoordinate){
    bool moved;
    PiecePtr piece;
    piece = new King(WHITE);
    board.place(piece, 0, 0);
    moved = board.move(0, 0, 4, 4);
    EXPECT_EQ(moved, false);
}

TEST_F(test_King, testCanMoveInvalidSameColour){
    bool moved;
    PiecePtr piece;
    piece = new King(WHITE);
    board.place(piece, 0, 0);
    piece = new King(WHITE);
    board.place(piece, 1, 1);
    moved = board.move(0, 0, 1, 1);
    EXPECT_EQ(moved, false);
}

TEST_F(test_King, testCanMoveValidDifferentColour){
    bool moved;
    PiecePtr piece;
    piece = new King(WHITE);
    board.place(piece, 0, 0);
    piece = new King(BLACK);
    board.place(piece, 1, 1);
    moved = board.move(0, 0, 1, 1);
    EXPECT_EQ(moved, true);
}

TEST_F(test_King, testCanMoveValid){
    bool moved;
    PiecePtr piece;
    piece = new King(WHITE);
    board.place(piece, 0, 0);
    moved = board.move(0, 0, 0, 1);
    EXPECT_EQ(moved, true);
}

TEST_F(test_King, testClone){
    PiecePtr piece, temp;
    piece = new King(WHITE);
    temp = piece->clone();
    EXPECT_EQ(piece->getSymbol(), temp->getSymbol());
}



