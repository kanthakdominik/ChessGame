#include "ChessGameWidget.h"

#include <iostream>
#include <fstream>
#include <Wt/WBreak.h>
#include <Wt/WPushButton.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WMessageBox.h>
#include <Wt/WProgressBar.h>
#include <Wt/WFileUpload.h>
#include <Wt/WLogger.h>

#include "Session.h"

using namespace Wt;
using namespace std;

ChessGameWidget::ChessGameWidget(const std::string& name) : WContainerWidget(), name_(name)
{
	setStyleClass("main-box");
	setContentAlignment(AlignmentFlag::Center);
	hbox = std::make_unique<WHBoxLayout>();

	auto vbox = std::make_unique<WContainerWidget>();
	vbox->setStyleClass("vbox");


	newGameButton = addWidget(cpp14::make_unique<WPushButton>(tr("chess.newGame")));
	newGameButton->clicked().connect(this, &ChessGameWidget::newGame);

	chessBoardWidget = hbox->addWidget(cpp14::make_unique<ChessBoardWidget>());
	panelWidget = hbox->addWidget(cpp14::make_unique<PanelWidget>(chessBoardWidget));

	//game save
	chessBoardWidget->nextMoveSignal.connect(this, &ChessGameWidget::setChessMoves);
	textResource = std::make_shared<ChessResource>();
	WLink link = WLink(textResource);
	link.setTarget(Wt::LinkTarget::NewWindow);
	WAnchor* anchor = vbox->addWidget(cpp14::make_unique<WAnchor>(link, "Save Game"));

	//game load
	Wt::WFileUpload* fu = vbox->addWidget(cpp14::make_unique<WFileUpload>());
	fu->setFileTextSize(50);
	fu->changed().connect([=] {fu->upload(); });
	fu->uploaded().connect([=] { loadGame(fu->uploadedFiles()); });

	//connections
	chessBoardWidget->checkMateSignal.connect(this, &ChessGameWidget::gameOver);
	chessBoardWidget->nextMoveSignal.connect(panelWidget, &PanelWidget::updateArrow);
	chessBoardWidget->newLostSignal.connect(panelWidget, &PanelWidget::addLostFigure);

	hbox->addWidget(std::move(vbox));
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
	endGameSignal.emit();
}

void ChessGameWidget::setChessMoves()
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
	textResource->setText(text);
}

void ChessGameWidget::loadGame(const std::vector< Http::UploadedFile >& file) {

	/*chessBoardWidget->resetChessboard();
	chessBoardWidget->generateChessPieces();
	panelWidget->cleartLostFigures();
	panelWidget->updateArrow();
	QTextStream in(&file);
	try {
		while (!in.atEnd()) {
			QString line = in.readLine();
			chessboard->readFromText(line);
		}
	}
	catch (QString error) {
		QMessageBox::critical(this, "B³¹d!", error);
		chessboard->resetChessboard();
		chessboard->generateChessPieces();
		panel->clearLost();
		panel->updateCurrentPlayer();
	}*/
}




