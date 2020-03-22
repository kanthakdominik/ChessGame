#ifndef START_WIDGET_H_
#define START_WIDGET_H_

#include <vector>

#include <Wt/WContainerWidget.h>

class Session;

class StartWidget : public Wt::WContainerWidget
{
public:
	StartWidget(const std::string& name);

private:
	Wt::WText* title_;
	Wt::WText* statusText_;
	Wt::WPushButton* newGameButton_;
	std::string name_;

	void newGame();
};

#endif //START_WIDGET_H_
