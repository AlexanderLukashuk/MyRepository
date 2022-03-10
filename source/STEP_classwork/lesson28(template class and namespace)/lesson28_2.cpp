#include <iostream>
using namespace std;

namespace MyNameSpace
{
    void func() {}
}

namespace MyNameSpace
{
    int num;
}

void func() {}

int main()
{
    MyNameSpace::num;
}