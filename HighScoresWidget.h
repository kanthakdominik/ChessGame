
#ifndef HIGH_SCORES_WIDGET_H_
#define HIGH_SCORES_WIDGET_H_

#include <Wt/WContainerWidget.h>

using namespace Wt;

class Session;

/**
 * Klasa dziedzicz�ca po WContainerWidget, odpowiadaj�ca za wy�wietlanie statystyk u�ytkownik�w 
 * oraz ich aktualizacj�
 */
class HighScoresWidget : public WContainerWidget
{
public:

    /**
    * Konstruktor przyjmuj�cy obiekt sesji jako parametr
    * Session* session - aktualna sesja
   */
    HighScoresWidget(Session* session);

    /**
     * Metoda odpowiedzialna za wy�wietlenie oraz od�wie�anie tabeli statystyk
    */
    void update();

private:
    Session* session_;
};

#endif //HIGH_SCORES_WIDGET_H_
