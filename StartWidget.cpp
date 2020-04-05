#include "StartWidget.h"

#include <Wt/WBreak.h>
#include <Wt/WPushButton.h>
#include <Wt/WHBoxLayout.h>

#include "Session.h"

using namespace Wt;

StartWidget::StartWidget(const std::string& name) : WContainerWidget(), name_(name)
{
	setContentAlignment(AlignmentFlag::Center);
	background_ = addWidget(cpp14::make_unique<Wt::WImage>(Wt::WLink("resources/Images/background.jpg")));
	addWidget(cpp14::make_unique<WBreak>());
	newGameButton_ = addWidget(cpp14::make_unique<WPushButton>(tr("chess.newGame")));
	newGameButton_->clicked().connect(this, &StartWidget::newGame);
	addWidget(cpp14::make_unique<WBreak>());
}

void StartWidget::newGame()
{
	background_->hide();
	newGameButton_->hide();

	setStyleClass("main-box");
	hbox_ = setLayout(Wt::cpp14::make_unique<Wt::WHBoxLayout>());

	chessBoardWidget_ = Wt::cpp14::make_unique<ChessBoardWidget>();
	panelWidget_ = Wt::cpp14::make_unique<PanelWidget>();

	hbox_->addWidget(std::move(panelWidget_));
	hbox_->addWidget(std::move(chessBoardWidget_));
}


