#include <iostream>
using namespace std;

class A
{
public:
    virtual void print()
    {
        cout << "A\n";
    }
};

class B : public A
{
public:
    void print()
    {
        cout << "B\n";
    }
};

class C : public B
{
public:
    void print()
    {
        cout << "C\n";
    }
};

class D : public C
{
public:
    void print()
    {
        cout << "D\n";
    }
};

int main()
{
    //A* ptr = new D();
    //A* ptr = new C();
    B* ptr = new D();
    ptr->print();
}