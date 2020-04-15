#include "ChessResource.h"

ChessResource::ChessResource() :  WResource()
{
	suggestFileName("chessData.txt");
}

void ChessResource::handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response) 
{
	response.setMimeType("plain/text");
	response.out() << text;
}

void ChessResource::setText(std::string text) {
	this->text = text;
}

ChessResource::~ChessResource()
{
	beingDeleted();
}
