#ifndef PANEL_WIDGET_H_
#define PANEL_WIDGET_H_

#include <Wt/WContainerWidget.h>
#include <Wt/WImage.h>

using namespace Wt;

class PanelWidget : public WContainerWidget
{
public:
	PanelWidget();

private:
	WImage* playerBlack_;
	WImage* playerWhite_;
	WText* playerBlackTitle_;
	WText* playerWhiteTitle_;
};

#endif //PANEL_WIDGET_H_
