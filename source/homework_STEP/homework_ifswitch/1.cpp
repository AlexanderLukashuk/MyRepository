#include <iostream>
using namespace std;
int main ()
{
    int x;

    cout << "Enter a number: ";
    cin >> x;

    if (x % 2 == 0)
    {
        cout << x << " - even number" << endl;
    }
    else
    {
        cout << x << " - odd number" << endl;
    }
    return 0;
}
