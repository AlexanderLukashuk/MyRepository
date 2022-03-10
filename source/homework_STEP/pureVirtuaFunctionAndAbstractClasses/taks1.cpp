#include <iostream>
using namespace std;

class Employer
{
protected:
    string name;
public:
    Employer(string name) : name(name) {}
    virtual void print() = 0;
};

void Employer::print()
{
    cout << "Name: " << name << endl;
}

class President : public Employer
{
private:
    string country;
    int termOfGoverment;
public:
    President(string name, string country, int termOfGoverment) : Employer(name), country(country), termOfGoverment(termOfGoverment) {}

    virtual void print() override
    {
        cout << "Name: " << name << endl;
        cout << name << " rules " << country << endl;
        cout << name << " on the " << termOfGoverment << " term of the " << country << endl;
    }
};

class Manager : public Employer
{
private:
    string company;
public:
    Manager(string name, string company) : Employer(name), company(company) {}

    virtual void print() override
    {
        cout << "Name: " << name << endl;
        cout << name << " works in " << company << endl;
    }
};

class Worker : public Employer
{
public:
    Worker(string name) : Employer(name) {}

    virtual void print() override
    {
        cout << "Name: " << name << endl;
    }
};

int main()
{
    
}