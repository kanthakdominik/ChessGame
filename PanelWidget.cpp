#include "PanelWidget.h"

PanelWidget::PanelWidget() : WContainerWidget()
{
	setStyleClass("panel-box");

	//player1 Arrow
	WContainerWidget* player1Arrow = new WContainerWidget();
	auto player1ArrowLayout = std::make_unique<WHBoxLayout>();
	player1ArrowLayout->addWidget(std::make_unique<WImage>(WLink("resources/Images/arrow.png")));
	player1Arrow->setLayout(std::move(player1ArrowLayout));
	player1Arrow->setStyleClass("playerArrow");

	//player2 Arrow
	WContainerWidget* player2Arrow = new WContainerWidget();
	auto player2ArrowLayout = std::make_unique<WHBoxLayout>();
	player2ArrowLayout->addWidget(std::make_unique<WImage>(WLink("resources/Images/arrow.png")));
	player2Arrow->setLayout(std::move(player2ArrowLayout));
	player2Arrow->setStyleClass("playerArrow");

	//player1 Image
	WContainerWidget* player1Image = new WContainerWidget();
	auto player1ImageLayout = std::make_unique<WHBoxLayout>();
	player1ImageLayout->addWidget(std::make_unique<WImage>(WLink("resources/Images/player_black.png")));
	player1Image->setLayout(std::move(player1ImageLayout));
	player1Image->setStyleClass("playerImage");

	//player2 Image
	WContainerWidget* player2Image = new WContainerWidget();
	auto player2ImageLayout = std::make_unique<WHBoxLayout>();
	player2ImageLayout->addWidget(std::make_unique<WImage>(WLink("resources/Images/player_white.png")));
	player2Image->setLayout(std::move(player2ImageLayout));
	player2Image->setStyleClass("playerImage");

	//player1 Label
	WContainerWidget* player1Label = new WContainerWidget();
	auto player1LabelLayout = std::make_unique<WHBoxLayout>();
	player1LabelLayout->addWidget(std::make_unique<WText>("Player Black"));
	player1Label->setLayout(std::move(player1LabelLayout));
	player1Label->setStyleClass("playerLabel");

	//player2 Label
	WContainerWidget* player2Label = new WContainerWidget();
	auto player2LabelLayout = std::make_unique<WHBoxLayout>();
	player2LabelLayout->addWidget(std::make_unique<WText>("Player White"));
	player2Label->setLayout(std::move(player2LabelLayout));
	player2Label->setStyleClass("playerLabel");

	//player1 lost pieces
	WContainerWidget* player1LostPieces = new WContainerWidget();
	auto player1LostPiecesLayout = std::make_unique<WGridLayout>();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			auto image = std::make_unique<WImage>(ChessPiece(1, Figure::KING).getIconLink());
			image->setStyleClass("lostFigureImage");
			player1LostPiecesLayout->addWidget(std::move(image), i, j);
		}
	}
	player1LostPieces->setLayout(std::move(player1LostPiecesLayout));

	//player2 lost pieces
	WContainerWidget* player2LostPieces = new WContainerWidget();
	auto player2LostPiecesLayout = std::make_unique<WGridLayout>();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			auto image = std::make_unique<WImage>(ChessPiece(2, Figure::KING).getIconLink());
			image->setStyleClass("lostFigureImage");
			player2LostPiecesLayout->addWidget(std::move(image), i, j);
		}
	}
	player2LostPieces->setLayout(std::move(player2LostPiecesLayout));

	//panel
	WContainerWidget* panel = addWidget(std::make_unique<WContainerWidget>());
	auto panelLayout = std::make_unique<WGridLayout>();
	panelLayout->addWidget(std::unique_ptr<WContainerWidget>(player1Arrow), 0, 0);
	panelLayout->addWidget(std::unique_ptr<WContainerWidget>(player1Image), 1, 0);
	panelLayout->addWidget(std::unique_ptr<WContainerWidget>(player1Label), 2, 0);
	panelLayout->addWidget(std::unique_ptr<WContainerWidget>(player1LostPieces), 3, 0);
	panelLayout->addWidget(std::unique_ptr<WContainerWidget>(player2Arrow), 0, 1);
	panelLayout->addWidget(std::unique_ptr<WContainerWidget>(player2Image), 1, 1);
	panelLayout->addWidget(std::unique_ptr<WContainerWidget>(player2Label), 2, 1);
	panelLayout->addWidget(std::unique_ptr<WContainerWidget>(player2LostPieces), 3, 1);
	panel->setLayout(std::move(panelLayout));

}
