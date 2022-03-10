#include <iostream>
using namespace std;

//void func1() noexcept
void func1() throw()
{
    throw 1;
}

void func2()
{
    func1();
}

int main()
{
    try
    {
        func2();
        cout << 1;
        cout << 1;
        cout << 1;
    }
    catch (int)
    {
        cout << "Incorrect" << endl;
    }
}