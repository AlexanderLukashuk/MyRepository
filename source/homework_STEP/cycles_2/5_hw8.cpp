#include <iostream>
using namespace std;
int main ()
{
    int k, num = 1;

    cout << "Enter factor: ";
    cin >> k;

    for (int i = 0; i <= 10; i++)
    {
        num *= k * i;
        cout << k << " * " << i << " = " << num << endl;
        num = 1;
    }
    return 0;
}
