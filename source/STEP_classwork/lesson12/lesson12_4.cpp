#include <iostream>
using namespace std;

class A;

class Display
{
public:
    //static void show(const A& obj)
    void show(const A& obj);
};

class A
{
private:
    int num1;
    double num2;
    friend class Display;
    friend void Display::show(const A& obj);
public:
    A() : num1(0), num2(0) {}
};

void Display::show(const A& obj)
    {
        cout << obj.num1 << " " << obj.num2 << endl;
    }

int main()
{
    A a;
    Display displ;
    displ.show(a);
    //Display::show(a);
}