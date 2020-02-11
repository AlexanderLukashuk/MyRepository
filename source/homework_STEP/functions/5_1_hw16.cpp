#include <iostream>
using namespace std;

void luckyTicket(int num)
{
    int num1, num2, num3, num4, num5, num6;
    int sum1, sum2;

    num1 = num / 100000;
    num2 = num / 10000 % 10;
    num3 = num / 1000 % 10;
    num4 = num / 100 % 10;
    num5 = num / 10 % 10;
    num6 = num % 10;

    sum1 = num1 + num2 + num3;
    sum2 = num4 + num5 + num6;

    if (sum1 == sum2)
    {
        cout << "It is lucky ticket" << endl;
    }
    else
    {
        cout << "It is not lucky ticket :(" << endl;
    }
}

int main()
{
    int num = 0;

    cout << "Enter a number: ";
    while (num < 100000 || num > 999999)
    {
        cin >> num;

        if (num < 100000 || num > 999999)
        {
            cout << "you entered wrong number" << endl;
            cout << "enter number again: ";
        }
    }

    luckyTicket(num);

    return 0;
}
