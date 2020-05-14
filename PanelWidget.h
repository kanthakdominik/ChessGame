#ifndef PANEL_WIDGET_H_
#define PANEL_WIDGET_H_

#include <Wt/WContainerWidget.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WGridLayout.h>
#include <Wt/WImage.h>
#include <Wt/WLabel.h>
#include <Wt/WString.h>

#include "ChessBoardWidget.h"
#include "ChessPiece.h"

using namespace Wt;

/**
 * Klasa dziedzicz¹ca po WContainerWidget, odpowiadaj¹ca za panel boczny wyœwietlaj¹cy informacje dotycz¹ce gry:
 * zbite figury oraz który gracz ma mo¿liwoœæ ruchu
 */
class PanelWidget : public WContainerWidget
{
public:
	/**
	* Konstruktor ustawiaj¹cy zawarte w panelu widgety
	* ChessBoardWidget* chessBoard - referencja do szachownicy
	*/
	PanelWidget(ChessBoardWidget* chessBoard);

	/**
	* Metoda odpowiedzialna za usuniêcie ikon zbitych figur
    */
	void cleartLostFigures();

	/**
	* Metoda zwracaj¹ca WLink, który jest odnoœnikiem do pustej ikony figury
	*/
	WLink getBlancIconLink();

	/**
	* Metoda bêd¹ca slotem wywo³ywanym przez sygna³ nextMoveSignal odpowiedzialna za 
	* aktualizacjê strza³ki wskazuj¹cej ruch aktualnego gracza
	*/
	void updateArrow();

	/**
	* Metoda bêd¹ca slotem wywo³ywanym przez sygna³ nextMoveSignal odpowiedzialna za
	* dodanie ikony zbitej figury do panelu
	* WLink lstFigure - link do ikony zbitej figury
	*/
	void addLostFigure(WLink lostFigure);

private:
	ChessBoardWidget* chessBoard;
	int player1LostPiecesCounter;
	int player2LostPiecesCounter;
	WImage* player1Arrow;
	WImage* player2Arrow;
	WImage* player1LostFigures[16];
	WImage* player2LostFigures[16];
	std::unique_ptr<WContainerWidget> player1LostFiguresImage;
	std::unique_ptr<WContainerWidget> player2LostFiguresImage;
};

#endif //PANEL_WIDGET_H_
