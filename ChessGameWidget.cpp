#include "ChessGameWidget.h"

#include <Wt/WBreak.h>
#include <Wt/WPushButton.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WMessageBox.h>
#include <Wt/WLogger.h>

#include "Session.h"

using namespace Wt;

ChessGameWidget::ChessGameWidget(const std::string& name) : WContainerWidget(), name_(name)
{
	setStyleClass("main-box");
	setContentAlignment(AlignmentFlag::Center);
	hbox = std::make_unique<WHBoxLayout>();

	newGameButton = addWidget(cpp14::make_unique<WPushButton>(tr("chess.newGame")));
	newGameButton->clicked().connect(this, &ChessGameWidget::newGame);

	panelWidget = hbox->addWidget(cpp14::make_unique<PanelWidget>(chessBoardWidget));
	chessBoardWidget = hbox->addWidget(cpp14::make_unique<ChessBoardWidget>());

	//connections
	chessBoardWidget->checkMateSignal.connect(this, &ChessGameWidget::gameOver);
	//chessBoardWidget->nextMoveSignal.connect(this, &PanelWidget::updateArrow);
	//chessBoardWidget->newLostSignal.connect(this, &PanelWidget::addLostFigure);
}

void ChessGameWidget::newGame()
{
	newGameButton->hide();
	setLayout(std::move(hbox));

	chessBoardWidget->generateChessBoard();
	chessBoardWidget->generateChessPieces();
}

void ChessGameWidget::gameOver(int player)
{
	if (player == 1) {
		StandardButton result = WMessageBox::show("Koniec gry", "Wygra³ gracz czarny", StandardButton::Ok);
	}
	else {
		StandardButton result = WMessageBox::show("Koniec gry", "Wygra³ gracz bia³y", StandardButton::Ok);
	}
	chessBoardWidget->blockAllSquares();
}


