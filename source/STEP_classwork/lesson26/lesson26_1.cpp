#include <iostream>
using namespace std;

class Parent
{
public:
    virtual void method1() 
    {
        cout << "!" << endl;
    }
    virtual void method2() = 0;

};

class Child : public Parent
{
public:
    /*virtual void method1() 
    {
        cout << "?" << endl;
    }*/

    virtual void method2() override
    {
        cout << "Child" << endl;
    }
};

int main()
{
    //Parent p;
    //p.method1();

    Child c;
    c.method2();

    Parent* ptr = &c;
    ptr->method2();
}