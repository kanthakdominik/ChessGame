
#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>


class HelloApplication : public Wt::WApplication
{
public:
    HelloApplication(const Wt::WEnvironment& env);

};

/*
 * The env argument contains information about the new session, and
 * the initial request. It must be passed to the WApplication
 * constructor so it is typically also an argument for your custom
 * application constructor.
*/
HelloApplication::HelloApplication(const Wt::WEnvironment& env)
    : WApplication(env)
{
    setTitle("ChessWeb");                      // application title
}

int main(int argc, char** argv)
{
    /*
     * Your main method may set up some shared resources, but should then
     * start the server application (FastCGI or httpd) that starts listening
     * for requests, and handles all of the application life cycles.
     *
     * The last argument to WRun specifies the function that will instantiate
     * new application objects. That function is executed when a new user surfs
     * to the Wt application, and after the library has negotiated browser
     * support. The function should return a newly instantiated application
     * object.
     */
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
        /*
         * You could read information from the environment to decide whether
         * the user has permission to start a new application
         */
        return Wt::cpp14::make_unique<HelloApplication>(env);
        });
}
