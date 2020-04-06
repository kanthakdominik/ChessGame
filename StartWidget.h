
#ifndef CHESSGAME_H_
#define CHESSGAME_H_

#include <Wt/WContainerWidget.h>

#include "Session.h"

using namespace Wt;

class Wt::WStackedWidget;
class Wt::WAnchor;
class ChessGameWidget;
class HighScoresWidget;
class Session;

class StartWidget : public WContainerWidget
{
public:
	StartWidget();
	void handleInternalPath(const std::string& internalPath);

private:
	WStackedWidget* mainStack_;
	ChessGameWidget* game_;
	HighScoresWidget* scores_;
	WContainerWidget* links_;
	WAnchor* backToGameAnchor_;
	WAnchor* scoresAnchor_;
	Session session_;

	void onAuthEvent();
	void showGame();
	void showHighScores();
};
#endif //CHESSGAME_H_
