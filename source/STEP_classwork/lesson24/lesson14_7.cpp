#include <iostream>
using namespace std;

class A
{
protected:
    int num;
public:
    int number;
    void show() {}
    void func() {}
};

class B : public A
{
private:
    using A::func;
    using A::number;
protected:

public:
    using A::num;
};

int main()
{
    B b;
    b.func();
    b.number = 8;
}