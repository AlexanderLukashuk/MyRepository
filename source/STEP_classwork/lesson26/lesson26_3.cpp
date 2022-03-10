#include <iostream>
#include <vector>
using namespace std;

class Parent
{
public:
    virtual void method1() = 0;


    virtual ~Parent() {}
};

class Son : public Parent
{
public:
    void baleron()
    {
        cout << "tancyet detka" << endl;
    }

    virtual void method1() override
    {
        cout << "Son" << endl;
    }
};

class Daughter : public Parent
{
public:
    void borba()
    {
        cout << "Delay borba" << endl;
    }
    virtual void method1() override
    {
        cout << "Daughter" << endl;
    }
};

int main()
{
    //Parent* ptrP = new Parent();
    Parent* ptrS = new Son();
    Parent* ptrD = new Daughter();

    Son* p = dynamic_cast<Son*>(ptrS);

    // dynamic_cast пытатся преобразовать родительский указатель 
    //в указатель дочернего класса 
    //если ему это не удается то оставляет nullptr
    if (dynamic_cast<Son*>(ptrS))
    {
        cout << "Good" << endl;
        dynamic_cast<Son*>(ptrS)->baleron();
    }
}