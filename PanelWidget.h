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

using namespace Wt;

class PanelWidget : public WContainerWidget
{
public:
	PanelWidget();
	
	void setArrow(int player);
	//void updateLostFigure(int player, Figure figure);

private:
	WImage* player1Arrow;
	WImage* player2Arrow;
	
};

#endif //PANEL_WIDGET_H_
