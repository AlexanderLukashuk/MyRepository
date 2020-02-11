#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

int main()
{
    srand(time(0));
    int array[SIZE];
    int* parray = array;
    int positive = 0, negative = 0;
    int percent_positive, percent_negative;

    for (int i = 0; i < SIZE; i++)
    {
        *(parray + i) = rand() % 45 - 20;
        cout << *(parray + i) << " ";
    }
    cout << endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (*(parray + i) > 0)
        {
            positive++;
        }
        else
        {
            negative++;
        }
    }

    percent_positive = (positive * 100) / SIZE;
    percent_negative = (negative * 100) / SIZE;

    cout << "Percent of positive number = " << percent_positive << "%" << endl;
    cout << "Percent of negative number = " << percent_negative << "%" << endl;

    return 0;
}
