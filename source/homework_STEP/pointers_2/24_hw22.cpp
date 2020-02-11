#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

int main()
{
    srand(time(0));
    int array[SIZE];
    int* parray = array;
    int index_min, index_max;

    for (int i = 0; i < SIZE; i++)
    {
        *(parray + i) = rand() % 20;
        cout << *(parray + i) << " ";
    }
    cout << endl;

    int min = *(parray), max = *(parray);

    for (int i = 0; i < SIZE; i++)
    {
        if (min > *(parray + i))
        {
            min = *(parray + i);
            index_min = i;
        }

        if (max < *(parray + i))
        {
            max = *(parray + i);
            index_max = i;
        }
    }

    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;
    cout << "Index of min element = " << index_min << endl;
    cout << "Index of max element = " << index_max << endl;
    cout << "Number of min element = " << index_min + 1 << endl;
    cout << "Number of max element = " << index_max + 1 << endl;

    return 0;
}
