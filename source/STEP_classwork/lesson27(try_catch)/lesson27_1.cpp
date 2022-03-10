#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    while (true)
    {
        cout << "Enter 2 numbers: ";
        cin >> num1 >> num2;

        try
        {
            if (num2 == 0)
            {
                throw num2;
            }
            cout << "Result of devite operation = " << num1 / num2 << endl;
        }
        catch (int)
        {
            cout << "Devide by zero is uncorrect" << endl;
        }
    }
}