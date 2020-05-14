#include "ChessPiece.h"
#include "ChessSquare.h"

ChessPiece::ChessPiece(int playerNumber) {
	this->playerNumber = playerNumber;
	moveNumber = 0;
}

WLink ChessPiece::getIconLink() {
	iconLink.setUrl("resources/Images/pieces/blank.png");
	return iconLink;
}

ChessPiece* ChessPiece::getFigure() {
	return this;
}

int ChessPiece::getPlayer() {
	return playerNumber;
}

int ChessPiece::getMoveNumber() {
	return moveNumber;
}

void ChessPiece::increaseMoveNumber() {
	moveNumber++;
}

void ChessPiece::checkMove(int x, int y, int currentPlayer, ChessSquare* clickedSquare, ChessSquare* chessSquares[8][8]) {
}

