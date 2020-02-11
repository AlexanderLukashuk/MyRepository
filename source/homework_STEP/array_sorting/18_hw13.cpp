#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

int main()
{
    int num, num1 = 1, num2, num4;
    int size = 0;
    cout << "Enter a number: ";
    cin >> num;
    num2 = num;
    while (num2 != 0)
    {
        num2 = num;
        num2 /= num1;
        num1 *= 10;
        size++;
    }
    size = size - 1;
    int array[size];

    array[size - 1] = num % 10;
    num4 = num;
    num1 = 10;

    for (int i = size - 2; i >= 0; i--)
    {
        array[i] = (num4 / 10) % 10;
        num4 = num / num1;
        num1 *= 10;
    }

    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "  ";
    }
    cout << endl;
    
    return 0;
}
