
#ifndef HIGH_SCORES_WIDGET_H_
#define HIGH_SCORES_WIDGET_H_

#include <Wt/WContainerWidget.h>

using namespace Wt;

class Session;

/**
 * Klasa dziedzicząca po WContainerWidget, odpowiadająca za wyświetlanie statystyk użytkowników 
 * oraz ich aktualizację
 */
class HighScoresWidget : public WContainerWidget
{
public:

    /**
    * Konstruktor przyjmujący obiekt sesji jako parametr
    * Session* session - aktualna sesja
   */
    HighScoresWidget(Session* session);

    /**
     * Metoda odpowiedzialna za wyświetlenie oraz odświeżanie tabeli statystyk
    */
    void update();

private:
    Session* session_;
};

#endif //HIGH_SCORES_WIDGET_H_
