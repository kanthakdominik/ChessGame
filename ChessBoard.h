#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"

#include "ChessPiece.h"
#include "Position.h"
#include "Move.h"
#include <array>

class ChessBoard
{
public:
	~ChessBoard();

	void setupWithDefault();

	ChessPiece* getPieceAt(Position pos);
	void placePieceAt(ChessPiece* const piece, Position pos);

	bool isThreatenedBy(Position targetPos, Color playerColor);
	std::vector<Move> getAllMovesFor(Color playerColor);

	void movePiece(Move move);
	void removePieceAt(Position pos);
	ChessBoard* testMove(Move move);

	void clear();

private:
	std::array<ChessPiece*, 64> fields{};

	int getFieldIndex(Position pos);
};

#endif // CHESSBOARD_H