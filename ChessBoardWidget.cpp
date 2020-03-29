#include "ChessBoardWidget.h"

#include "Wt/WBreak.h"
#include "Wt/WLineEdit.h"
#include "Wt/WText.h"
#include "Wt/WGridLayout.h"

ChessBoardWidget::ChessBoardWidget() : WContainerWidget()
{
	setStyleClass("chess-box");
	currentPlayer = 0;
	generateChessBoard();
	generateChessPieces();
}

void ChessBoardWidget::generateChessBoard() {

	chessBoard = this->addWidget(std::make_unique<Wt::WContainerWidget>());
	chessBoard->setStyleClass("centerWidget");
	chessBoard->setHeight(512);
	chessBoard->setWidth(512);
	auto grid = chessBoard->setLayout(Wt::cpp14::make_unique<Wt::WGridLayout>());

	for (int row = 0; row < 8; ++row) {
		for (int column = 0; column < 8; ++column) {
			chessSquares[row][column] = grid->addWidget(cpp14::make_unique<ChessSquare>(row, column), row, column);
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
        if (chessSquares[dx][dy]->getPiece()->getFigure() == Figure::KING) {
            //Szach mat
           // emit checkMate(currentPlayer);
            return;
        }
        lost.push_back(chessSquares[dx][dy]->getPiece());
        chessSquares[dx][dy]->removePiece();
       // emit newLost();
    }
    chessSquares[dx][dy]->setPiece(sourcePiece);

    //Zmiana gracza
    if (currentPlayer == 0) currentPlayer = 1;
    else currentPlayer = 0;

    sourcePiece->nextMove();
   // emit nextMove();
    updateSquares();
}

bool ChessBoardWidget::checkActive(int x, int y)
{
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if (chessSquares[x][y]->isPiece() == true) {
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

void ChessBoardWidget::setCurrentPlayer(int player)
{
    currentPlayer = player;
}

void ChessBoardWidget::resetChessboard()
{
    setCurrentPlayer(0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chessSquares[i][j]->isPiece()) {
                delete chessSquares[i][j]->getPiece();
            }
        }
    }
    lost.clear();
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
}

void ChessBoardWidget::blockAllSquares()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chessSquares[i][j]->setActive(false);
        }
    }
}

void ChessBoardWidget::generateChessPieces() {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chessSquares[i][j]->removePiece();
        }
    }

	rook1_black = new ChessPiece(1, Figure::ROOK);
	rook2_black = new ChessPiece(1, Figure::ROOK);
	knight1_black = new ChessPiece(1, Figure::KNIGHT);
	knight2_black = new ChessPiece(1, Figure::KNIGHT);
	bishop1_black = new ChessPiece(1, Figure::BISHOP);
	bishop2_black = new ChessPiece(1, Figure::BISHOP);
	queen_black = new ChessPiece(1, Figure::QUEEN);
	king_black = new ChessPiece(1, Figure::KING);
	for (int i = 0; i < 8; i++) {
		pawns_black[i] = new ChessPiece(1, Figure::PAWN);
	}

	rook1_white = new ChessPiece(0, Figure::ROOK);
	rook2_white = new ChessPiece(0, Figure::ROOK);
	knight1_white = new ChessPiece(0, Figure::KNIGHT);
	knight2_white = new ChessPiece(0, Figure::KNIGHT);
	bishop1_white = new ChessPiece(0, Figure::BISHOP);
	bishop2_white = new ChessPiece(0, Figure::BISHOP);
	queen_white = new ChessPiece(0, Figure::QUEEN);
	king_white = new ChessPiece(0, Figure::KING);
	for (int i = 0; i < 8; i++) {
		pawns_white[i] = new ChessPiece(0, Figure::PAWN);
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
}

void ChessBoardWidget::validateClick(int x, int y)
{
    ChessSquare* square = chessSquares[x][y];
    if (square->isPiece() == true && square->getPiece()->getPlayer() == currentPlayer) {
        updateSquares();
        square->setActive(Color::GREEN);
        sx = x;
        sy = y;
        //Walidacja ruchów
        int i;
        switch (square->getPiece()->getFigure()) {
        case Figure::KING:
            checkActive(x + 1, y - 1);
            checkActive(x + 1, y);
            checkActive(x + 1, y + 1);
            checkActive(x, y + 1);
            checkActive(x, y - 1);
            checkActive(x - 1, y + 1);
            checkActive(x - 1, y);
            checkActive(x - 1, y + 1);
            break;
        case Figure::BISHOP:
            i = 1;
            while (checkActive(x + i, y + i)) i++;
            i = 1;
            while (checkActive(x + i, y - i)) i++;
            i = 1;
            while (checkActive(x - i, y + i)) i++;
            i = 1;
            while (checkActive(x - i, y - i)) i++;
            break;
        case Figure::KNIGHT:
            checkActive(x + 2, y + 1);
            checkActive(x + 2, y - 1);
            checkActive(x - 2, y + 1);
            checkActive(x - 2, y - 1);
            checkActive(x + 1, y + 2);
            checkActive(x + 1, y - 2);
            checkActive(x - 1, y + 2);
            checkActive(x - 1, y - 2);
            break;
        case Figure::QUEEN:
            i = 1;
            while (checkActive(x + i, y)) i++;
            i = 1;
            while (checkActive(x + i, y + i)) i++;
            i = 1;
            while (checkActive(x + i, y - i)) i++;
            i = 1;
            while (checkActive(x, y + i)) i++;
            i = 1;
            while (checkActive(x, y - i)) i++;
            i = 1;
            while (checkActive(x - i, y)) i++;
            i = 1;
            while (checkActive(x - i, y + i)) i++;
            i = 1;
            while (checkActive(x - i, y - i)) i++;
            break;
        case Figure::ROOK:
            i = 1;
            while (checkActive(x + i, y) == true) i++;
            i = 1;
            while (checkActive(x - i, y) == true) i++;
            i = 1;
            while (checkActive(x, y - i) == true) i++;
            i = 1;
            while (checkActive(x, y + i) == true) i++;
            break;
        case Figure::PAWN:
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
            break;
        default: break;
        }
    }
    else {
        dx = x;
        dy = y;
        move();
    }
}

ChessBoardWidget::~ChessBoardWidget()
{
    resetChessboard();
    for (int i = 0; i < 8; i++) {
        delete[] chessSquares[i];
    }
    delete[] chessSquares;
}