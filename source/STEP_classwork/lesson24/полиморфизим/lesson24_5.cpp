#include <iostream>
using namespace std;

class A
{
public:
    virtual void method()
    {

    }
};

class B : public A
{
public:
    virtual void method() override final
    {

    }
};

class C final : public B
{
public:
    // virtual void method() override final
    // {
        
    // }
};

// class D : public C
// {

// };

int main()
{
    B b;
    A* ptr = &b;
    A& ref = b;

    ptr->method();
    ref.method();
}