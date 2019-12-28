#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    int num1, num2, power = 2;

    cout << "Enter a number: ";
    cin >> num1;
    num2 = num1;

    while (power != 5)
    {
        num1 = pow(num2, power);
        cout << num2 << "in power of  " << power << " = " << num1 << endl;
        power++;
    }
    return 0;
}
