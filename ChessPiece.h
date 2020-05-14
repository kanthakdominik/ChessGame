#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <Wt/WString.h>
#include <Wt/WImage.h>
#include <Wt/WLink.h>
#include <Wt/WLogger.h>


using namespace Wt;

class ChessSquare;

/**
 * Klasa odpowiadaj�ca za abstrakcyjn� figur� szachow�, dziedzicz� po niej figury
 */
class ChessPiece
{
public:
	/**
	* Konstruktor klasy ustawiaj�cy numer gracza
	* playerNumber - numer gracza
	 */
	ChessPiece(int playerNumber);

	/**
	* Metoda wirtualna zwracaj�ca figur�
	 */
	virtual ChessPiece* getFigure();

	/**
	* Metoda wirtualna zwracaj�ca odno�nik do ikony figury
	 */
	virtual WLink getIconLink();

	/**
	* Metoda wirtualna sprawdzaj�ca mo�liwo�� dostepnych ruch�w figury
	* int x, int y - wsp�rz�dne pozycji
	* int currentPlayer - aktywny gracz
	* ChessSquare* clickedSquare - referencja do wybranego pola szachowego
	* ChessSquare* chessSquares[8][8] - referencja do szachownicy
	 */
	virtual void checkMove(int x, int y, int currentPlayer, ChessSquare* clickedSquare, ChessSquare* chessSquares[8][8]);
	
	/**
	* Metoda zwracaj�ca numer aktualnego gracza
	 */
	int getPlayer();

	/**
	* Metoda zwracaj�ca liczb� wykonanych ruch�w figury
	 */
	int getMoveNumber();

	/**
	* Metoda zwi�kszaj�ca liczb� ruch�w figury
	 */
	void increaseMoveNumber();

protected:
	WLink iconLink;
	int playerNumber;

private:
	int moveNumber;

};

#endif // CHESSPIECE_H