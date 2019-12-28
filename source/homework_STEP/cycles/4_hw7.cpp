#include <iostream>
using namespace std;
int main ()
{
    const double PERCENT = 0.2;
    double m, s;
    int year = 0, add;

    cout << "Enter the amount of m thousand rubles: ";
    cin >> m;
    cout << "Enter debt s: ";
    cin >> s;

    add = m * PERCENT;

    while (m < s)
    {
        m += add;
        year++;
    }
    cout << "debt will be equal " << s << " across " << year << " years\n";
    return 0;
}
