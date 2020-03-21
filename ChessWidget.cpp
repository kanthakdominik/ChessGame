
#include "ChessWidget.h"

#include <Wt/WBreak.h>
#include <Wt/WComboBox.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WAny.h>

#include "Session.h"


using namespace Wt;

namespace {
    const int MaxGuesses = 9;
}

ChessWidget::ChessWidget(const std::string& name)
    : WContainerWidget(),
    name_(name),
    badGuesses_(0)
{
    setContentAlignment(AlignmentFlag::Center);

    title_ = addWidget(cpp14::make_unique<WText>(tr("chess.readyToPlay")));

    statusText_ = addWidget(cpp14::make_unique<WText>()); 

    addWidget(cpp14::make_unique<WBreak>());

    newGameButton_ = addWidget(cpp14::make_unique<WPushButton>(tr("chess.newGame")));
    newGameButton_->clicked().connect(this, &ChessWidget::newGame);

}

void ChessWidget::newGame()
{
    WString title(tr("chess.guessTheWord"));
    title_->setText(title.arg(name_));

    newGameButton_->hide();
    
    badGuesses_ = 0;
    
    statusText_->setText("");
}


