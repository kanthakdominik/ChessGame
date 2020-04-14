#ifndef START_WIDGET_H_
#define START_WIDGET_H_

#include <vector>
#include <Wt/WImage.h>
#include <Wt/WContainerWidget.h>

#include "PanelWidget.h"
#include "ChessBoardWidget.h"
#include "ChessResource.h"

using namespace Wt;

class Session;
class PanelWidget;
class ChessBoardWidget;

class ChessGameWidget : public WContainerWidget
{
public:
	ChessGameWidget(const std::string& name);
    void newGame();
	std::string returnChessMoves();

	//slot
	void gameOver(int player);

private:
	WLink link;
	WString name_;
	std::unique_ptr<WHBoxLayout> hbox;
	WPushButton* newGameButton;
	PanelWidget* panelWidget;
    ChessBoardWidget* chessBoardWidget;
};

#endif //START_WIDGET_H_
