#include "ChessSquare.h"

ChessSquare::ChessSquare(int row, int column) : WPushButton()
{
	this->row = row;
	this->column = column;
	chessPiece = nullptr;
	active = false;

	clicked().connect(this, &ChessSquare::process);

	if (column % 2 == 0) {
		if (row % 2 == 0)
			this->setColor(Color::GRAY);
		else
			this->setColor(Color::WHITE);
	}
	else {
		if (row % 2 == 0)
			this->setColor(Color::WHITE);
		else
			this->setColor(Color::GRAY);
	}
}

void ChessSquare::process() {
	clickedChessSquare_.emit(row, column); 
}

void ChessSquare::setActive(Color color)
{
	this->active = true;
	setColor(color);
}

void ChessSquare::setActive(bool active)
{
	this->active = active;
	this->setColor(Color::WHITE);

}

bool ChessSquare::isPiece()
{
	if (chessPiece != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

bool ChessSquare::isActive()
{
	return active;
}

ChessPiece* ChessSquare::getPiece()
{
	return chessPiece;
}

void ChessSquare::setPiece(ChessPiece* chessPiece)
{
	this->chessPiece = chessPiece;
	setIcon(chessPiece->getIconLink());
}

void ChessSquare::removePiece()
{
	chessPiece = nullptr;
	setIcon("");
}

WString ChessSquare::toChessNotation()
{
	WString coordinates;
	char  x = column + 49;
	char y = row + 65;
	if (column >= 0 && column < 8 && row >= 0 && row < 8) {
		coordinates += &x;
		coordinates += &y;
	}
	return coordinates;
}

void ChessSquare::setColor(Color color)
{
	this->color = color;

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

Signal<int, int>& ChessSquare::clickedChessSquare()
{
	return clickedChessSquare_;
}

ChessSquare::~ChessSquare()
{

}


