#ifndef START_WIDGET_H_
#define START_WIDGET_H_

#include <vector>
#include <Wt/WImage.h>
#include <Wt/WContainerWidget.h>

#include "PanelWidget.h"
#include "ChessBoardWidget.h"

using namespace Wt;

class Session;
class PanelWidget;
class ChessBoardWidget;

class StartWidget : public Wt::WContainerWidget
{
public:
	StartWidget(const std::string& name);

private:
	WPushButton* newGameButton_;
	WImage* background_;
	WHBoxLayout* hbox_;
	std::unique_ptr<PanelWidget> panelWidget_;
	std::unique_ptr<ChessBoardWidget> chessBoardWidget_;
	std::string name_;

	void newGame();
};

#endif //START_WIDGET_H_
