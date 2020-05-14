#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <Wt/WLogger.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>

#include "ChessPiece.h"

/**
 * Klasa typu wyliczeniowego odpowiadaj�ca za kolor pola szachowego
 */
enum class Color
{
	WHITE,
	GRAY,
	RED,
	GREEN
};

/**
 * Klasa dziedzicz�ca po WPushButton, odpowiadaj�ca za puste pole szachowe
 */
class ChessSquare : public WPushButton
{
public:
	ChessSquare(int row, int column);

	/**
	* Metoda ustawiaj�ca pole szachowe jak aktywne lub nieaktywne
	* bool active - warto�� logiczna
	*/
	void setActive(bool active);       

	/**
	* Metoda ustawiaj�ca pole szachowe jak aktywne oraz zmienia jego kolor
	* Color color - nowy kolor pola szachowego
	*/
	void setActive(Color color);

	/**
	* Metoda zwraca informacj�, czy na polu jest ustawiona figura
	*/
	bool isPiece();       

	/**
	* Metoda zwraca informacj�, czy pole jest aktywne
	*/
	bool isActive();       

	/**
	* Metoda zwraca referencj� do figury ustawionej na polu
	*/
	ChessPiece* getPiece();     

	/**
	* Metoda ustawia figur� na polu szachowym
	* ChessPiece* chessPiece - referencja do figury
	*/
	void setPiece(ChessPiece* chessPiece);  

	/**
	* Metoda usuwaj�ca figur� z pola szachowego
	*/
	void removePiece();        

	/**
	* Metoda ustawiaj�ca kolor pola szachowego
	* Color color - kolor na kt�ry ma przyj�c pole 
	*/
	void setBackgroundColor(Color color);        

	/**
	* Metoda b�d�ca slotem wywo�ywanym przez sygna� clicked(), emituj�ca sygna� clickedChessSquareSignal 
	* tylko w przypadku gdy pole szachowe jest aktywne
	*/
	void clickEvent();

	/**
	* Metoda zwracaj�ca koordynaty pola szachowego
	*/
	std::string toChessNotation();

	/**
	* Metoda analizuj�ca figury na planszy oraz odpowiednio koloruj�ca pola szachowe 
	* (dla wszystkich figur poza Pionem)
	* int x, int y - koordynaty pola szachowego
	* int currentPlayer - aktywny gracz
	* ChessSquare* chessSquares[8][8] - referencja do planszy
	*/
	bool setMove(int x, int y, int currentPlayer, ChessSquare* chessSquares[8][8]);

	/**
	* Metoda analizuj�ca figury na planszy oraz odpowiednio koloruj�ca pola szachowe 
	* (dla figury Pion, poniewa� ma on inne zasady dla ruchu i inne zasady dla ataku)
	* int x, int y - koordynaty pola szachowego
	* int currentPlayer - aktywny gracz
	* ChessSquare* chessSquares[8][8] - referencja do planszy
	*/
	void setMovePawn(int x, int y, int currentPlayer, ChessSquare* chessSquares[8][8]);
	 
	/**
	 * Sygna� wywo�ujacy metod� ChessBoardWidget::validateClick, kt�ra obs�uguje wci�ni�cie aktywengo pola szachowego
	*/
	Signal<int, int> clickedChessSquareSignal;

private:
	/**
	* Metoda ustawiaj�ca bazowy kolor pola szachowego (czarny lub bia�y)
	* int color - liczb� odpowiadaj�ca graczom (1 - czarny, 0 -bia�y)
	*/
	void setBaseColor(int color);

	bool active;
	int color;
	int column;
	int row;
	Color backgroundColor;
	ChessPiece* chessPiece;
};
#endif // CHESSSQUARE_H