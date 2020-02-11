#include <iostream>
using namespace std;
int main ()
{
    int S, t, V;

    cout << "Enter distance to airport: ";
    cin >> S;
    cout << "Enter time for which you need to get to the airport: ";
    cin >> t;

    V = S / t;
    cout << "You should ride with speed = " << V << endl;
    return 0;
}
