#include <iostream>
using namespace std;

namespace MyNameSpace
{
    void func() {}
    int num;
}

void func() {}

int main()
{
    int num;

    func();
    num = 100;

    MyNameSpace::func();
    MyNameSpace::num = 123;

    cout << num << " ";
    cout << MyNameSpace::num << endl;
}