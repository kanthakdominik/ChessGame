#include "PanelWidget.h"

PanelWidget::PanelWidget() : WContainerWidget()
{
	setStyleClass("panel-box");

	player1Arrow = addWidget(std::make_unique<WImage>(WLink("resources/Images/arrow_blank.png")));
	player2Arrow = addWidget(std::make_unique<WImage>(WLink("resources/Images/arrow_blank.png")));

	WImage* player1Image =addWidget(std::make_unique<WImage>(WLink("resources/Images/player_black.png")));
	player1Image->setStyleClass("playerImage");
	WImage* player2Image = addWidget(std::make_unique<WImage>(WLink("resources/Images/player_white.png")));
	player2Image->setStyleClass("playerImage");

	WText* player1Label = addWidget(std::make_unique<WText>("Player Black"));
	player1Label->setStyleClass("playerLabel");
	WText* player2Label = addWidget(std::make_unique<WText>("Player White"));
	player2Label->setStyleClass("playerLabel");

	////player1 lost pieces
	std::unique_ptr<WContainerWidget> lostFigureImage1 = std::make_unique<WContainerWidget>();
	lostFigureImage1->setStyleClass("lostFigureContainer");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			auto figure = lostFigureImage1->addWidget(std::make_unique<WImage>(ChessPiece(1, Figure::KING).getIconLink()));
			figure->setStyleClass("lostFigureImage");
		}
	}
	addWidget(std::move(lostFigureImage1));

	////player2 lost pieces
	std::unique_ptr<WContainerWidget> lostFigureImage2 = std::make_unique<WContainerWidget>();
	lostFigureImage2->setStyleClass("lostFigureContainer");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			auto figure = lostFigureImage2->addWidget(std::make_unique<WImage>(ChessPiece(0, Figure::QUEEN).getIconLink()));
			figure->setStyleClass("lostFigureImage");
		}
	}
	addWidget(std::move(lostFigureImage2));
}

void PanelWidget::setArrow(int player) {
	player1Arrow->setImageLink("resources/Images/arrow_blank.png");
	player2Arrow->setImageLink("resources/Images/arrow_blank.png");

	if (player == 1) {
		player1Arrow->setImageLink("resources/Images/arrow.png");
	}
	else {
		player2Arrow->setImageLink("resources/Images/arrow.png");
	}
}
	
