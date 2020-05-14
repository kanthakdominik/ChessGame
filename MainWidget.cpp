#include "MainWidget.h"

MainWidget::MainWidget(Game* game) : WContainerWidget(), game(game) 
{
	session.login().changed().connect(this, &MainWidget::onAuthEvent);

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
}

void MainWidget::onAuthEvent()
{
	if (session.login().loggedIn()) {
		links->show();
		handleInternalPath(WApplication::instance()->internalPath());
	}
	else {
		mainStack->clear();
		links_->hide();
	}
}

void MainWidget::handleInternalPath(const std::string& internalPath)
{
	if (session.login().loggedIn()) {
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