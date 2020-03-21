
#ifndef CHESSGAME_H_
#define CHESSGAME_H_

#include <Wt/WContainerWidget.h>

#include "Session.h"

using namespace Wt;

namespace Wt {
    class WStackedWidget;
    class WAnchor;
}

class ChessWidget;
class HighScoresWidget;
class Session;

class ChessGame : public WContainerWidget
{
public:
    ChessGame();

    void handleInternalPath(const std::string& internalPath);

private:
    WStackedWidget* mainStack_;
    ChessWidget* game_;
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
