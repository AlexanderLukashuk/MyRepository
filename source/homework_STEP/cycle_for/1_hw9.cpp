#include <iostream>
using namespace std;
int main ()
{
    int num1, num2, num3;
    int count = 0;
    for (int i = 100; i <= 999; i++)
    {
        num1 = i % 10;
        num2 = i % 100 / 10;
        num3 = i / 100;
        if (num1 == num2)
        {
            count++;
        }
        else if (num1 == num3)
        {
            count++;
        }
        else if (num2 == num3)
        {
            count++;
        }
        else
        {
            continue;
        }
    }
    cout << "The number of numbers that have 2 identical digits = " << count << endl;
    return 0;
}
