#ifndef MAIN_WIDGET_
#define MAIN_WIDGET_

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>

#include "Game.h"
#include "Session.h"

using namespace Wt;

class Session;

class MainWidget : public WContainerWidget
{
public:
	MainWidget(Game* game);
	
private:
	Game* game; 
	Session session;

	void onAuthEvent();
	void handleInternalPath(const std::string& internalPath);
};
#endif //MAIN_WIDGET_
	

	