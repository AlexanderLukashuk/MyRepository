#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User
{
private:
    string login;
    string password;

public:
    User() {}
    User(string login, string password) : login(login), password(password) {}

    void setLogin(string login)
    {
        if (login.empty() != true)
        {
            this->login = login;
        }
    }

    void setPassword(string password)
    {
        if (password.empty() != true)
        {
            this->password = password;
        }
    }

    const string &getLogin() const
    {
        return login;
    }

    const string &getPassword() const
    {
        return password;
    }
};

vector<User> users;

class IAuthorizationService
{
public:
    virtual bool signUp(const User &user) = 0;
    virtual bool signIn(const User &user) = 0;
};

class AuthorizationServiceSimple : public IAuthorizationService
{
    bool validUser(const User &user)
    {
        return !(user.getLogin().empty() || user.getPassword().empty());
    }

public:
    virtual bool signUp(const User &user) override
    {
        for (auto el : users)
        {
            if (el.getLogin() == user.getLogin() && el.getPassword() == user.getPassword())
            {
                return false;
            }
        }
        users.push_back(user);
        return true;
    }

    virtual bool signIn(const User &user) override
    {
        if (!validUser(user))
        {
            return false;
        }

        for (auto el : users)
        {
            if (el.getLogin() == user.getLogin() && el.getPassword() == user.getPassword())
            {
                return true;
            }
        }
        return false;
    }

    void showAll()
    {
        for (int i = 0; i < users.size(); ++i)
        {
            cout << users[i].getLogin() << endl;
        }
    }
};

class AuthorizationServiceHard : public IAuthorizationService
{
    bool validUser(const User &user)
    {
        return !(user.getLogin().empty() || user.getPassword().empty());
    }

    bool validLogin(const User &user)
    {
        bool check;   

        for (int i = 0; i < user.getLogin().size(); i++)
        {
            if (int(user.getLogin()[i]) >= 65 && int(user.getLogin()[i]) <= 90)
            {
                check = true;
            }
            else if (int(user.getLogin()[i]) >= 97 && int(user.getLogin()[i]) <= 122)
            {
                check = true;
            }
            else if (int(user.getLogin()[i]) >= 48 && int(user.getLogin()[i]) <= 57)
            {
                check = true;
            }
            else if (int(user.getLogin()[i]) == 95)
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
        }

        return check;
    }

    bool validPassword(const User &user)
    {
        bool check;

        int size = user.getPassword().size();

        if (size < 6 || size > 20)
        {
            return false;
        }

        for (int i = 0; i < user.getPassword().size(); i++)
        {
            if (int(user.getPassword()[i]) >= 65 && int(user.getPassword()[i]) <= 90)
            {
                check = true;
            }
            else if (int(user.getPassword()[i]) >= 97 && int(user.getPassword()[i]) <= 122)
            {
                check = true;
            }
            else if (int(user.getPassword()[i]) >= 48 && int(user.getPassword()[i]) <= 57)
            {
                check = true;
            }
            else if (int(user.getPassword()[i]) == 95)
            {
                check = true;
            }
            else
            {
                check = false;
                break;
            }
        }

        return check;
    }

public:
    virtual bool signUp(const User &user) override
    {
        if ((validLogin(user) && validPassword(user)) == true)
        {
            for (auto el : users)
            {
                if (el.getLogin() == user.getLogin() && el.getPassword() == user.getPassword())
                {
                    return false;
                }
            }
            users.push_back(user);
            return true;
        }
    }

    virtual bool signIn(const User &user) override
    {
        if ((validLogin(user) && validPassword(user)) == true)
        {
            if (!validUser(user))
            {
                return false;
            }

            for (auto el : users)
            {
                if (el.getLogin() == user.getLogin() && el.getPassword() == user.getPassword())
                {
                    return true;
                }
            }
            return false;
        }
    }
};

void create()
{
    string log;
    string passW;
    cout << "Enter login: ";
    getline(cin, log);
    cout << "Pick a password: ";
    getline(cin, passW);
    cin.get();

    if (log.empty() != true && passW.empty() != true)
    {
        users.push_back(User(log, passW));
        return;
    }
    else
    {
        cout << "Authorization is incorrect" << endl;
    }
}

int main()
{
    users.push_back(User("Alex", "12345"));
    users.push_back(User("Danil", "qwerty"));
    users.push_back(User("John", "ASD123"));
    //IAuthorizationService *ptr = new AuthorizationServiceSimple();
    IAuthorizationService *ptr = new AuthorizationServiceHard();

    if (ptr->signUp(User("Kirill", "QweAsd123")))
    {
        cout << "Registration was succesful" << endl;
    }
    else
    {
        cout << "registrtion failed" << endl;
    }

    if (ptr->signUp(User("John", "JohnFucker")))
    {
        cout << "John krasava" << endl;
        cout << "Registration was succesful" << endl;
    }
    else
    {
        cout << "John is loser" << endl;
        cout << "registrtion failed" << endl;
    }

    for (auto user : users)
    {
        cout << user.getLogin() << " " << user.getPassword() << endl;
    }

    if (ptr->signIn(User("qwd", "asd")))
    {
        cout << "Autorization was succesful" << endl;
    }
    else
    {
        cout << "Autorization failed" << endl;
    }

    if (ptr->signIn(User("Danil", "qwerty")))
    {
        cout << "Autorization was succesful" << endl;
    }
    else
    {
        cout << "Autorization failed" << endl;
    }
}