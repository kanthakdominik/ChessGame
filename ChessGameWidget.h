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
	void openGame(std::string fileLocation);
	void createNewGame();

	//signal
	Signal<> endGameSignal;

	//slot
	void gameOver(int player);

private:
	WLink link;
	WString name_;
	WAnchor* anchor;
	WFileUpload* openGameUpload;
	std::unique_ptr<WHBoxLayout> hbox;
	std::unique_ptr<WContainerWidget> vbox;
	WPushButton* newGameButton;
	WPushButton* createNewGameButton;
	PanelWidget* panelWidget;
	ChessBoardWidget* chessBoardWidget;
	std::shared_ptr<ChessResource> textResource;
};

#endif //START_WIDGET_H_
