#include "Piece.h"
#include "Board.h"
#include "Knight.h"
#include <fstream>
#include <gtest/gtest.h>

class test_Knight : public testing::Test {
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
    Board board;
};

TEST_F(test_Knight, testDefaultConstructor){
    bool col;
    PiecePtr piece;
    piece = new Knight(WHITE);
    col = piece->getColour();
    EXPECT_EQ(col, WHITE);
}

TEST_F(test_Knight, testGetSymbolWhite){
    char sym;
    PiecePtr piece;
    piece = new Knight(WHITE);
    sym = piece->getSymbol();
    EXPECT_EQ(sym, 'N');
}


TEST_F(test_Knight, testGetSymbolBlack){
    char sym;
    PiecePtr piece;
    piece = new Knight(BLACK);
    sym = piece->getSymbol();
    EXPECT_EQ(sym, 'n');
}

TEST_F(test_Knight, testCanMoveInvalidDestionation){
    bool moved;
    PiecePtr piece;
    piece = new Knight(WHITE);
    board.place(piece, 0, 0);
    moved = board.move(0, 0, 3, 2);
    EXPECT_EQ(moved, false);
}

TEST_F(test_Knight, testCanMoveValidEmptySpace){
    bool moved;
    PiecePtr piece;
    piece = new Knight(WHITE);
    board.place(piece, 0, 0);
    moved = board.move(0, 0, 1, 2);
    EXPECT_EQ(moved, true);
}

TEST_F(test_Knight, testCanMoveInvalidCaptureColour){
    bool moved;
    PiecePtr piece;
    piece = new Knight(WHITE);
    board.place(piece, 0, 0);
    piece = new Knight(WHITE);
    board.place(piece, 1, 2);
    moved = board.move(0, 0, 1, 2);
    EXPECT_EQ(moved, false);
}

TEST_F(test_Knight, testCanMoveValidCaptureColour){
    bool moved;
    PiecePtr piece;
    piece = new Knight(WHITE);
    board.place(piece, 0, 0);
    piece = new Knight(BLACK);
    board.place(piece, 2, 1);
    moved = board.move(0, 0, 2, 1);
    EXPECT_EQ(moved, true);
}

TEST_F(test_Knight, testClone){
    PiecePtr piece, temp;
    piece = new Knight(WHITE);
    temp = piece->clone();
    EXPECT_EQ(piece->getSymbol(), temp->getSymbol());
}
