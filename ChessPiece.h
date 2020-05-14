#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <Wt/WString.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>
#include <Wt/WLogger.h>


using namespace Wt;

class ChessSquare;

/**
 * Klasa odpowiadaj¹ca za abstrakcyjn¹ figurê szachow¹, dziedzicz¹ po niej figury
 */
class ChessPiece
{
public:
	/**
	* Konstruktor klasy ustawiaj¹cy numer gracza
	* playerNumber - numer gracza
	 */
	ChessPiece(int playerNumber);

	/**
	* Metoda wirtualna zwracaj¹ca figurê
	 */
	virtual ChessPiece* getFigure();

	/**
	* Metoda wirtualna zwracaj¹ca odnoœnik do ikony figury
	 */
	virtual WLink getIconLink();

	/**
	* Metoda wirtualna sprawdzaj¹ca mo¿liwoœæ dostepnych ruchów figury
	* int x, int y - wspó³rzêdne pozycji
	* int currentPlayer - aktywny gracz
	* ChessSquare* clickedSquare - referencja do wybranego pola szachowego
	* ChessSquare* chessSquares[8][8] - referencja do szachownicy
	 */
	virtual void checkMove(int x, int y, int currentPlayer, ChessSquare* clickedSquare, ChessSquare* chessSquares[8][8]);
	
	/**
	* Metoda zwracaj¹ca numer aktualnego gracza
	 */
	int getPlayer();

	/**
	* Metoda zwracaj¹ca liczbê wykonanych ruchów figury
	 */
	int getMoveNumber();

	/**
	* Metoda zwiêkszaj¹ca liczbê ruchów figury
	 */
	void increaseMoveNumber();

protected:
	WLink iconLink;
	int playerNumber;

private:
	int moveNumber;

};

#endif // CHESSPIECE_H