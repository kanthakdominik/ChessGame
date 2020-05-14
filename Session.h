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
 * Klasa odpowiadaj¹ca za obs³ugê oraz utrzymanie sesji strony w przegl¹darce
 */
class Session
{
public:
    /**
    * Konstruktor który wczytuje bazê danych, w przypadku jej braku tworzy bazê danych oraz mapuje odpowiednie
    * klasy na tabele i tworzy konto goœcia
    */
    Session();

    /**
    * Metoda odpowiedzialna za konfiguracjê logowania
    */
    static void configureAuth();

    /**
    * Metoda zwracaj¹ca u¿ytkowników
    */
    Auth::AbstractUserDatabase& users();

    /**
    * Metoda zwracaj¹ca obiekt klasy Login
    */
    Auth::Login& login() { return login_; }

    /**
    * Metoda wysy³aj¹ca zapytanie do bazy danych i zwracaj¹ca u¿ytkowników z najwieksz¹ iloœci¹ zakoñcoznych gier
    * int limit - limit zwracanych u¿ytkowników
    */
    std::vector<User> topUsers(int limit);

    /**
    * Metoda zwracaj¹ca nazwe zalogowanego u¿ytkownika
    */
    std::string userName() const;

    /**
    * Metoda odpowiedzialna za dodanie nowego wyniku do tabeli
    */
    void addToScore();

    /**
    * Metoda zwracaj¹ca obiekt klasy AuthService
    */
    static const Auth::AuthService& auth();

    /**
    * Metoda zwracaj¹ca obiekt klasy PasswordService
    */
    static const Auth::AbstractPasswordService& passwordAuth();

    /**
    * Metoda zwracaj¹ca obiekt klasy MyOAuth
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