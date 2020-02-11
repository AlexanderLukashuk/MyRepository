#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 30;

int main()
{
    srand(time(0));
    int count_0 = 0, count_1 = 0;
    int array[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 2;
        if (array[i] == 0)
            count_0++;
        else
            count_1++;
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "count_0 = " << count_0 << endl;
    cout << "count_1 = " << count_1 << endl;
    cout << endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (count_1 > count_0 && array[i] == 1)
        {
            array[i] = 0;
            count_0++;
            count_1--;
        }
        else if (count_1 > count_0 / 2 && array[i] == 1)
        {
            array[i] = 0;
            count_0++;
            count_1--;
        }
    }
    cout << "count_0 = " << count_0 << endl;
    cout << "count_1 = " << count_1 << endl;
    
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
