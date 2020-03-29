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
	void setColor(Color color);           
	WString toChessNotation();          
	~ChessSquare();  

private:
	bool active;
	Color color;
	int column;
	int row;
	ChessPiece* chessPiece;
};
#endif // CHESSSQUARE_H
