#include "ChessSquare.h"

ChessSquare::ChessSquare(int row, int column) : WPushButton(){
	this->row = row;
	this->column = column;
	chessPiece = nullptr;
	active = false;

	clicked().connect(this, &ChessSquare::clickEvent);

	if (column % 2 == 0) {
		if (row % 2 == 0) {
			setColor(1);
			backgroundColor = Color::GRAY;
		}
		else {
			setColor(0);
			backgroundColor = Color::WHITE;
		}
	}
	else {
		if (row % 2 == 0) {
			setColor(0);
			backgroundColor = Color::WHITE;
		}
		else {
			setColor(1);
			backgroundColor = Color::GRAY;
		}
	}
}

//Signal<int, int>& ChessSquare::clickedChessSquare() {
//	return clickedChessSquareSignal;
//}

void ChessSquare::clickEvent() {
	if (active == true) {
		clickedChessSquareSignal.emit(row, column);
	}
}

void ChessSquare::setActive(Color color){
	this->active = true;
	WPushButton::setEnabled(true);
	setBackgroundColor(color);
}

void ChessSquare::setActive(bool active){
	this->active = active;
	WPushButton::setEnabled(active);
	this->setBackgroundColor(backgroundColor);
}

bool ChessSquare::isPiece(){
	if (chessPiece != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void ChessSquare::setBackgroundColor(Color color){
	this->backgroundColor = color;

	switch (color) {
	case Color::WHITE:
		setStyleClass("chessButtonWhite");
		break;
	case Color::GRAY:
		setStyleClass("chessButtonGray");
		break;
	case Color::RED:
		setStyleClass("chessButtonRed");
		break;
	case Color::GREEN:
		setStyleClass("chessButtonGreen");
		break;
	default: break;
	}
}

void ChessSquare::setColor(int color){
	switch (color) {
	case 0:
		setStyleClass("chessButtonWhite");
		break;
	case 1:
		setStyleClass("chessButtonGray");
		break;
	default:
		throw WString("Incorrect chess square color");
		break;
	}
	this->color = color;
}

bool ChessSquare::isActive(){
	return active;
}

ChessPiece* ChessSquare::getPiece(){
	return chessPiece;
}

void ChessSquare::setPiece(ChessPiece* chessPiece){
	this->chessPiece = chessPiece;
	setIcon(chessPiece->getIconLink());
}

void ChessSquare::removePiece(){
	chessPiece = nullptr;
	setIcon("");
}

ChessSquare::~ChessSquare(){
	//log("info") << "ChessSquare deleted.";
}


