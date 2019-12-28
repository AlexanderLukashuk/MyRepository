#include <iostream>
using namespace std;
int main ()
{
    int num, num2 = 100000, num3 = 0, num4;

    cout << "Enter a number in the range from 0 to 100000: ";
    cin >> num;
    num4 = num;

    if (num > 0 && num < 100000)
    {
        while (num2 != 0)
        {
            num4 = num / num2;
            if (num4 == 0)
            {
                while (num4 == 0)
                {
                    num2 /= 10;
                    num4 = num / num2;
                }
            }
            else if (num2 == 1)
            {
                num3 = (num % 10);
                cout << num3 << " ";
                num2 /= 10;
            }
            else
            {
                num3 = (num / num2) % 10;
                cout << num3 << " ";
                num2 /= 10;
            }
        }
    }
    else
    {
        cout << "You entered wrong number" << endl;
    }
    return 0;
}
