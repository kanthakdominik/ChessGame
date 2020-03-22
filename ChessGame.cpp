
#include <Wt/WAnchor.h>
#include <Wt/WText.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WApplication.h>
#include <Wt/Auth/AuthWidget.h>
#include <Wt/Auth/RegistrationModel.h>

#include "ChessGame.h"
#include "StartWidget.h"
#include "HighScoresWidget.h"

ChessGame::ChessGame() : WContainerWidget(), game_(0), scores_(0)
{
	session_.login().changed().connect(this, &ChessGame::onAuthEvent);

	std::unique_ptr<Auth::AuthModel> authModel = cpp14::make_unique<Auth::AuthModel>(Session::auth(), session_.users());
	authModel->addPasswordAuth(&Session::passwordAuth());
	authModel->addOAuth(Session::oAuth());

	std::unique_ptr<Auth::AuthWidget> authWidget = cpp14::make_unique<Auth::AuthWidget>(session_.login());
	auto authWidgetPtr = authWidget.get();
	authWidget->setModel(std::move(authModel));
	authWidget->setRegistrationEnabled(true);

	std::unique_ptr<WText> title(cpp14::make_unique<WText>("<h1>Chess Game</h1>"));
	addWidget(std::move(title));

	addWidget(std::move(authWidget));

	mainStack_ = new WStackedWidget();
	mainStack_->setStyleClass("gamestack");
	addWidget(std::unique_ptr<WStackedWidget>(mainStack_));

	links_ = new WContainerWidget();
	links_->setStyleClass("links");
	links_->hide();
	addWidget(std::unique_ptr<WContainerWidget>(links_));

	backToGameAnchor_ = links_->addWidget(cpp14::make_unique<WAnchor>("/play", "Game"));
	backToGameAnchor_->setLink(WLink(LinkType::InternalPath, "/play"));

	scoresAnchor_ = links_->addWidget(cpp14::make_unique<WAnchor>("/highscores", "Highscores"));
	scoresAnchor_->setLink(WLink(LinkType::InternalPath, "/highscores"));

	WApplication::instance()->internalPathChanged().connect(this, &ChessGame::handleInternalPath);

	authWidgetPtr->processEnvironment();
}

void ChessGame::onAuthEvent()
{
	if (session_.login().loggedIn()) {
		links_->show();
		handleInternalPath(WApplication::instance()->internalPath());
	}
	else {
		mainStack_->clear();
		game_ = 0;
		scores_ = 0;
		links_->hide();
	}
}

void ChessGame::handleInternalPath(const std::string& internalPath)
{
	if (session_.login().loggedIn()) {
		if (internalPath == "/play") {
			showGame();
		}
		else if (internalPath == "/highscores") {
			showHighScores();
		}
		else {
			WApplication::instance()->setInternalPath("/play", true);
		}	
	}
}

void ChessGame::showHighScores()
{
	if (!scores_) {
		scores_ = mainStack_->addWidget(cpp14::make_unique<HighScoresWidget>(&session_));
	}
		
	mainStack_->setCurrentWidget(scores_);
	scores_->update();

	backToGameAnchor_->removeStyleClass("selected-link");
	scoresAnchor_->addStyleClass("selected-link");
}

void ChessGame::showGame()
{
	if (!game_) {
		game_ = mainStack_->addWidget(cpp14::make_unique<StartWidget>(session_.userName()));
	}

	mainStack_->setCurrentWidget(game_);

	backToGameAnchor_->addStyleClass("selected-link");
	scoresAnchor_->removeStyleClass("selected-link");
}
