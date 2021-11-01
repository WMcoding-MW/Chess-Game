#include "Piece.h"
#include "Board.h"
#include "Bishop.h"
#include <fstream>
#include <gtest/gtest.h>

class test_Bishop : public testing::Test {
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
    Board board;
};

TEST_F(test_Bishop, testDefaultConstructor){
    bool col;
    PiecePtr piece;
    piece = new Bishop(WHITE);
    col = piece->getColour();
    EXPECT_EQ(col, WHITE);
}

TEST_F(test_Bishop, testGetSymbolWhite){
    char sym;
    PiecePtr piece;
    piece = new Bishop(WHITE);
    sym = piece->getSymbol();
    EXPECT_EQ(sym, 'B');
}

TEST_F(test_Bishop, testCanMoveInvalidNotDiagnol){
    bool moved;
    PiecePtr piece;
    piece = new Bishop(WHITE);
    board.place(piece, 0, 0);
    moved = board.move(0, 0, 5, 4);
    EXPECT_EQ(moved, false);
}

TEST_F(test_Bishop, testCanMoveInvalidPathNotClear){
    bool moved;
    PiecePtr piece;
    piece = new Bishop(WHITE);
    board.place(piece, 0, 0);
    piece = new Bishop(WHITE);
    board.place(piece, 3, 3);
    moved = board.move(0, 0, 6, 6);
    EXPECT_EQ(moved, false);
}


TEST_F(test_Bishop, testCanMoveValidPathNoPieceAtDestination){
    bool moved;
    PiecePtr piece;
    piece = new Bishop(WHITE);
    board.place(piece, 0, 0);
    moved = board.move(0, 0, 4, 4);
    EXPECT_EQ(moved, true);
}

TEST_F(test_Bishop, testCanMoveValidPathSameColourAtDestination){
    bool moved;
    PiecePtr piece;
    piece = new Bishop(WHITE);
    board.place(piece, 0, 0);
    piece = new Bishop(WHITE);
    board.place(piece, 4, 4);
    moved = board.move(0, 0, 4, 4);
    EXPECT_EQ(moved, false);
}

TEST_F(test_Bishop, testCanMoveValidPathDifferentColourAtDestination){
    bool moved;
    PiecePtr piece;
    piece = new Bishop(WHITE);
    board.place(piece, 0, 0);
    piece = new Bishop(BLACK);
    board.place(piece, 4, 4);
    moved = board.move(0, 0, 4, 4);
    EXPECT_EQ(moved, true);
}

TEST_F(test_Bishop, testClone){
    PiecePtr piece, temp;
    piece = new Bishop(WHITE);
    temp = piece->clone();
    EXPECT_EQ(piece->getSymbol(), temp->getSymbol());
}

