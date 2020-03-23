#include "PanelWidget.h"

#include <Wt/WBreak.h>
#include <Wt/WText.h>

PanelWidget::PanelWidget() 
{
    setStyleClass("panel-box");
    setContentAlignment(AlignmentFlag::Center);
    playerBlack_ = addWidget(cpp14::make_unique<Wt::WImage>(Wt::WLink("resources/Images/profile_black.png")));
    playerBlack_->setAlternateText("Player Black");
    playerBlackTitle_ = addWidget(cpp14::make_unique<WText>(tr("chess.blackPlayer")));
    addWidget(cpp14::make_unique<WBreak>());
    addWidget(cpp14::make_unique<WBreak>());
    addWidget(cpp14::make_unique<WBreak>());
    playerWhite_ = addWidget(cpp14::make_unique<Wt::WImage>(Wt::WLink("resources/Images/profile_white.png")));
    playerWhite_->setAlternateText("Player White");
    playerWhiteTitle_ = addWidget(cpp14::make_unique<WText>(tr("chess.whitePlayer")));
}
