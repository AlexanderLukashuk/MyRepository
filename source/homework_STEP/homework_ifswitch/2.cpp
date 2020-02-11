#include <iostream>
using namespace std;
int main ()
{
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    if (a < b)
    {
    cout << a << " is less" << endl;
    }
    else if (a == b)
    cout << a << " = " << b << endl;
    else
    cout << b << " is less " << endl;
    return 0;
}
