#ifndef CHESS_RESOURCE_
#define CHESS_RESOURCE_

#include <Wt/Http/Request.h>
#include <Wt/Http/Response.h>
#include <Wt/WObject.h>
#include <Wt/WResource.h>

using namespace Wt;

/**
 * Klasa dziedzicz�ca po WResource, odpowiedzialna za zas�b b�dacy zapisem gry, kt�ry mo�na pobra� na dysk
 */
class ChessResource : public WResource
{
public:
	/**
	* Konstruktor ustawiaj�cy domy�ln� nazw� zasobu
	*/
	ChessResource();

	/**
	* Dekonstruktor, kt�ry usuwa mo�liwo�� wysy�ania ��da� do tego zasobu
	*/
	~ChessResource();

	/**
	* Metoda przechwytuj�ca �adania do tego zasobu oraz wysy�aj�ca odpowied� na te ��dania
	* const Http::Request& request - �adanie
	* Http::Response& response - odpowied�
	*/
	void handleRequest(const Http::Request& request, Http::Response& response);

	/**
	* Metoda ustawiaj�ca tekst w zasobie
	*/
	void setText(std::string text);

private:
	std::string text;
};

#endif //CHESS_RESOURCE_
