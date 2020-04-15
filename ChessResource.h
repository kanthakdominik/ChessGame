#ifndef CHESS_RESOURCE_
#define CHESS_RESOURCE_

#include <Wt/Http/Request.h>
#include <Wt/Http/Response.h>
#include <Wt/WObject.h>
#include <Wt/WResource.h>

using namespace Wt;


class ChessResource : public WResource
{
public:
	ChessResource();
	~ChessResource();
	void handleRequest(const Http::Request& request, Http::Response& response);
	void setText(std::string text);

private:
	std::string text;
};

#endif //CHESS_RESOURCE_
