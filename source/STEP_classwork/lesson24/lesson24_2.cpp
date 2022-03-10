#include <iostream>
using namespace std;

class A
{
protected:
    int num = 1;
public:
    void show()
    {
        cout << num << endl;
    }
};

class B
{
protected:
    int num = 2;
public:
    void show()
    {
        cout << num << endl;
    }
};

class C : public A, public B
{
protected:
    int num = 3;
public:
    void show()
    {
        /*cout << A::num << endl;
        cout << B::num << endl;
        cout << num << endl;*/
        /*showA();
        showB();
        cout << num << endl;*/

        A::show();
        B::show();
        cout << num << endl;
    }
};

int main()
{
    C c;
    //c.showA();
    //c.showB();
    c.show();

}