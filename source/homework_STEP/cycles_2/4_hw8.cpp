#include <iostream>
using namespace std;
int main ()
{
    long long a1, amount = 1;

    cout << "Enter a1(1 <= a1 <= 20): ";
    cin >> a1;

    if (a1 >= 1 && a1 <= 20)
    {
        for (int i = a1; i <= 20; i++)
        {
            amount *= i;
        }
        cout << "amount = " << amount << endl;
    }
    else 
    {
        cout << "You entered wrong a1\n";
    }
    return 0;
}
