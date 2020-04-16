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

class PanelWidget : public WContainerWidget
{
public:
	PanelWidget(ChessBoardWidget* chessBoard);

	void cleartLostFigures();
	WLink getBlancIconLink();

	//slots         
	void updateArrow();
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
