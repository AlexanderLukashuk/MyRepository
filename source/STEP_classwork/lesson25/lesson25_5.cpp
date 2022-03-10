#include <iostream>
using namespace std;

class INameOfClass
{
public:
    virtual void someMethod1() = 0;
    //virtual void someMethod2() = 0;
    //virtual void someMethod3() = 0;

    virtual ~INameOfClass() {}
};

class NameOfClass : public INameOfClass
{
public:
    virtual void someMethod1() override
    {
        cout << "Some instructions\n";
    }
};

class NameOfClass2 : public INameOfClass
{
public:
    virtual void someMethod1() override
    {
        cout << "Another instructions\n";
    }
};

int main()
{
    INameOfClass* service = new NameOfClass2();
    service->someMethod1();
}