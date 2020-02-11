#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

int main()
{
    srand(time(0));
    int array[SIZE];
    int* parray = array;
    int* pparray = &array[SIZE - 1];
    int sum = 0;

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 20;
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < SIZE / 2; i++)
    {
        if (i % 2 == 0)
        {
            sum += *(parray + i) + *(pparray - i - 1);
        }
    }
    sum -= *(parray + (SIZE / 2) - 1);
    cout << "Sum = " << sum << endl;

    return 0;
}
