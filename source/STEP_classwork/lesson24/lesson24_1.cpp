#include <iostream>
using namespace std;

class A
{
protected:
    int numA = 1;
public:
    void showA()
    {
        cout << numA << endl;
    }
};

class B
{
protected:
    int numB = 2;
public:
    void showB()
    {
        cout << numB << endl;
    }
};

class C : public A, public B
{
protected:
    int numC = 3;
public:
    void showC()
    {
        cout << numC << endl;
    }
};

int main()
{
    C c;
    c.showA();
    c.showB();
    c.showC();

}