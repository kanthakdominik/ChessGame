#ifndef KING_
#define KING_

#include "ChessPiece.h"
#include <vector>

class ChessSquare;

/**
 * Klasa dziedzicz¹ca po ChessPiece odpowiadaj¹ca za figurê Król
 */
class King : public ChessPiece
{
public:
	/**
	* Konstruktor klasy przekazuj¹cy numer gracza do klasy nadrzêdnej
	* playerNumber - numer gracza
	*/
	King(int playerNumber);

	/**
	* Metoda zwracaj¹ca figurê
	 */
	ChessPiece* getFigure();

	/**
	* Metoda zwracaj¹ca odnoœnik do ikony figury
	 */
	WLink getIconLink();

	/**
	* Metoda sprawdzaj¹ca mo¿liwoœæ dostepnych ruchów figury
	* int x, int y - wspó³rzêdne pozycji
	* int currentPlayer - aktywny gracz
	* ChessSquare* clickedSquare - referencja do wybranego pola szachowego
	* ChessSquare* chessSquares[8][8] - referencja do szachownicy
	 */
	void checkMove(int x, int y, int currentPlayer, ChessSquare* clickedSquare, ChessSquare* chessSquares[8][8]);

private:
};

#endif // KING_

