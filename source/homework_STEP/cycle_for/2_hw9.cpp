#include <iostream>
using namespace std;
int main ()
{
    int count = 0, num1, num2, num3;

    for (int i = 100; i <= 999; i++)
    {
        num1 = i % 10;
        num2 = i % 100 / 10;
        num3 = i / 100;
        if (num1 != num2 && num1 != num3 && num2 != num3)
        {
            count++;
        }
    }
    cout << "The number of numbers for which all digits are different = " << count;
    cout << endl;
    return 0;
}
