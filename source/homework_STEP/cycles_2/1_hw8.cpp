#include <iostream>
using namespace std;
int main ()
{
    int a, sum = 0;

    cout << "Enter a number: ";
    cin >> a;

    for (int i = a; i <= 500; i++)
    {
        sum += i;
    }
    cout << "The amout = " << sum << endl;
    return 0;
}
