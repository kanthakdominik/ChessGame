
#ifndef CHESS_WIDGET_H_
#define CHESS_WIDGET_H_

#include <vector>

#include <Wt/WContainerWidget.h>

class Session;

class ChessWidget : public Wt::WContainerWidget
{
public:
    ChessWidget(const std::string& name);

    Wt::Signal<int>& scoreUpdated() { return scoreUpdated_; }

private:
    Wt::WText* title_;

    Wt::WText* statusText_;
    Wt::WComboBox* language_;
    Wt::WPushButton* newGameButton_;

    Wt::Signal<int>            scoreUpdated_;

    std::string                name_;

    int                        badGuesses_;

    void newGame();
};

#endif //CHESS_WIDGET_H_
