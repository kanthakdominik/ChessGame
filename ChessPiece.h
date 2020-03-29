#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <Wt/WString.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>
#include <Wt/WLogger.h>

using namespace Wt;

enum class Figure
{
    KING,
    BISHOP,
    KNIGHT,
    QUEEN,
	ROOK,
	PAWN
};

class ChessPiece
{
public:
    ChessPiece(int playerNumber, Figure figure);
    Figure getFigure();
    WLink getIconLink();
    int getPlayer();        
    int getMoveNumber();    
    void nextMove();        
    ~ChessPiece();

private:
    Figure figure;
    WLink iconLink;
    int moveNumber;
    int playerNumber;
};

#endif // CHESSPIECE_H
