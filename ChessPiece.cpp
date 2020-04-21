#include "ChessPiece.h"

ChessPiece::ChessPiece(int playerNumber){
	this->playerNumber = playerNumber;
	moveNumber = 0;
}

//WLink ChessPiece::getIconLink(){
//	WString player_name;
//	if (playerNumber == 1)
//		player_name = "black";
//	else
//		player_name = "white";
//
//	switch (figure) {
//	case Figure::KING:
//		iconLink.setUrl(("resources/Images/pieces/king_" + player_name + ".png").toUTF8());
//		break;
//	case Figure::BISHOP:
//		iconLink.setUrl(("resources/Images/pieces/bishop_" + player_name + ".png").toUTF8());
//		break;
//	case Figure::KNIGHT:
//		iconLink.setUrl(("resources/Images/pieces/knight_" + player_name + ".png").toUTF8());
//		break;
//	case Figure::QUEEN:
//		iconLink.setUrl(("resources/Images/pieces/queen_" + player_name + ".png").toUTF8());
//		break;
//	case Figure::ROOK:
//		iconLink.setUrl(("resources/Images/pieces/rook_" + player_name + ".png").toUTF8());
//		break;
//	case Figure::PAWN:
//		iconLink.setUrl(("resources/Images/pieces/pawn_" + player_name + ".png").toUTF8());
//		break;
//	default: 
//		iconLink.setUrl("resources/Images/pieces/blank.png");
//		break;
//	}
//	return iconLink;
//}

int ChessPiece::getPlayer(){
	return playerNumber;
}

int ChessPiece::getMoveNumber(){
	return moveNumber;
}

void ChessPiece::nextMove(){
	moveNumber++;
}

ChessPiece::~ChessPiece(){
	//log("info") << "ChessPiece deleted";
}
