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
	void setChessMoves();
	void loadGame(const std::vector< Http::UploadedFile >& file);

	//signal
	Signal<> endGameSignal;

	//slot
	void gameOver(int player);

private:
	WLink link;
	WString name_;
	std::unique_ptr<WHBoxLayout> hbox;
	WPushButton* newGameButton;
	PanelWidget* panelWidget;
    ChessBoardWidget* chessBoardWidget;
	std::shared_ptr<ChessResource> textResource;
};

#endif //START_WIDGET_H_
