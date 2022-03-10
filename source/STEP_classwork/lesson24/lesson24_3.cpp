#include <iostream>
using namespace std;

class Base
{
protected:
    int num;
};

class A : public Base
{
protected:
public:
    A() { num = 1; }
};

class B : public Base
{
protected:
public:
    B() { num = 2; }
};

class C : public A, public B
{
protected:
public:
    void show()
    {
        cout << A::num << B::num << endl;
    }
};

int main()
{
    C c;
    //c.showA();
    //c.showB();
    c.show();

}