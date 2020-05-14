#ifndef QUEEN_
#define QUEEN_

#include "ChessPiece.h"
#include <vector>

class ChessSquare;

/**
 * Klasa dziedzicz�ca po ChessPiece odpowiadaj�ca za figur� Hetman
 */
class Queen : public ChessPiece
{
public:
	/**
	* Konstruktor klasy przekazuj�cy numer gracza do klasy nadrz�dnej
	* playerNumber - numer gracza
	*/
	Queen(int playerNumber);

	/**
	* Metoda zwracaj�ca figur�
	 */
	ChessPiece* getFigure();

	/**
	* Metoda zwracaj�ca odno�nik do ikony figury
	 */
	WLink getIconLink();

	/**
	* Metoda sprawdzaj�ca mo�liwo�� dostepnych ruch�w figury
	* int x, int y - wsp�rz�dne pozycji
	* int currentPlayer - aktywny gracz
	* ChessSquare* clickedSquare - referencja do wybranego pola szachowego
	* ChessSquare* chessSquares[8][8] - referencja do szachownicy
	 */
	void checkMove(int x, int y, int currentPlayer, ChessSquare* clickedSquare, ChessSquare* chessSquares[8][8]);

private:
};

#endif // QUEEN_