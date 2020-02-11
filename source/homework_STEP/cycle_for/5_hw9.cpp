#include <iostream>
using namespace std;
int main ()
{
    int a, sum = 0, num;

    cout << "Enter a number: ";
    cin >> a;

    for (int i = 10; i < a * 10; i *= 10)
    {
        num = a % i;
        if (i > 10)
        {
            num = (a % i) / (i / 10);
        }
        sum += num;
    }
    if (sum * sum * sum == a * a)
    {
        cout << "the cube of the sum of the digits = " << sum * sum * sum << endl;
        cout << a << " * " << a << " = " << a * a << endl;
        cout << sum * sum * sum << " = " << a * a << endl;
    }
    else
    {
        cout << "the cube of the sum of the digits of this number is not  equal to ";
        cout << a << " * " << a << endl;
    }
    return 0;
}
