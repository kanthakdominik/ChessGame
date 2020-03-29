#ifndef CHESS_BOARD_WIDGET_H_
#define CHESS_BOARD_WIDGET_H_

#include <Wt/WContainerWidget.h>
#include "ChessSquare.h"
#include "ChessPiece.h"

using namespace Wt;

class ChessBoardWidget : public WContainerWidget
{
	friend class PanelWidget;
public:
	ChessBoardWidget();
	void generateChessBoard();
	void generateChessPieces();
	void resetChessboard();             
	void blockAllSquares();
	~ChessBoardWidget();

	//slots
	void validateClick(int x, int y);

private:
	WContainerWidget* chessBoard;
	ChessSquare* chessSquares[8][8];

	void updateSquares();              
	void move();                        
	void setCurrentPlayer(int player);  
	bool checkActive(int x, int y); 
	int currentPlayer;
	int sx;
	int sy;
	int dx;
	int dy;
	std::list<ChessPiece*> lost;        

	//Black pieces 
	ChessPiece* pawns_black[8];
	ChessPiece* rook1_black;
	ChessPiece* rook2_black;
	ChessPiece* knight1_black;
	ChessPiece* knight2_black;
	ChessPiece* bishop1_black;
	ChessPiece* bishop2_black;
	ChessPiece* queen_black;
	ChessPiece* king_black;

	//White pieces
	ChessPiece* pawns_white[8];
	ChessPiece* rook1_white;
	ChessPiece* rook2_white;
	ChessPiece* knight1_white;
	ChessPiece* knight2_white;
	ChessPiece* bishop1_white;
	ChessPiece* bishop2_white;
	ChessPiece* queen_white;
	ChessPiece* king_white;
};

#endif //CHESS_BOARD_WIDGET_H_