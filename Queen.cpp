#include "Queen.h"
#include "ChessSquare.h"

Queen::Queen(int playerNumber) : ChessPiece(playerNumber) {

}

ChessPiece* Queen::getFigure() {
	return this;
}

WLink Queen::getIconLink() {
	WString player_name;
	if (ChessPiece::playerNumber == 1)
		player_name = "black";
	else
		player_name = "white";

	ChessPiece::iconLink.setUrl(("resources/Images/pieces/queen_" + player_name + ".png").toUTF8());
	return iconLink;
}

void Queen::checkMove(int x, int y, int currentPlayer, ChessSquare* clickedSquare, ChessSquare* chessSquares[8][8]) {
	
	int i = 1;
	while (clickedSquare->setMove(x + i, y, currentPlayer, chessSquares)) i++;
	i = 1;
	while (clickedSquare->setMove(x + i, y + i, currentPlayer, chessSquares)) i++;
	i = 1;
	while (clickedSquare->setMove(x + i, y - i, currentPlayer, chessSquares)) i++;
	i = 1;
	while (clickedSquare->setMove(x, y + i, currentPlayer, chessSquares)) i++;
	i = 1;
	while (clickedSquare->setMove(x, y - i, currentPlayer, chessSquares)) i++;
	i = 1;
	while (clickedSquare->setMove(x - i, y, currentPlayer, chessSquares)) i++;
	i = 1;
	while (clickedSquare->setMove(x - i, y + i, currentPlayer, chessSquares)) i++;
	i = 1;
	while (clickedSquare->setMove(x - i, y - i, currentPlayer, chessSquares)) i++;
}
