#include "ChessGameWidget.h"

#include <iostream>
#include <fstream>
#include <Wt/WBreak.h>
#include <Wt/WPushButton.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WMessageBox.h>
#include <Wt/WLogger.h>

#include "Session.h"

using namespace Wt;
using namespace std;

ChessGameWidget::ChessGameWidget(const std::string& name) : WContainerWidget(), name_(name)
{
	setStyleClass("main-box");
	setContentAlignment(AlignmentFlag::Center);
	hbox = std::make_unique<WHBoxLayout>();

	newGameButton = addWidget(cpp14::make_unique<WPushButton>(tr("chess.newGame")));
	newGameButton->clicked().connect(this, &ChessGameWidget::newGame);

	chessBoardWidget = hbox->addWidget(cpp14::make_unique<ChessBoardWidget>());
	panelWidget = hbox->addWidget(cpp14::make_unique<PanelWidget>(chessBoardWidget));

	auto textResource = std::make_shared<ChessResource>();
	Wt::WLink link = Wt::WLink(textResource);
	link.setTarget(Wt::LinkTarget::NewWindow);
	Wt::WAnchor* anchor = hbox->addWidget(cpp14::make_unique<Wt::WAnchor>(link, "Save Game"));

	//connections
	chessBoardWidget->checkMateSignal.connect(this, &ChessGameWidget::gameOver);
	chessBoardWidget->nextMoveSignal.connect(panelWidget, &PanelWidget::updateArrow);
	chessBoardWidget->nextMoveSignal.connect( &ChessResource::setChanged);
	chessBoardWidget->newLostSignal.connect(panelWidget, &PanelWidget::addLostFigure);
}

void ChessGameWidget::newGame()
{
	removeWidget(newGameButton);
	setLayout(std::move(hbox));

	chessBoardWidget->generateChessBoard();
	chessBoardWidget->generateChessPieces();
}

void ChessGameWidget::gameOver(int player)
{
	if (player == 1) {
		StandardButton result = WMessageBox::show("End of the game", "Black Player wins", StandardButton::Ok);
	}
	else {
		StandardButton result = WMessageBox::show("End of the game", "White Player wins", StandardButton::Ok);
	}
	chessBoardWidget->blockAllSquares();
	removeWidget(chessBoardWidget);
	removeWidget(panelWidget);
	removeWidget(this);
}

std::string ChessGameWidget::returnChessMoves()
{
	vector<string>  history = chessBoardWidget->history;
	int counter = 0;
	string text;
	for (int i = 0; i < history.size(); i++) {
		text.append(history[i] + " ");
		counter++;
		if (counter % 2 == 0) {
			text.append("\n");
			counter = 0;
		}
	}
	return text;
}



