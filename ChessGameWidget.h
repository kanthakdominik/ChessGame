#ifndef START_WIDGET_H_
#define START_WIDGET_H_

#include <vector>
#include <Wt/WImage.h>
#include <Wt/WContainerWidget.h>

#include "PanelWidget.h"
#include "ChessBoardWidget.h"
#include "ChessResource.h"

using namespace Wt;

class Session;
class PanelWidget;
class ChessBoardWidget;

/**
 * Klasa dziedzicz¹ca po WContainerWidget, odpowiadaj¹ca za obs³ugê gry w szachy
 */
class ChessGameWidget : public WContainerWidget
{
public:
	/**
	 * Konstruktor klasy dodaj¹cy widgety, oraz kontrolki odpowiedzialne za zapisywania i wczytywanie gry
	*/
	ChessGameWidget(const std::string& name);

	/**
	 * Metoda odpowiedzialna za stworzenie nowej gry przy pierwszym uruchomieniu 
	*/
	void newGame();

	/**
	 * Metoda odpowiedzialna za wczytanie stanu gry z pliku
	 * fileLocation - link do pliku ze stanem gry
	*/
	void openGame(std::string fileLocation);

	/**
	 * Metoda bêd¹ca slotem, wywo³ywana sygna³em endGameSignal, odpowiadaj¹ca za stworzenie noweg gry w trakcie obecnej gry
	*/
	void createNewGame();

	/**
	 * Metoda bêd¹ca slotem, wywo³ywana sygna³em nextMoveSignal, odpowiadaj¹ca za dodanie nowego ruchu do historii ruchów
	*/
	void setChessMoves();

	/**
	 * Metoda bêd¹ca slotem, wywo³ywana sygna³em checkMateSignal, odpowiadaj¹ca za wyœwietlenie okna z informacj¹ o wyniku gry
	 * int player - numer gracza, który wygra³
	*/
	void gameOver(int player);

	/**
	 * Sygna³ wywo³ujacy metody StartWidget::addGameToScore oraz StartWidget::createNewGame 
	 * aktywowany po naciœniêciu przycisku tworz¹cego now¹ grê
	*/
	Signal<> endGameSignal;

private:
	WLink link;
	WString name_;
	WAnchor* anchor;
	WFileUpload* openGameUpload;
	std::unique_ptr<WHBoxLayout> hbox;
	std::unique_ptr<WContainerWidget> vbox;
	WPushButton* newGameButton;
	WPushButton* createNewGameButton;
	PanelWidget* panelWidget;
	ChessBoardWidget* chessBoardWidget;
	std::shared_ptr<ChessResource> textResource;
};

#endif //START_WIDGET_H_
