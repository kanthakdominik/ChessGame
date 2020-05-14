#ifndef START_WIDGET_H
#define START_WIDGET_H

#include <Wt/WContainerWidget.h>

#include "Session.h"

using namespace Wt;

class Wt::WStackedWidget;
class Wt::WAnchor;
class ChessGameWidget;
class HighScoresWidget;
class Session;

/**
 * Klasa dziedzicz¹ca po WContainerWidget, odpowiadaj¹ca za g³ówny widget wyœwietlany na stronie,
 * w niej osadzone s¹ wszystkie pozosta³e widgety
 */
class StartWidget : public WContainerWidget
{
public:
	/**
	* Kontruktor inicjuj¹cy widgety aplikacji, kotwice pomiedzy stronami oraz ekran logowania
	*/
	StartWidget();

	/**
	* Metoda przechwytuj¹ca œcie¿ki adresu url strony oraz przekierowuj¹ca do nich
	* const std::string& internalPath - œcie¿ka adresu url
	*/
	void handleInternalPath(const std::string& internalPath);

	/**
	* Metoda bêd¹ca slotem wywo³ywanym przez sygna³ endGameSignal odpowiedzialna za zwiêkszenie iloœci
	* zakoñczonych gier w bazie danych
	*/
	void addGameToScore();

	/**
	* Metoda bêd¹ca slotem wywo³ywanym przez sygna³ endGameSignal odpowiedzialna za zakonczenie obecnej gry
	* oraz rozpoczêcie nowej rozgrywki
	*/
	void createNewGame();

private:
	WStackedWidget* mainStack_;
	ChessGameWidget* game_;
	HighScoresWidget* scores_;
	WContainerWidget* links_;
	WAnchor* backToGameAnchor_;
	WAnchor* scoresAnchor_;
	Session session_;

	/**
	* Metoda bedaca slotem wywo³ywanym przez sygna³ session_.login().changed() odpowiedzialna za dostêp do
	* gry po zalogowaniu oraz pozwalaj¹ca na przechwytywanie œcie¿ek adresu url
	*/
	void onAuthEvent();

	/**
	* Metoda odpowiedzialna za wyœwietlenie widgetu z gr¹
	*/
	void showGame();

	/**
	* Metoda odpowiedzialna za wyœwietlenie widgetu ze statystykami
	*/
	void showHighScores();
};
#endif //START_WIDGET_H
