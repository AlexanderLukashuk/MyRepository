#ifndef _PERSON_N_
#define _PERSON_H_
#include <string>
#include <vector>
#include "account.hpp"

class Account;

class Person
{
private:
    std::vector<Account> account;
    std::string name;
    std::string lastName;
    int age;
public:
    Person();
    Person(std::string name, std::string lastName, int age);

    void addAccount(const Account& obj)
    {
        account.push_back(obj);
    }
    void setName(std::string name);
    void setLastName(std::string lastName);
    void setAge(int age);
    std::string getName();
    std::string getLastName();
    int getAge();
};
#endif