#include <iostream>
using namespace std;

class Parent
{
public:
    Parent()
    {
        cout << "CTOR Parent\n";
    }

    virtual ~Parent()
    {
        cout << "DESTR Parent\n";
    }

    virtual void method() const
    {
        cout << "Parent\n";
    }
};

class OBJ
{
private:
    int* ptr;
public:
    OBJ()
    {
        cout << "CTOR OBJ\n";
    }

    virtual ~OBJ()
    {
        cout << "DESTR OBJ\n";
        delete[] ptr;
    }
};

class Child : public Parent
{
    OBJ obj;
public:
    Child()
    {
        cout << "CTOR Child\n";
    }

    virtual ~Child()
    {
        cout << "DESTR Child\n";
    }

    virtual void method() const
    {
        cout << "Child\n";
    }
};


int main()
{
    {
        Parent* ptr = new Child();
        delete ptr;
    }
}