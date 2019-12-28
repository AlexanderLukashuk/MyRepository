#include <iostream>
using namespace std;
int main ()
{
    const double km_per_mile = 1.6;
    const double mile_per_naut_mil = 1.9;
    double miles, km, naut_mil;

    cout << "Enter miles: ";
    cin >> miles;

    km = miles * km_per_mile;
    naut_mil = miles * mile_per_naut_mil;
    cout << "Kilometers = " << km << endl;
    cout << "Nautical miles = " << naut_mil << endl;

    return 0;
}
