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
 * Klasa dziedzicz�ca po WContainerWidget, odpowiadaj�ca za panel boczny wy�wietlaj�cy informacje dotycz�ce gry:
 * zbite figury oraz kt�ry gracz ma mo�liwo�� ruchu
 */
class PanelWidget : public WContainerWidget
{
public:
	/**
	* Konstruktor ustawiaj�cy zawarte w panelu widgety
	* ChessBoardWidget* chessBoard - referencja do szachownicy
	*/
	PanelWidget(ChessBoardWidget* chessBoard);

	/**
	* Metoda odpowiedzialna za usuni�cie ikon zbitych figur
    */
	void cleartLostFigures();

	/**
	* Metoda zwracaj�ca WLink, kt�ry jest odno�nikiem do pustej ikony figury
	*/
	WLink getBlancIconLink();

	/**
	* Metoda b�d�ca slotem wywo�ywanym przez sygna� nextMoveSignal odpowiedzialna za 
	* aktualizacj� strza�ki wskazuj�cej ruch aktualnego gracza
	*/
	void updateArrow();

	/**
	* Metoda b�d�ca slotem wywo�ywanym przez sygna� nextMoveSignal odpowiedzialna za
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
