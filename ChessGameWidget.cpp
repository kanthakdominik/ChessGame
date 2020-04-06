#include "ChessGameWidget.h"

#include <Wt/WBreak.h>
#include <Wt/WPushButton.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WLogger.h>

#include "Session.h"

using namespace Wt;

ChessGameWidget::ChessGameWidget(const std::string& name) : WContainerWidget(), name_(name)
{
	//setStyleClass("main-box");
	setContentAlignment(AlignmentFlag::Center);
	hbox = std::make_unique<WHBoxLayout>();

	newGameButton = addWidget(cpp14::make_unique<WPushButton>(tr("chess.newGame")));
	newGameButton->clicked().connect(this, &ChessGameWidget::newGame);

	panelWidget = hbox->addWidget(cpp14::make_unique<PanelWidget>());
	chessBoardWidget = hbox->addWidget(cpp14::make_unique<ChessBoardWidget>());
}

void ChessGameWidget::newGame()
{
	newGameButton->hide();

	chessBoardWidget->generateChessBoard();
	chessBoardWidget->generateChessPieces();

	setLayout(std::move(hbox));
}

