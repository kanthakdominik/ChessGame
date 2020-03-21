
#ifndef HIGH_SCORES_WIDGET_H_
#define HIGH_SCORES_WIDGET_H_

#include <Wt/WContainerWidget.h>

using namespace Wt;

class Session;

class HighScoresWidget : public WContainerWidget
{
public:
    HighScoresWidget(Session* session);
    void update();

private:
    Session* session_;
};

#endif //HIGH_SCORES_WIDGET_H_
