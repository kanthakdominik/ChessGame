#ifndef CHESSSQUARE_H
#define CHESSSQUARE_H

#include <Wt/WLogger.h>
#include <Wt/WPushButton.h>
#include <Wt/WString.h>

#include "ChessPiece.h"

/**
 * Klasa typu wyliczeniowego odpowiadaj¹ca za kolor pola szachowego
 */
enum class Color
{
	WHITE,
	GRAY,
	RED,
	GREEN
};

/**
 * Klasa dziedzicz¹ca po WPushButton, odpowiadaj¹ca za puste pole szachowe
 */
class ChessSquare : public WPushButton
{
public:
	ChessSquare(int row, int column);

	/**
	* Metoda ustawiaj¹ca pole szachowe jak aktywne lub nieaktywne
	* bool active - wartoœæ logiczna
	*/
	void setActive(bool active);       

	/**
	* Metoda ustawiaj¹ca pole szachowe jak aktywne oraz zmienia jego kolor
	* Color color - nowy kolor pola szachowego
	*/
	void setActive(Color color);

	/**
	* Metoda zwraca informacjê, czy na polu jest ustawiona figura
	*/
	bool isPiece();       

	/**
	* Metoda zwraca informacjê, czy pole jest aktywne
	*/
	bool isActive();       

	/**
	* Metoda zwraca referencjê do figury ustawionej na polu
	*/
	ChessPiece* getPiece();     

	/**
	* Metoda ustawia figurê na polu szachowym
	* ChessPiece* chessPiece - referencja do figury
	*/
	void setPiece(ChessPiece* chessPiece);  

	/**
	* Metoda usuwaj¹ca figurê z pola szachowego
	*/
	void removePiece();        

	/**
	* Metoda ustawiaj¹ca kolor pola szachowego
	* Color color - kolor na który ma przyj¹c pole 
	*/
	void setBackgroundColor(Color color);        

	/**
	* Metoda bêd¹ca slotem wywo³ywanym przez sygna³ clicked(), emituj¹ca sygna³ clickedChessSquareSignal 
	* tylko w przypadku gdy pole szachowe jest aktywne
	*/
	void clickEvent();

	/**
	* Metoda zwracaj¹ca koordynaty pola szachowego
	*/
	std::string toChessNotation();

	/**
	* Metoda analizuj¹ca figury na planszy oraz odpowiednio koloruj¹ca pola szachowe 
	* (dla wszystkich figur poza Pionem)
	* int x, int y - koordynaty pola szachowego
	* int currentPlayer - aktywny gracz
	* ChessSquare* chessSquares[8][8] - referencja do planszy
	*/
	bool setMove(int x, int y, int currentPlayer, ChessSquare* chessSquares[8][8]);

	/**
	* Metoda analizuj¹ca figury na planszy oraz odpowiednio koloruj¹ca pola szachowe 
	* (dla figury Pion, poniewa¿ ma on inne zasady dla ruchu i inne zasady dla ataku)
	* int x, int y - koordynaty pola szachowego
	* int currentPlayer - aktywny gracz
	* ChessSquare* chessSquares[8][8] - referencja do planszy
	*/
	void setMovePawn(int x, int y, int currentPlayer, ChessSquare* chessSquares[8][8]);
	 
	/**
	 * Sygna³ wywo³ujacy metodê ChessBoardWidget::validateClick, która obs³uguje wciœniêcie aktywengo pola szachowego
	*/
	Signal<int, int> clickedChessSquareSignal;

private:
	/**
	* Metoda ustawiaj¹ca bazowy kolor pola szachowego (czarny lub bia³y)
	* int color - liczb¹ odpowiadaj¹ca graczom (1 - czarny, 0 -bia³y)
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