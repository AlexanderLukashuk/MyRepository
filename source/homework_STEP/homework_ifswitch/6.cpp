#include <iostream>
using namespace std;
int main ()
{
    int num;

    cout << "Enter any number: ";
    cin >> num;

    if (num % 2 == 0)
    {
        num *= 3;
        cout << "Now your number = " << num << endl;
    }
    else
    {
        num /= 2;
        cout << "Now your number = " << num << endl;
    }
    return 0;
}
