#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <Wt/WLogger.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>

#include "ChessPiece.h"

enum class Color
{
	WHITE,
	GRAY,
	RED,
	GREEN
};

class ChessSquare : public WPushButton
{
public:
	ChessSquare(int row, int column);
	void setActive(bool active);        
	void setActive(Color color);
	bool isPiece();                     
	bool isActive();                    
	ChessPiece* getPiece();             
	void setPiece(ChessPiece* chessPiece);   
	void removePiece();             
	void setBackgroundColor(Color color);        
	void clickEvent();
	std::string toChessNotation();
	~ChessSquare();  

	//signal
	Signal<int, int> clickedChessSquareSignal;

private:
	void setColor(int color);
	bool active;
	int color;
	int column;
	int row;
	Color backgroundColor;
	ChessPiece* chessPiece;
};
#endif // CHESSSQUARE_H