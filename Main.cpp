
#include <Wt/WApplication.h>
#include <Wt/WServer.h>

#include "ChessGame.h"
#include "Session.h"

using namespace Wt;

std::unique_ptr<WApplication> createApplication(const WEnvironment& env)
{
    auto app = cpp14::make_unique<WApplication>(env);

    app->setTitle("Chess Game");

    app->messageResourceBundle().use(app->appRoot() + "strings");
    app->messageResourceBundle().use(app->appRoot() + "templates");

    app->useStyleSheet("css/chess.css");


    app->root()->addWidget(cpp14::make_unique<ChessGame>());

    return app;
}


int main(int argc, char** argv)
{
    try {
        WServer server(argc, argv, WTHTTP_CONFIGURATION);

        server.addEntryPoint(EntryPointType::Application, createApplication);

        Session::configureAuth();

        server.run();
    }
    catch (WServer::Exception& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }
}
