#ifndef CHESS_BOARD_WIDGET_H_
#define CHESS_BOARD_WIDGET_H_

#include <Wt/WContainerWidget.h>
#include <Wt/WSignal.h>
#include "ChessSquare.h"
#include "ChessPiece.h"
#include "ChessResource.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "Rook.h"

using namespace Wt;

/**
 * Szablon funkcji sprawdzaj¹cy czy przekazany obiekt jest instancj¹ danej klasy
 * Base - klasa
 * Object - sprawdzany obiekt
 */
template<typename Base, typename Object>
inline bool instanceof(const Object* ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}

/**
 * Klasa dziedzicz¹ca po WContainerWidget, odpowiadaj¹ca za wyœwietlanie oraz obs³ugê szachownicy
 */
class ChessBoardWidget : public WContainerWidget
{
	friend class PanelWidget;
	friend class ChessResources;
public:
	std::vector<std::string> history;

	/**
	 * Konstruktor klasy ustawiaj¹cy gracza czarnego jako aktualnego gracza
	*/
	ChessBoardWidget();

	/**
	 * Metoda odpowiedzialna za wygenerowanie szachownicy
	*/
	void generateChessBoard();

	/**
	 * Metoda odpowiedzialna za wygenerowanie figur szachowych
	*/
	void generateChessPieces();

	/**
	 * Metoda odpowiedzialna za reset szachownicy
	*/
	void resetChessboard();

	/**
	 * Metoda odpowiedzialna za zablokowanie wszystkich pól szachowych
	*/
	void blockAllSquares();

	/**
	 * Metoda odpowiedzialna za odpowiednie pokolorowanie pól szachowych
	*/
	void setDefaultColors();

	/**
	 * Metoda odpowiedzialna za odczyt koordynatów szachowych z podanej linii tekstu oraz wykonujaca zapisany ruch
	 * line - linia tesktu bed¹ca jednym ruchem na szachownicy
	*/
	void readFromText(std::string line);

	/**
	 * Metoda bêd¹ca slotem, obs³uguj¹cym sygna³ clickedChessSquareSignal wywo³ywanym poprzez klikniêcie aktywnego pola szachowego
	 * int x, int y - wspó³rzêdne pozycji
	*/
	void validateClick(int x, int y);

	/**
	 * Sygna³ wywo³ujacy metody ChessGameWidget::setChessMoves oraz PanelWidget::updateArrow aktywowany po wykonaniu ruchu przez gracza
	*/
	Signal<> nextMoveSignal;

	/**
	 * Sygna³ wywo³ujacy metodê ChessGameWidget::gameOver aktywowany po zbiciu figury Króla
	 * int - przekazywany parametr mówi¹cy który gracz wygra³
	*/
	Signal<int> checkMateSignal;

	/**
	 * Sygna³ wywo³ujacy metodê PanelWidget::addLostFigure aktywowany po zbiciu figury przez gracza
	*/
	Signal<WLink> newLostSignal;

private:
	WContainerWidget* chessBoard;
	ChessSquare* chessSquares[8][8];
	WText* text;

	/**
	 * Metoda odpowiedzialna za odpowiednie blokowanie oraz odblokowanie pól szachowych po ka¿dym ruchu graczy
	*/
	void updateSquares();

	/**
	 * Metoda odpowiedzialna za wykonanie ruchu figur na planszy
	*/
	void move();

	/**
	 * Metoda odpowiedzialna za zamianê graczy
	 * player - gracz który otrzyma mozliwoœæ ruchu
	*/
	void setCurrentPlayer(int player);

	int currentPlayer;
	int sx;
	int sy;
	int dx;
	int dy;
	std::list<ChessPiece*> lostPiecesList;

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
