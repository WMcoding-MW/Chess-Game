#include "Piece.h"
#include "Board.h"
#include "Pawn.h"
#include <fstream>
#include <string>
#include <typeinfo>
#include <gtest/gtest.h>
class test_Pawn : public testing::Test {
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
    PiecePtr piece;
};

TEST_F(test_Pawn, testDefaultConstructorWhite){
    bool col;
    piece = new Pawn(WHITE);
    col = piece->getColour();
    EXPECT_EQ(col, WHITE);
}

TEST_F(test_Pawn, testDefaultConstructorBlack){
    bool col;
    piece = new Pawn(BLACK);
    col = piece->getColour();
    EXPECT_EQ(col, BLACK);
}

TEST_F(test_Pawn, testGetSymbolWhite){
    char sym;
    piece = new Pawn(WHITE);
    sym = piece->getSymbol();
    EXPECT_EQ(sym, 'P');
}

TEST_F(test_Pawn, testGetSymbolBLACK){
    char sym;
    piece = new Pawn(BLACK);
    sym = piece->getSymbol();
    EXPECT_EQ(sym, 'p');
}

TEST_F(test_Pawn, testCanMoveValid1){
    PiecePtr h;
    Board board;
    bool move;
    h = new Pawn(BLACK);
    board.place(h, 0, 0);
    move = h->canMove(board, 0, 0, 1, 0);
    EXPECT_EQ(true, move);
}

TEST_F(test_Pawn, testCanMoveValid2){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    move = piece->canMove(board, 0, 0, 2, 0);
    EXPECT_EQ(true, move);
}


TEST_F(test_Pawn, testCanMoveOccupiedPawn){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    piece = new Pawn(BLACK);
    board.place(piece, 1, 0);
    move = piece->canMove(board, 0, 0, 1, 0);
    EXPECT_EQ(false, move);
}

TEST_F(test_Pawn, testCanMoveInvalidMovePawnX){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    move = piece->canMove(board, 0, 0, 6, 0);
    EXPECT_EQ(false, move);

}

TEST_F(test_Pawn, testCanMoveInvalidMovePawnY){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    move = piece->canMove(board, 0, 0, 1, 6);
    EXPECT_EQ(false, move);
}


TEST_F(test_Pawn, testCanMoveInvalidMoveHasMoved2){
    Board board;
    bool move;
    PiecePtr temp;
    temp = new Pawn(BLACK);
    board.place(temp, 0, 0);
    temp->notifyMoved();
    move = temp->canMove(board, 0, 0, 2, 0);
    EXPECT_EQ(false, move);

}

TEST_F(test_Pawn, testCanMoveValidMoveFirst2Then1){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    move = piece->canMove(board, 0, 0, 2, 0);
    move = piece->canMove(board, 2, 0, 3, 0);
    EXPECT_EQ(true, move);

}

TEST_F(test_Pawn, testCanMoveInvalidMovePawnCapture){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    piece = new Pawn(BLACK);
    board.place(piece, 1, 1);
    move = piece->canMove(board, 0, 0, 1, 1);
    EXPECT_EQ(false, move);

}

TEST_F(test_Pawn, testCanMoveValidMovePawnCapture){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    piece = new Pawn(WHITE);
    board.place(piece, 1, 1);
    board.write(std::cout);
    move = board.move(0, 0, 1, 1);
    EXPECT_EQ(true, move);
}

TEST_F(test_Pawn, testClone){
    Board board;
    PiecePtr temp;
    piece = new Pawn(BLACK);
    temp = piece->clone();
    EXPECT_EQ(temp->getSymbol(), piece->getSymbol());
    }

TEST_F(test_Pawn, testNotifyMove){
    Board board;
    bool move;
    Pawn *temp;
    temp = new Pawn(BLACK);
    temp->notifyMoved();
    board.place(temp, 0, 0);
    move = board.move(0, 0, 2, 0);
    EXPECT_EQ(move, false);
}


