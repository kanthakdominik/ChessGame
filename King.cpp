#include "King.h"
#include "ChessSquare.h"

King::King(int playerNumber) : ChessPiece(playerNumber) {

}

ChessPiece* King::getFigure() {
	return this;
}

WLink King::getIconLink() {
	WString player_name;
	if (ChessPiece::playerNumber == 1)
		player_name = "black";
	else
		player_name = "white";

	ChessPiece::iconLink.setUrl(("resources/Images/pieces/king_" + player_name + ".png").toUTF8());
	return iconLink;
}

void King::checkMove(int x, int y, int currentPlayer, ChessSquare* clickedSquare, ChessSquare* chessSquares[8][8]) {
	clickedSquare->setMove(x + 1, y - 1, currentPlayer, chessSquares);
	clickedSquare->setMove(x + 1, y,	 currentPlayer, chessSquares);
	clickedSquare->setMove(x + 1, y + 1, currentPlayer, chessSquares);
	clickedSquare->setMove(x	, y + 1, currentPlayer, chessSquares);
	clickedSquare->setMove(x	, y - 1, currentPlayer, chessSquares);
	clickedSquare->setMove(x - 1, y + 1, currentPlayer, chessSquares);
	clickedSquare->setMove(x - 1, y,	 currentPlayer, chessSquares);
	clickedSquare->setMove(x - 1, y + 1, currentPlayer, chessSquares);
}