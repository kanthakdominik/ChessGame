#ifndef SESSION_H_
#define SESSION_H_

#include <vector>

#include <Wt/Auth/Login.h>

#include <Wt/Dbo/Session.h>
#include <Wt/Dbo/ptr.h>
#include <Wt/Dbo/backend/Sqlite3.h>

#include "User.h"

using namespace Wt;

typedef Auth::Dbo::UserDatabase<AuthInfo> UserDatabase;

/**
 * Klasa odpowiadaj�ca za obs�ug� oraz utrzymanie sesji strony w przegl�darce
 */
class Session
{
public:
    /**
    * Konstruktor kt�ry wczytuje baz� danych, w przypadku jej braku tworzy baz� danych oraz mapuje odpowiednie
    * klasy na tabele i tworzy konto go�cia
    */
    Session();

    /**
    * Metoda odpowiedzialna za konfiguracj� logowania
    */
    static void configureAuth();

    /**
    * Metoda zwracaj�ca u�ytkownik�w
    */
    Auth::AbstractUserDatabase& users();

    /**
    * Metoda zwracaj�ca obiekt klasy Login
    */
    Auth::Login& login() { return login_; }

    /**
    * Metoda wysy�aj�ca zapytanie do bazy danych i zwracaj�ca u�ytkownik�w z najwieksz� ilo�ci� zako�coznych gier
    * int limit - limit zwracanych u�ytkownik�w
    */
    std::vector<User> topUsers(int limit);

    /**
    * Metoda zwracaj�ca nazwe zalogowanego u�ytkownika
    */
    std::string userName() const;

    /**
    * Metoda odpowiedzialna za dodanie nowego wyniku do tabeli
    */
    void addToScore();

    /**
    * Metoda zwracaj�ca obiekt klasy AuthService
    */
    static const Auth::AuthService& auth();

    /**
    * Metoda zwracaj�ca obiekt klasy PasswordService
    */
    static const Auth::AbstractPasswordService& passwordAuth();

    /**
    * Metoda zwracaj�ca obiekt klasy MyOAuth
    */
    static const std::vector<const Auth::OAuthService*>& oAuth();

    ~Session();

private:
    mutable Dbo::Session session_;
    std::unique_ptr<UserDatabase> users_;
    Auth::Login login_;
    Dbo::ptr<User> user() const;
};

#endif //SESSION_H_