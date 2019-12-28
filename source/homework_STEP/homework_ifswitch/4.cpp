#include <iostream>
using namespace std;
int main ()
{
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    if (a == b)
    {
        cout << a << " = " << b << endl;
    }
    else if (a > b)
    {
        cout << b << ", " << a << endl;
    }
    else
    {
        cout << a << ", "  << b << endl;
    }
    return 0;
}
