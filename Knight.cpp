#include "Knight.h"
#include "ChessSquare.h"

Knight::Knight(int playerNumber) : ChessPiece(playerNumber) {

}

ChessPiece* Knight::getFigure() {
	return this;
}

WLink Knight::getIconLink() {
	WString player_name;
	if (ChessPiece::playerNumber == 1)
		player_name = "black";
	else
		player_name = "white";

	ChessPiece::iconLink.setUrl(("resources/Images/pieces/knight_" + player_name + ".png").toUTF8());
	return iconLink;
}

void Knight::checkMove(int x, int y, int currentPlayer, ChessSquare* clickedSquare, ChessSquare* chessSquares[8][8]) {
	
	clickedSquare->setMove(x + 2, y + 1, currentPlayer, chessSquares);
	clickedSquare->setMove(x + 2, y - 1, currentPlayer, chessSquares);
	clickedSquare->setMove(x - 2, y + 1, currentPlayer, chessSquares);
	clickedSquare->setMove(x - 2, y - 1, currentPlayer, chessSquares);
	clickedSquare->setMove(x + 1, y + 2, currentPlayer, chessSquares);
	clickedSquare->setMove(x + 1, y - 2, currentPlayer, chessSquares);
	clickedSquare->setMove(x - 1, y + 2, currentPlayer, chessSquares);
	clickedSquare->setMove(x - 1, y - 2, currentPlayer, chessSquares);
}
