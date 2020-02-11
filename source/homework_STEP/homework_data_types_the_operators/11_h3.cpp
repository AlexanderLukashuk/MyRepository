#include <iostream>
using namespace std;
int main ()
{
    int num1, num2, num3, sum, comp, average;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter third number: ";
    cin >> num3;

    sum = num1 + num2 + num3;
    comp = num1 * num2 * num3;
    average = sum / 3;

    cout << "The amount = " << sum << endl;
    cout << "The composition = " << comp << endl;
    cout << "The average = " << average << endl;
    return 0;

}
