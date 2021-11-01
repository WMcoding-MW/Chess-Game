#include "Piece.h"
#include "Board.h"
#include "Queen.h"
#include "Pawn.h"
#include "Rook.h"
#include <fstream>
#include <gtest/gtest.h>
class test_Piece : public testing::Test {
protected:
    virtual void SetUp()
    {
    }
    virtual void TearDown()
    {
    }
    PiecePtr piece;
};

TEST_F(test_Piece, testDefaultConstructorWhite){
    bool col;
    piece = new Pawn(WHITE);
    col = piece->getColour();
    EXPECT_EQ(col, WHITE);
}

TEST_F(test_Piece, testDefaultConstructorBlack){
    bool col;
    piece = new Pawn(BLACK);
    col = piece->getColour();
    EXPECT_EQ(col, BLACK);
}

TEST_F(test_Piece, testCanMoveValid1){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    move = board.move(0, 0, 1, 0);
    EXPECT_EQ(true, move);
}

TEST_F(test_Piece, testCanMoveValid2){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    move = piece->canMove(board, 0, 0, 2, 0);
    EXPECT_EQ(true, move);
}


TEST_F(test_Piece, testCanMoveOccupiedPawn){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    piece = new Pawn(BLACK);
    board.place(piece, 1, 0);
    move = piece->canMove(board, 0, 0, 1, 0);
    EXPECT_EQ(false, move);
}

TEST_F(test_Piece, testCanMoveInvalidMovePawnX){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    move = piece->canMove(board, 0, 0, 6, 0);
    EXPECT_EQ(false, move);

}

TEST_F(test_Piece, testCanMoveInvalidMovePawnY){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    move = piece->canMove(board, 0, 0, 1, 6);
    EXPECT_EQ(false, move);
}


TEST_F(test_Piece, testCanMoveInvalidMoveHasMoved2){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    piece->notifyMoved();
    move = piece->canMove(board, 0, 0, 2, 0);
    EXPECT_EQ(false, move);

}

TEST_F(test_Piece, testCanMoveValidMovePawnCapture){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    piece = new Pawn(WHITE);
    board.place(piece, 1, 1);
    move = board.move(0, 0, 1, 1);
    EXPECT_EQ(true, move);
}

TEST_F(test_Piece, testCanMoveInvalidMovePawnCapture){
    Board board;
    bool move;
    piece = new Pawn(BLACK);
    board.place(piece, 0, 0);
    move = piece->canMove(board, 0, 0, 1, 1);
    EXPECT_EQ(false, move);
}

TEST_F(test_Piece, testCheckDiagonalTopLeftValid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    move = piece->canMove(board, 4, 4, 2, 2);
    EXPECT_EQ(true, move);
}

TEST_F(test_Piece, testCheckDiagonalTopLeftInvalid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    piece = new Queen(BLACK);
    board.place(piece, 3, 3);
    move = piece->canMove(board, 4, 4, 2, 2);
    EXPECT_EQ(false, move);
}


TEST_F(test_Piece, testCheckDiagonalTopRightValid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    move = piece->canMove(board, 4, 4, 2, 6);
    EXPECT_EQ(true, move);
}

TEST_F(test_Piece, testCheckDiagonalTopRightInvalid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    piece = new Queen(BLACK);
    board.place(piece, 3, 5);
    move = piece->canMove(board, 4, 4, 2, 6);
    EXPECT_EQ(false, move);
}


TEST_F(test_Piece, testCheckDiagonalBottomRightValid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    move = piece->canMove(board, 4, 4, 6, 6);
    EXPECT_EQ(true, move);
}

TEST_F(test_Piece, testCheckDiagonalBottomRightInvalid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    piece = new Queen(BLACK);
    board.place(piece, 5, 5);
    move = piece->canMove(board, 4, 4, 6, 6);
    EXPECT_EQ(false, move);
}

TEST_F(test_Piece, testCheckDiagonalBottomLeftValid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    move = piece->canMove(board, 4, 4, 6, 2);
    EXPECT_EQ(true, move);
}

TEST_F(test_Piece, testCheckDiagonalBottomLeftInvalid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    piece = new Queen(BLACK);
    board.place(piece, 5, 3);
    move = piece->canMove(board, 4, 4, 6, 2);
    EXPECT_EQ(false, move);
}

TEST_F(test_Piece, testCheckVerticalHorizontalUpValid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    move = piece->canMove(board, 4, 4, 2, 4);
    EXPECT_EQ(true, move);
}

TEST_F(test_Piece, testCheckVerticalHorizontalUpInvalid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    piece = new Queen(BLACK);
    board.place(piece, 3, 4);
    move = piece->canMove(board, 4, 4, 2, 4);
    EXPECT_EQ(false, move);
}

TEST_F(test_Piece, testCheckVerticalHorizontalDownValid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    move = piece->canMove(board, 4, 4, 6, 4);
    EXPECT_EQ(true, move);
}

TEST_F(test_Piece, testCheckVerticalHorizontalDownInvalid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    piece = new Queen(BLACK);
    board.place(piece, 5, 4);
    move = piece->canMove(board, 4, 4, 6, 4);
    EXPECT_EQ(false, move);
}

TEST_F(test_Piece, testCheckVerticalHorizontalRightValid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    move = piece->canMove(board, 4, 4, 4, 6);
    EXPECT_EQ(true, move);
}

TEST_F(test_Piece, testCheckVerticalHorizontalRightInvalid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    piece = new Queen(BLACK);
    board.place(piece, 4, 5);
    move = piece->canMove(board, 4, 4, 4, 6);
    EXPECT_EQ(false, move);
}

TEST_F(test_Piece, testCheckVerticalHorizontalLeftValid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    move = piece->canMove(board, 4, 4, 4, 2);
    EXPECT_EQ(true, move);
}

TEST_F(test_Piece, testCheckVerticalHorizontalLeftInvalid){
    Board board;
    bool move;
    piece = new Queen(BLACK);
    board.place(piece, 4, 4);
    piece = new Queen(BLACK);
    board.place(piece, 4, 3);
    move = piece->canMove(board, 4, 4, 4, 2);
    EXPECT_EQ(false, move);
}

TEST_F(test_Piece, testNotifyMove){
     Board board;
     bool move;
     piece = new Pawn(BLACK);
     piece->notifyMoved();
     board.place(piece, 0, 0);
     move = board.move(0, 0, 2, 0);
     EXPECT_EQ(false, move);
}

TEST_F(test_Piece, testCanMoveRookValidEmptyDestinationVertical){
    Board board;
    bool moved;
    PiecePtr piece = new Rook(WHITE);
    board.place(piece, 0, 0);
    moved = board.move(0, 0, 5, 0);
    EXPECT_EQ(moved, true);
}

TEST_F(test_Piece, testCanMoveRookValidEmptyDestinationHorizontal){
    Board board;
    bool moved;
    PiecePtr piece = new Rook(WHITE);
    board.place(piece, 0, 0);
    moved = board.move(0, 0, 0, 5);
    EXPECT_EQ(moved, true);
}

