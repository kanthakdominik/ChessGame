#include "Rook.h"
#include "ChessSquare.h"

Rook::Rook(int playerNumber) : ChessPiece(playerNumber) {

}

ChessPiece* Rook::getFigure() {
	return this;
}

WLink Rook::getIconLink() {
	WString player_name;
	if (ChessPiece::playerNumber == 1)
		player_name = "black";
	else
		player_name = "white";

	ChessPiece::iconLink.setUrl(("resources/Images/pieces/rook_" + player_name + ".png").toUTF8());
	return iconLink;
}

void Rook::checkMove(int x, int y, int currentPlayer, ChessSquare* clickedSquare, ChessSquare* chessSquares[8][8]) {

	int i = 1;
	while (clickedSquare->setMove(x + i, y, currentPlayer, chessSquares)) i++;
	i = 1;
	while (clickedSquare->setMove(x - i, y, currentPlayer, chessSquares)) i++;
	i = 1;
	while (clickedSquare->setMove(x, y - i, currentPlayer, chessSquares)) i++;
	i = 1;
	while (clickedSquare->setMove(x, y + i, currentPlayer, chessSquares)) i++;
}
