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
 * Klasa dziedzicz�ca po WContainerWidget, odpowiadaj�ca za obs�ug� gry w szachy
 */
class ChessGameWidget : public WContainerWidget
{
public:
	/**
	 * Konstruktor klasy dodaj�cy widgety, oraz kontrolki odpowiedzialne za zapisywania i wczytywanie gry
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
	 * Metoda b�d�ca slotem, wywo�ywana sygna�em endGameSignal, odpowiadaj�ca za stworzenie noweg gry w trakcie obecnej gry
	*/
	void createNewGame();

	/**
	 * Metoda b�d�ca slotem, wywo�ywana sygna�em nextMoveSignal, odpowiadaj�ca za dodanie nowego ruchu do historii ruch�w
	*/
	void setChessMoves();

	/**
	 * Metoda b�d�ca slotem, wywo�ywana sygna�em checkMateSignal, odpowiadaj�ca za wy�wietlenie okna z informacj� o wyniku gry
	 * int player - numer gracza, kt�ry wygra�
	*/
	void gameOver(int player);

	/**
	 * Sygna� wywo�ujacy metody StartWidget::addGameToScore oraz StartWidget::createNewGame 
	 * aktywowany po naci�ni�ciu przycisku tworz�cego now� gr�
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
