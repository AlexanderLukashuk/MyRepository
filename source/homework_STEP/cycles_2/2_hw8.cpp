#include <iostream>
using namespace std;
int main ()
{
    int x, y, power = 1;

    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    for (int i = 1; i <= y; i++)
    {
        power = power * x;
    }
    cout << "power = " << power << endl;
    return 0;
}
