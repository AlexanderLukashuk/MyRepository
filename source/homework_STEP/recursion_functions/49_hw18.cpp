#include <iostream>
using namespace std;

long long fact(long long num)
{
    if (num == 0)
    {
        return 0;
    }
    else if (num == 1)
    {
        return 1;
    }
    else if (num > 1)
    {
        return num * fact(num - 1);
    }
}

int main()
{
    int num;

    cout << "Enter any number: ";
    cin >> num;

    cout << "Factorial " << num << " = " << fact(num) << endl;

    return 0;
}
