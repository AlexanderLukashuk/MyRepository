#include <iostream>
using namespace std;

int Sum(int argument1, int argument2)
{
    int sum = 0;

    if (argument1 < argument2)
    {
        for (int i = argument1; i <= argument2; i++)
        {
            sum += i;
        }
    }
    else
    {
        for (int i = argument2; i <= argument1; i++)
        {
            sum += i;
        }
    }

    return sum;
}

int main()
{
    int num1, num2;
    cout << "Enter firts number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    cout << "The amount = " << Sum(num1, num2) << endl;

    return 0;
}
