#include <iostream>
using namespace std;

namespace MyNameSpace
{
    void func() {}
    int num;
}

using MyNameSpace::num;

void func() {}

int main()
{
    num;
    func();
    MyNameSpace::func();
}