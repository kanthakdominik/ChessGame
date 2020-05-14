#ifndef CHESS_RESOURCE_
#define CHESS_RESOURCE_

#include <Wt/Http/Request.h>
#include <Wt/Http/Response.h>
#include <Wt/WObject.h>
#include <Wt/WResource.h>

using namespace Wt;

/**
 * Klasa dziedzicz¹ca po WResource, odpowiedzialna za zasób bêdacy zapisem gry, który mo¿na pobraæ na dysk
 */
class ChessResource : public WResource
{
public:
	/**
	* Konstruktor ustawiaj¹cy domyœln¹ nazwê zasobu
	*/
	ChessResource();

	/**
	* Dekonstruktor, który usuwa mo¿liwoœæ wysy³ania ¿¹dañ do tego zasobu
	*/
	~ChessResource();

	/**
	* Metoda przechwytuj¹ca ¿adania do tego zasobu oraz wysy³aj¹ca odpowiedŸ na te ¿¹dania
	* const Http::Request& request - ¿adanie
	* Http::Response& response - odpowiedŸ
	*/
	void handleRequest(const Http::Request& request, Http::Response& response);

	/**
	* Metoda ustawiaj¹ca tekst w zasobie
	*/
	void setText(std::string text);

private:
	std::string text;
};

#endif //CHESS_RESOURCE_
