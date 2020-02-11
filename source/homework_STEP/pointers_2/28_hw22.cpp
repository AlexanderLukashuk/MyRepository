#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    int* pa = &a;
    int* pb = &b;
    int* pc = &c;

    cout << (int)pa - (int)pb << endl;
    cout << &a - &b << endl;

    return 0;
}
