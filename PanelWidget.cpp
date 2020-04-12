#include "PanelWidget.h"

PanelWidget::PanelWidget(ChessBoardWidget* chessBoard) : WContainerWidget()
{
	this->chessBoard = chessBoard;
	player1LostPiecesCounter = 0;
	player2LostPiecesCounter = 0;
	setStyleClass("panel-box");

	//players Arrows
	player1Arrow = addWidget(std::make_unique<WImage>(WLink("resources/Images/arrow.png")));
	player2Arrow = addWidget(std::make_unique<WImage>(WLink("resources/Images/arrow_blank.png")));

	//players Images
	WImage* player1Image = addWidget(std::make_unique<WImage>(WLink("resources/Images/player_black.png")));
	player1Image->setStyleClass("playerImage");
	WImage* player2Image = addWidget(std::make_unique<WImage>(WLink("resources/Images/player_white.png")));
	player2Image->setStyleClass("playerImage");

	//players Labels
	WText* player1Label = addWidget(std::make_unique<WText>("Player Black"));
	player1Label->setStyleClass("playerLabel");
	WText* player2Label = addWidget(std::make_unique<WText>("Player White"));
	player2Label->setStyleClass("playerLabel");

	//player1 empty lost pieces
	player1LostFiguresImage = std::make_unique<WContainerWidget>();
	player1LostFiguresImage->setStyleClass("lostFigureContainer");
	for (int i = 0; i < 16; i++) {
		player1LostFigures[i] = player1LostFiguresImage->addWidget(std::make_unique<WImage>(getBlancIconLink()));
		player1LostFigures[i]->setStyleClass("lostFigureImage");
	}
	addWidget(std::move(player1LostFiguresImage));

	//player2 empty lost pieces
	player2LostFiguresImage = std::make_unique<WContainerWidget>();
	player2LostFiguresImage->setStyleClass("lostFigureContainer");
	for (int i = 0; i < 16; i++) {
		player2LostFigures[i] = player2LostFiguresImage->addWidget(std::make_unique<WImage>(getBlancIconLink()));
		player2LostFigures[i]->setStyleClass("lostFigureImage");
	}
	addWidget(std::move(player2LostFiguresImage));
}

void PanelWidget::updateArrow() {
	player1Arrow->setImageLink("resources/Images/arrow_blank.png");
	player2Arrow->setImageLink("resources/Images/arrow_blank.png");

	if (chessBoard->currentPlayer == 1) {
		player1Arrow->setImageLink("resources/Images/arrow.png");
	}
	else {
		player2Arrow->setImageLink("resources/Images/arrow.png");
	}
}

WLink PanelWidget::getBlancIconLink() {
	return WLink("resources/Images/pieces/blank.png");
}

void PanelWidget::addLostFigure(WLink lostFigure) {

	if (chessBoard->currentPlayer == 1) {
		if (player1LostPiecesCounter < 16) {
			player1LostFigures[player1LostPiecesCounter]->setImageLink(lostFigure);
			player1LostPiecesCounter++;
		}
	}
	else {
		if (player2LostPiecesCounter < 16) {
			player2LostFigures[player2LostPiecesCounter]->setImageLink(lostFigure);
			player2LostPiecesCounter++;
		}
	}
}

void PanelWidget::cleartLostFigures() {
	player1LostPiecesCounter = 0;
	player2LostPiecesCounter = 0;

	for (int i = 0; i < 16; i++) {
		player1LostFigures[player1LostPiecesCounter]->setImageLink(getBlancIconLink());
		player2LostFigures[player2LostPiecesCounter]->setImageLink(getBlancIconLink());
	}
}
