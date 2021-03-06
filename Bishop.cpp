#include "Bishop.h"
#include "ChessSquare.h"

Bishop::Bishop(int playerNumber) : ChessPiece(playerNumber) {

}

ChessPiece* Bishop::getFigure() {
	return this;
}

WLink Bishop::getIconLink() {
	WString player_name;
	if (ChessPiece::playerNumber == 1)
		player_name = "black";
	else
		player_name = "white";

	ChessPiece::iconLink.setUrl(("resources/Images/pieces/bishop_" + player_name + ".png").toUTF8());
	return iconLink;
}

void Bishop::checkMove(int x, int y, int currentPlayer, ChessSquare* clickedSquare, ChessSquare* chessSquares[8][8]){

	int i = 1;
	while (clickedSquare->setMove(x + i, y + i, currentPlayer, chessSquares)) i++;
	i = 1;
	while (clickedSquare->setMove(x + i, y - i, currentPlayer, chessSquares)) i++;
	i = 1;
	while (clickedSquare->setMove(x - i, y + i, currentPlayer, chessSquares)) i++;
	i = 1;
	while (clickedSquare->setMove(x - i, y - i, currentPlayer, chessSquares)) i++;
}
