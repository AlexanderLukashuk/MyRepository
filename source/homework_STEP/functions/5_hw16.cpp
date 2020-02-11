#include <iostream>
using namespace std;

int luckyTicket()
{
    int num1, num2, num3, num4, num5, num6;
    int sum1, sum2, count = 0;
    for (int i = 100000; i < 1000000; i++)
    {
        num1 = i / 100000;
        num2 = i / 10000 % 10;
        num3 = i / 1000 % 10;
        num4 = i / 100 % 10;
        num5 = i / 10 % 10;
        num6 = i % 10;

        sum1 = num1 + num2 + num3;
        sum2 = num4 + num5 + num6;
        
        if (sum1 == sum2)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    cout << luckyTicket() << endl;

    return 0;
}
