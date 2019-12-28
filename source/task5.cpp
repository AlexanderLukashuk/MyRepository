#include <iostream>
#include <cmath>
int main ()
{
    using namespace std;
    int num;
    int units, tens, hund, thous;

    cout << "Enter four-digit number: ";
    cin >> num;
    units = num % 10;
    tens = ((num % 100) - units) / 10;
    hund = ((num % 1000) - (tens + units)) / 100;
    thous = ((num % 10000) - (hund + tens + units)) / 1000;
    cout << thous << endl;
    cout << hund << endl;
    cout << tens << endl;
    cout << units << endl;
    return 0;
}
