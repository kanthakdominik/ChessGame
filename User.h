#ifndef USER_H_
#define USER_H_

#include <Wt/WDateTime.h>
#include <Wt/Dbo/Types.h>
#include <Wt/Dbo/WtSqlTraits.h>
#include <Wt/Auth/Dbo/AuthInfo.h>

#include <string>

using namespace Wt;

namespace dbo = Wt::Dbo;

class User;
typedef Auth::Dbo::AuthInfo<User> AuthInfo;
typedef dbo::collection< dbo::ptr<User> > Users;

/**
 * Klasa odpowiadaj¹ca za u¿ytkownika, który jest aktualnie zalogowany
 */
class User
{
public:

    /**
    * Szablon metody s³u¿¹cy do zapisania encji w bazie danych
    */
    template<class Action>
    void persist(Action& a)
    {
        dbo::field(a, gamesPlayed, "gamesPlayed");
        dbo::field(a, lastGame, "lastGame");
        dbo::hasMany(a, authInfos, dbo::ManyToOne, "user");
    }
    User();
    std::string name;
    int gamesPlayed;
    WDateTime lastGame;
    dbo::collection<dbo::ptr<AuthInfo>> authInfos;
};

DBO_EXTERN_TEMPLATES(User);

#endif // USER_H_