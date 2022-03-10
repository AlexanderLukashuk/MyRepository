#include <iostream>
#include <list>
using namespace std;

class Parent
{
public:
    virtual void show()
    {
        cout << "Parent" << endl;
    }

    virtual ~Parent()
    {
        cout << "DESTR Parent" << endl;
    }
};

class Son : public Parent
{
public:
    virtual void show() override
    {
        cout << "Son" << endl;
    }

    ~Son()
    {
        cout << "DESTR Son" << endl;
    }
};

class Daughter : public Parent
{
public:
    virtual void show() override
    {
        cout << "Daughter" << endl;
    }

    ~Daughter()
    {
        cout << "DESTR Daughter" << endl;
    }
};

int main()
{
    list<unique_ptr<Parent>> persons;

    persons.push_back(make_unique<Parent>());
    persons.push_back(make_unique<Son>());
    persons.push_back(make_unique<Daughter>());
    persons.push_back(make_unique<Daughter>());
    persons.push_back(make_unique<Parent>());
    persons.push_back(make_unique<Son>());

    for (auto& el : persons)
    {
        el->show();
    }

    persons.front()->show();
    persons.back()->show();

    /*for (auto el : persons)
    {
        delete el;
    }*/
}