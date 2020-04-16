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
	vbox = std::make_unique<WContainerWidget>();
	vbox->setStyleClass("vbox");

	newGameButton = addWidget(cpp14::make_unique<WPushButton>("Start New Game"));
	chessBoardWidget = hbox->addWidget(cpp14::make_unique<ChessBoardWidget>());
	panelWidget = hbox->addWidget(cpp14::make_unique<PanelWidget>(chessBoardWidget));

	//createNewGame button
	createNewGameButton = vbox->addWidget(cpp14::make_unique<WPushButton>("New Game"));
	createNewGameButton->clicked().connect(this, &ChessGameWidget::createNewGame);
	createNewGameButton->setStyleClass("createNewGameButton");

	//game save
	textResource = std::make_shared<ChessResource>();
	WLink link = WLink(textResource);
	link.setTarget(Wt::LinkTarget::NewWindow);
	anchor = vbox->addWidget(cpp14::make_unique<WAnchor>(link, "Save Game"));
	anchor->setStyleClass("saveAnchor");

	//game open;
	auto OpenGameText = vbox->addWidget(cpp14::make_unique<WText>("Open Game"));
	OpenGameText->setStyleClass("openGameText");
	openGameUpload = vbox->addWidget(cpp14::make_unique<WFileUpload>());
	openGameUpload->setFileTextSize(50);
	openGameUpload->changed().connect([=] {openGameUpload->upload(); });
	openGameUpload->uploaded().connect([=] {
		auto file = openGameUpload->uploadedFiles().at(0);
		string fileLocation = file.spoolFileName();
		openGame(fileLocation);
		log("OPEN") << fileLocation; });
	openGameUpload->setStyleClass("openGameUpload");
	
	//connections
	chessBoardWidget->checkMateSignal.connect(this, &ChessGameWidget::gameOver);
	chessBoardWidget->nextMoveSignal.connect(panelWidget, &PanelWidget::updateArrow);
	chessBoardWidget->newLostSignal.connect(panelWidget, &PanelWidget::addLostFigure);
	chessBoardWidget->nextMoveSignal.connect(this, &ChessGameWidget::setChessMoves);
	newGameButton->clicked().connect(this, &ChessGameWidget::newGame);

	hbox->addWidget(std::move(vbox));
}

void ChessGameWidget::newGame()
{
	setLayout(std::move(hbox));
	chessBoardWidget->generateChessBoard();
	chessBoardWidget->generateChessPieces();
	chessBoardWidget->setDefaultColors();
	panelWidget->cleartLostFigures();
	panelWidget->updateArrow();
}

void ChessGameWidget::createNewGame() {
	endGameSignal.emit();
}

void ChessGameWidget::gameOver(int player)
{
	chessBoardWidget->blockAllSquares();
	endGameSignal.emit();

	if (player == 1) {
		StandardButton result = WMessageBox::show("End of the game", "Black Player wins", StandardButton::Ok);
	}
	else {
		StandardButton result = WMessageBox::show("End of the game", "White Player wins", StandardButton::Ok);
	}
	chessBoardWidget->hide();
	panelWidget->hide();
	anchor->hide();
	openGameUpload->hide();
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

void ChessGameWidget::openGame(std::string fileLocation) {

	string line;
	ifstream myfile(fileLocation);

	chessBoardWidget->resetChessboard();
	chessBoardWidget->generateChessPieces();
	chessBoardWidget->setDefaultColors();
	panelWidget->cleartLostFigures();
	panelWidget->updateArrow();

	try {
		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				chessBoardWidget->readFromText(line);
			}
			myfile.close();
		}
		else log("FILE") << "Unable to open file";
	}
	catch (exception e) {
		chessBoardWidget->resetChessboard();
		chessBoardWidget->generateChessPieces();
		panelWidget->cleartLostFigures();
		panelWidget->updateArrow();
	}
}




