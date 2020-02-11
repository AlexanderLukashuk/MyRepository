#include <iostream>
using namespace std;

void numbers(int argum1, int argum2, int argum3)
{
    for (int i = 0; i <= 1000; i++)
    {
        if (i % argum1 == 0 && i % argum2 == 0 && i && argum3 == 0)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int num1, num2, num3;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter third number: ";
    cin >> num3;

    numbers(num1, num2, num3);

    return 0;
}
