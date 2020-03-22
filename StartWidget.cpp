#include "StartWidget.h"

#include <Wt/WBreak.h>
#include <Wt/WComboBox.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WAny.h>

#include "Session.h"

using namespace Wt;

StartWidget::StartWidget(const std::string& name) : WContainerWidget(),name_(name)
{
    setContentAlignment(AlignmentFlag::Center);

    title_ = addWidget(cpp14::make_unique<WText>(tr("chess.readyToPlay")));
    statusText_ = addWidget(cpp14::make_unique<WText>()); 
    addWidget(cpp14::make_unique<WBreak>());

    newGameButton_ = addWidget(cpp14::make_unique<WPushButton>(tr("chess.newGame")));
    newGameButton_->clicked().connect(this, &StartWidget::newGame);
}

void StartWidget::newGame()
{
    statusText_->setText("Witamy w grze szachy");

}


