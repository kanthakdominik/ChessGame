
#ifndef HIGH_SCORES_WIDGET_H_
#define HIGH_SCORES_WIDGET_H_

#include <Wt/WContainerWidget.h>

using namespace Wt;

class Session;

/**
 * Klasa dziedzicz¹ca po WContainerWidget, odpowiadaj¹ca za wyœwietlanie statystyk u¿ytkowników 
 * oraz ich aktualizacjê
 */
class HighScoresWidget : public WContainerWidget
{
public:

    /**
    * Konstruktor przyjmuj¹cy obiekt sesji jako parametr
    * Session* session - aktualna sesja
   */
    HighScoresWidget(Session* session);

    /**
     * Metoda odpowiedzialna za wyœwietlenie oraz odœwie¿anie tabeli statystyk
    */
    void update();

private:
    Session* session_;
};

#endif //HIGH_SCORES_WIDGET_H_
