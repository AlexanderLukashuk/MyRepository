#include <iostream>
using namespace std;
int main ()
{
    int a;

    cout << "Enter a number: ";
    cin >> a;

    cout << "divided without remainder: ";
    for (int i = 1; i <= a; i++)
    {
        if (a % (i * i) == 0)
        {
            cout << i << " ";
        }
    }

    cout << endl;

    cout << "not divided without remainder: ";
    for (int i = 1; i <= a; i++)
    {
        if (a % (i * i * i) != 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
