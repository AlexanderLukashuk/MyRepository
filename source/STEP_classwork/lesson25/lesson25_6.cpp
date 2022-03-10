#include <iostream>
#include <vector>
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

    const string& getLogin() const 
    {
        return login;
    }

    const string& getPassword() const
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
    bool validUser(const User& user)
    {
        return (!user.getLogin().empty() || user.getPassword().empty());
        /*if (user.getLogin().empty() || user.getPassword().empty())
        {
            return false;
        }*/
    }
public:
    virtual bool signUp(const User &user) override
    {
        for (auto el : users)
        {
            if (el.getLogin() == user.getLogin() && el.getPassword() == user.getPassword())
            {
                return true;
            }   
        }
    }

    virtual bool signIn(const User &user) override
    {
        if (!validUser(user))
        {
            return false;
        }
        
        users.push_back(user);
        
        /*string log;
        string passW;
        cout << "Enter login: ";
        getline(cin, log);
        cout << "Pick a password: ";
        getline(cin, passW);
        cin.get();

        for (int i = 0; i < users.size(); ++i)
        {
            if (log == users[i].getLogin() && passW == users[i].getPassword())
            {
                cout << "Authorization was successful" << endl;
                return true;
            }
            else
            {
                cout << "Wrong login or password" << endl;
                return false;
            }
        }*/
    }

    void showAll()
    {
        for (int i = 0; i < users.size(); ++i)
        {
            cout << users[i].getLogin() << endl;
        }
    }
};

User &create()
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
    IAuthorizationService *ptr = new AuthorizationServiceSimple();

    if (ptr->signUp(User("Kirill", "QweAsd123")))
    {
        cout << "Registration was succesful" << endl;
    }
    else
    {
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
}