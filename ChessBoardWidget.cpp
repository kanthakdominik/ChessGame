#include "ChessBoardWidget.h"
#include "Wt/WBreak.h"
#include "Wt/WLineEdit.h"
#include "Wt/WText.h"
#include "Wt/WGridLayout.h"

ChessBoardWidget::ChessBoardWidget() : WContainerWidget()
{
	setStyleClass("chess-box");
	currentPlayer = 1;
}

void ChessBoardWidget::generateChessBoard()
{
	chessBoard = this->addWidget(std::make_unique<Wt::WContainerWidget>());
	chessBoard->setStyleClass("centerWidget");
	chessBoard->setHeight(512);
	chessBoard->setWidth(512);
	auto grid = chessBoard->setLayout(cpp14::make_unique<Wt::WGridLayout>());

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			chessSquares[i][j] = grid->addWidget(cpp14::make_unique<ChessSquare>(i, j), i, j);
			chessSquares[i][j]->clickedChessSquareSignal.connect(this, &ChessBoardWidget::validateClick);
		}
	}
}

void ChessBoardWidget::move()
{
	if (chessSquares[dx][dy]->isActive() == false) {
		throw WString("B³¹d! Podane wspó³rzêdne s¹ niepoprawne.");
	}
	ChessPiece* sourcePiece = chessSquares[sx][sy]->getPiece();
	chessSquares[sx][sy]->removePiece();
	if (chessSquares[dx][dy]->isPiece() == true) {
		if (instanceof<King>(chessSquares[dx][dy]->getPiece()->getFigure())) {
			//Szach mat
			checkMateSignal.emit(currentPlayer);
			return;
		}
		lostPiecesList.push_back(chessSquares[dx][dy]->getPiece());
		newLostSignal.emit(chessSquares[dx][dy]->getPiece()->getIconLink());
		chessSquares[dx][dy]->removePiece();
	}
	chessSquares[dx][dy]->setPiece(sourcePiece);

	//Zmiana gracza
	if (currentPlayer == 0) currentPlayer = 1;
	else currentPlayer = 0;

	sourcePiece->increaseMoveNumber();
	history.push_back(chessSquares[sx][sy]->toChessNotation());
	history.push_back(chessSquares[dx][dy]->toChessNotation());

	nextMoveSignal.emit();
	updateSquares();
}

void ChessBoardWidget::setCurrentPlayer(int player) {
	currentPlayer = player;
}

void ChessBoardWidget::resetChessboard()
{
	setCurrentPlayer(1);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chessSquares[i][j]->isPiece()) {
				delete chessSquares[i][j]->getPiece();
			}
		}
	}
	lostPiecesList.clear();
	history.clear();
}

void ChessBoardWidget::updateSquares()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (chessSquares[i][j]->isPiece() == true && chessSquares[i][j]->getPiece()->getPlayer() == currentPlayer) {
				chessSquares[i][j]->setActive(true);
			}
			else {
				chessSquares[i][j]->setActive(false);
			}
		}
	}
	setDefaultColors();
}

void ChessBoardWidget::blockAllSquares()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			chessSquares[i][j]->setActive(false);
		}
	}
}

void ChessBoardWidget::generateChessPieces()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			chessSquares[i][j]->removePiece();
		}
	}
	rook1_black = new Rook(1);
	rook2_black = new Rook(1);
	knight1_black = new Knight(1);
	knight2_black = new Knight(1);
	bishop1_black = new Bishop(1);
	bishop2_black = new Bishop(1);
	queen_black = new Queen(1);
	king_black = new King(1);
	for (int i = 0; i < 8; i++) {
		pawns_black[i] = new Pawn(1);
	}
	rook1_white = new Rook(0);
	rook2_white = new Rook(0);
	knight1_white = new Knight(0);
	knight2_white = new Knight(0);
	bishop1_white = new Bishop(0);
	bishop2_white = new Bishop(0);
	queen_white = new Queen(0);
	king_white = new King(0);
	for (int i = 0; i < 8; i++) {
		pawns_white[i] = new Pawn(0);
	}
	//black pieces
	chessSquares[7][0]->setPiece(rook1_black);
	chessSquares[7][1]->setPiece(knight1_black);
	chessSquares[7][2]->setPiece(bishop1_black);
	chessSquares[7][3]->setPiece(queen_black);
	chessSquares[7][4]->setPiece(king_black);
	chessSquares[7][5]->setPiece(bishop2_black);
	chessSquares[7][6]->setPiece(knight2_black);
	chessSquares[7][7]->setPiece(rook2_black);
	for (int i = 0; i < 8; i++) {
		chessSquares[6][i]->setPiece(pawns_black[i]);
	}
	//white pieces
	chessSquares[0][0]->setPiece(rook1_white);
	chessSquares[0][1]->setPiece(knight1_white);
	chessSquares[0][2]->setPiece(bishop1_white);
	chessSquares[0][3]->setPiece(queen_white);
	chessSquares[0][4]->setPiece(king_white);
	chessSquares[0][5]->setPiece(bishop2_white);
	chessSquares[0][6]->setPiece(knight2_white);
	chessSquares[0][7]->setPiece(rook2_white);
	for (int i = 0; i < 8; i++) {
		chessSquares[1][i]->setPiece(pawns_white[i]);
	}
	updateSquares();
}

void ChessBoardWidget::validateClick(int x, int y)
{
	ChessSquare* square = chessSquares[x][y];
	if (square->isPiece() == true && square->getPiece()->getPlayer() == currentPlayer) {
		updateSquares();
		square->setActive(Color::GREEN);
		sx = x;
		sy = y;
		int i;
		square->getPiece()->getFigure()->checkMove(x, y, currentPlayer, square, chessSquares);
	}
	else {
		dx = x;
		dy = y;
		move();
	}
}

void ChessBoardWidget::setDefaultColors()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					chessSquares[i][j]->setBackgroundColor(Color::GRAY);
				}
				else {
					chessSquares[i][j]->setBackgroundColor(Color::WHITE);
				}
			}
			else {
				if (j % 2 == 0) {
					chessSquares[i][j]->setBackgroundColor(Color::WHITE);
				}
				else {
					chessSquares[i][j]->setBackgroundColor(Color::GRAY);
				}
			}
		}
	}
}

void ChessBoardWidget::readFromText(std::string line)
{
	int new_sy = (int)line.at(0) - 49;
	int new_sx = (int)line.at(1) - 65;
	validateClick(new_sx, new_sy);
	int new_dy = (int)line.at(3) - 49;
	int new_dx = (int)line.at(4) - 65;
	validateClick(new_dx, new_dy);
}
