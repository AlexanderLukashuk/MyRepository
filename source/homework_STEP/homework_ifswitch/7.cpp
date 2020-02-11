#include <iostream>
using namespace std;
int main ()
{
    int num1, num2, arith_operation, result;

    cout << "Enter first numbers: ";
    cin >> num1;
    cout << "Choose arithmetic operetion:" << endl;
    cout << "1)+ 2)- 3)* 4)/ 5)%" << endl;
    cin >> arith_operation;
    cout << "Enter second number: ";
    cin >> num2;

    if (arith_operation == 1)
    {
        result = num1 + num2;
        cout << num1 << " + " << num2 << " = " << result << endl;
    }
    else if (arith_operation == 2)
    {
        result = num1 - num2;
        cout << num1 << " - " << num2 << " = " << result << endl;
    }
    else if (arith_operation == 3)
    {
        result = num1 * num2;
        cout << num1 << " * " << num2 << " = " << result << endl;
    }
    else if (arith_operation == 4)
    {
        result = num1 / num2;
        cout << num1 << " / " << num2 << " = " << result << endl;
    }
    else if (arith_operation == 5)
    {
        result = num1 % num2;
        cout << num1 << " % " << num2 << " = " << result << endl;
    }
    else
    {
        cout << "You chose wrong operatin" << endl;
    }
    return 0;
}
