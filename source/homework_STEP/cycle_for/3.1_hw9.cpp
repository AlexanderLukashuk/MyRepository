#include <iostream>
using namespace std;
int main ()
{
    int num, num1, num2 = 0;

    cout << "Enter a number: ";
    cin >> num;

    for (int i = 10; i < num * 10; i *= 10)
    {
        num1 = num % i;
        if (i > 10)
        {
            num1 = (num % i) / (i / 10);
        }
        if (num1 == 3 || num1 == 6)
        {
            num1 = 0;
        }
        num2 = (num2 + num1) * 10;
    }
    num2 /= 10;
    for (int j = 10; j <= num2 * 10; j *= 10)
    {
        num1 = num2 % j;
        if (j > 10)
        {
            num1 = (num2 % j) / (j / 10);
        }
        cout << num1;
    }
    cout << endl;
    return 0;
}
