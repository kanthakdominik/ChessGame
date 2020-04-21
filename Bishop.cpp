#include "Bishop.h"

Bishop::Bishop(int playerNumber) : ChessPiece(playerNumber) {
}

WLink ChessPiece::getIconLink() {
	WString player_name;
	if (ChessPiece::playerNumber == 1)
		player_name = "black";
	else
		player_name = "white";

	ChessPiece::iconLink.setUrl(("resources/Images/pieces/bishop_" + player_name + ".png").toUTF8());
	return ChessPiece::iconLink;
}

ChessPiece* ChessPiece::getFigure() {
	return this;
}