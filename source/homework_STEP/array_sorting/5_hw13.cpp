#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

int main ()
{
    srand(time(0));
    int array[SIZE];
    int max, min;

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 10;
        cout << array[i] << " ";
    }
    max = array[0];
    min = array[0];
    cout << endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] > max)
            max = array[i];
        
        if (min > array[i])
            min = array[i];
    }
    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;

    return 0;
}
