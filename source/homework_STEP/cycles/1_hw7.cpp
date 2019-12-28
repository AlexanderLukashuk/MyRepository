#include <iostream>
using namespace std;
int main ()
{
    const double persent = 0.03;
    double S;
    int N;

    cout << "Enter the amount you want to put on the account at interest: ";
    cin >> S;
    cout << "Enter the time after which you want to pick up the deposit: ";
    cin >> N;

    S = S + (S * (persent * N));
    cout << "Now your money = " << S << endl;
    return 0;
}
