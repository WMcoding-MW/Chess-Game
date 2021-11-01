#include "Piece.h"
#include "Board.h"
#include "Queen.h"
#include <fstream>
#include <gtest/gtest.h>

class test_Queen : public testing::Test {
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
    Board board;
};

TEST_F(test_Queen, testDefaultConstructor){
    bool col;
    PiecePtr piece;
    piece = new Queen(WHITE);
    col = piece->getColour();
    EXPECT_EQ(col, WHITE);
}

TEST_F(test_Queen, testGetSymbolWhite){
    char sym;
    PiecePtr piece;
    piece = new Queen(WHITE);
    sym = piece->getSymbol();
    EXPECT_EQ(sym, 'Q');
}

TEST_F(test_Queen, testGetSymbolBlack){
    char sym;
    PiecePtr piece;
    piece = new Queen(BLACK);
    sym = piece->getSymbol();
    EXPECT_EQ(sym, 'q');
}

TEST_F(test_Queen, testCanMoveInvalidPieceInWay){
    bool moved;
    PiecePtr piece;
    piece = new Queen(BLACK);
    board.place(piece, 3, 3);
    piece = new Queen(BLACK);
    board.place(piece, 3, 4);
    moved = board.move(3, 3, 3, 5);
    EXPECT_EQ(moved, false);
}

TEST_F(test_Queen, testCanMoveInvalidPieceColourAtDestination){
    bool moved;
    PiecePtr piece;
    piece = new Queen(BLACK);
    board.place(piece, 3, 3);
    piece = new Queen(BLACK);
    board.place(piece, 3, 5);
    moved = board.move(3, 3, 3, 5);
    EXPECT_EQ(moved, false);
}

TEST_F(test_Queen, testCanMoveValidPieceColourAtDestination){
    bool moved;
    PiecePtr piece;
    piece = new Queen(BLACK);
    board.place(piece, 3, 3);
    piece = new Queen(WHITE);
    board.place(piece, 3, 5);
    moved = board.move(3, 3, 3, 5);
    EXPECT_EQ(moved, true);
}

TEST_F(test_Queen, testCanMoveValidEmptySpotDiagonal){
    bool moved;
    PiecePtr piece;
    piece = new Queen(BLACK);
    board.place(piece, 3, 3);
    moved = board.move(3, 3, 5, 5);
    EXPECT_EQ(moved, true);
}

TEST_F(test_Queen, testClone){
    PiecePtr piece, temp;
    piece = new Queen(WHITE);
    temp = piece->clone();
    EXPECT_EQ(piece->getSymbol(), temp->getSymbol());
}



