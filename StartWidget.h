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
 * Klasa dziedzicz�ca po WContainerWidget, odpowiadaj�ca za g��wny widget wy�wietlany na stronie,
 * w niej osadzone s� wszystkie pozosta�e widgety
 */
class StartWidget : public WContainerWidget
{
public:
	/**
	* Kontruktor inicjuj�cy widgety aplikacji, kotwice pomiedzy stronami oraz ekran logowania
	*/
	StartWidget();

	/**
	* Metoda przechwytuj�ca �cie�ki adresu url strony oraz przekierowuj�ca do nich
	* const std::string& internalPath - �cie�ka adresu url
	*/
	void handleInternalPath(const std::string& internalPath);

	/**
	* Metoda b�d�ca slotem wywo�ywanym przez sygna� endGameSignal odpowiedzialna za zwi�kszenie ilo�ci
	* zako�czonych gier w bazie danych
	*/
	void addGameToScore();

	/**
	* Metoda b�d�ca slotem wywo�ywanym przez sygna� endGameSignal odpowiedzialna za zakonczenie obecnej gry
	* oraz rozpocz�cie nowej rozgrywki
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
	* Metoda bedaca slotem wywo�ywanym przez sygna� session_.login().changed() odpowiedzialna za dost�p do
	* gry po zalogowaniu oraz pozwalaj�ca na przechwytywanie �cie�ek adresu url
	*/
	void onAuthEvent();

	/**
	* Metoda odpowiedzialna za wy�wietlenie widgetu z gr�
	*/
	void showGame();

	/**
	* Metoda odpowiedzialna za wy�wietlenie widgetu ze statystykami
	*/
	void showHighScores();
};
#endif //START_WIDGET_H
