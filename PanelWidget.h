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
	//void clearLost();
	//~PanelWidget();

	//void updateLost();          //!< Aktualizuje listê ze straconymi pionkami
	//void updateCurrentPlayer(); //!< Zmienia aktualny numer gracza

private:
	ChessBoardWidget* chessBoardWidget;
	
};

#endif //PANEL_WIDGET_H_
