#include "Pawn.h"
#include "ChessSquare.h"

Pawn::Pawn(int playerNumber) : ChessPiece(playerNumber) {

}

ChessPiece* Pawn::getFigure() {
	return this;
}

WLink Pawn::getIconLink() {
	WString player_name;
	if (ChessPiece::playerNumber == 1)
		player_name = "black";
	else
		player_name = "white";

	ChessPiece::iconLink.setUrl(("resources/Images/pieces/pawn_" + player_name + ".png").toUTF8());
	return iconLink;
}

void Pawn::checkMove(int x, int y, int currentPlayer, ChessSquare* clickedSquare, ChessSquare* chessSquares[8][8]) {
	clickedSquare->setMovePawn(x, y, currentPlayer, chessSquares);
}