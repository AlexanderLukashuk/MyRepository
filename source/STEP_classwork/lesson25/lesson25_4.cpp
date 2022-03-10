#include <iostream>
using namespace std;

class Parent
{
public:
    virtual Parent* getThis()
    {
        cout << "Parent\n";
        return this;
    }

    void show()
    {
        cout << "Parent's show\n";
    }
};

class Child : public Parent
{
public:
    virtual Child* getThis() override
    {
        cout << "Child\n";
        return this;
    }

    void show()
    {
        cout << "Child's show\n";
    }
};

int main()
{
    Child c;
    Parent* ptr = &c;
    c.getThis()->show();
    (ptr->getThis())->show();
}