#include "ChessSquare.h"

ChessSquare::ChessSquare(int row, int column) : WPushButton() {
	this->row = row;
	this->column = column;
	chessPiece = nullptr;
	active = false;

	clicked().connect(this, &ChessSquare::clickEvent);

	if (column % 2 == 0) {
		if (row % 2 == 0) {
			setBaseColor(1);
			backgroundColor = Color::GRAY;
		}
		else {
			setBaseColor(0);
			backgroundColor = Color::WHITE;
		}
	}
	else {
		if (row % 2 == 0) {
			setBaseColor(0);
			backgroundColor = Color::WHITE;
		}
		else {
			setBaseColor(1);
			backgroundColor = Color::GRAY;
		}
	}
}

void ChessSquare::clickEvent() {
	if (active == true) {
		clickedChessSquareSignal.emit(row, column);
	}
}

void ChessSquare::setActive(Color color) {
	this->active = true;
	WPushButton::setEnabled(true);
	setBackgroundColor(color);
}

void ChessSquare::setActive(bool active) {
	this->active = active;
	WPushButton::setEnabled(active);
	this->setBackgroundColor(backgroundColor);
}

bool ChessSquare::isPiece() {
	if (chessPiece != nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void ChessSquare::setBackgroundColor(Color color) {
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

void ChessSquare::setBaseColor(int color) {
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

bool ChessSquare::isActive() {
	return active;
}

ChessPiece* ChessSquare::getPiece() {
	return chessPiece;
}

void ChessSquare::setPiece(ChessPiece* chessPiece) {
	this->chessPiece = chessPiece;
	setIcon(chessPiece->getIconLink());
}

void ChessSquare::removePiece() {
	chessPiece = nullptr;
	setIcon("resources/Images/pieces/blank.png");
}

std::string ChessSquare::toChessNotation()
{
	std::string coordinates;
	char x = column + 49;
	char y = row + 65;

	if (column >= 0 && column < 8 && row >= 0 && row < 8) {
		coordinates += x;
		coordinates += y;
	}
	return coordinates;
}

bool ChessSquare::setMove(int x, int y, int currentPlayer, ChessSquare* chessSquares[8][8])
{
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		if (chessSquares[x][y]->ChessSquare::isPiece() == true) {
			if (chessSquares[x][y]->getPiece()->getPlayer() != currentPlayer) {
				chessSquares[x][y]->setActive(Color::RED);
			}
			return false;
		}
		else {
			chessSquares[x][y]->setActive(Color::GREEN);
			return true;
		}
	}
	else {
		return false;
	}
}
void ChessSquare::setMovePawn(int x, int y, int currentPlayer, ChessSquare* chessSquares[8][8])
{
	if (currentPlayer == 0) {
		if (x + 1 < 8) {
			if (chessSquares[x + 1][y]->isPiece() == false) chessSquares[x + 1][y]->setActive(Color::GREEN);
			if (y + 1 < 8 && chessSquares[x + 1][y + 1]->isPiece() == true && chessSquares[x + 1][y + 1]->getPiece()->getPlayer() != currentPlayer) {
				chessSquares[x + 1][y + 1]->setActive(Color::RED);
			}
			if (y - 1 >= 0 && chessSquares[x + 1][y - 1]->isPiece() == true && chessSquares[x + 1][y - 1]->getPiece()->getPlayer() != currentPlayer) {
				chessSquares[x + 1][y - 1]->setActive(Color::RED);
			}
		}
		if (chessSquares[x][y]->getPiece()->getMoveNumber() == 0) {
			if (chessSquares[x + 2][y]->isPiece() == false) chessSquares[x + 2][y]->setActive(Color::GREEN);
		}
	}
	else {
		if (x - 1 >= 0) {
			if (chessSquares[x - 1][y]->isPiece() == false) chessSquares[x - 1][y]->setActive(Color::GREEN);
			if (y + 1 < 8 && chessSquares[x - 1][y + 1]->isPiece() == true && chessSquares[x - 1][y + 1]->getPiece()->getPlayer() != currentPlayer) {
				chessSquares[x - 1][y + 1]->setActive(Color::RED);
			}
			if (y - 1 >= 0 && chessSquares[x - 1][y - 1]->isPiece() == true && chessSquares[x - 1][y - 1]->getPiece()->getPlayer() != currentPlayer) {
				chessSquares[x - 1][y - 1]->setActive(Color::RED);
			}
		}
		if (chessSquares[x][y]->getPiece()->getMoveNumber() == 0) {
			if (chessSquares[x - 2][y]->isPiece() == false) chessSquares[x - 2][y]->setActive(Color::GREEN);
		}
	}
}


