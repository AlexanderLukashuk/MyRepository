#include <iostream>
using namespace std;

const int SIZE = 10;

int main ()
{
    int array[SIZE];

    cout << "Enter first number: ";
    cin >> array[0];
    cout << "Enter second number: ";
    cin >> array[1];

    for (int i = 1; i < SIZE - 1; i++)
    {
        array[i + 1] = array[i - 1] + array[i];
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
