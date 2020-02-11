#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    int size, positive = 0, negative = 0, sum = 0;
    int sum_positive = 0, sum_negative = 0;
    double percent_positive, percent_negative;

    cout << "Enter size of array: ";
    cin >> size;

    int array[size];
    int* parray = array;

    for (int i = 0; i < size; i++)
    {
        *(parray + i) = rand() % 20 - 10;
        cout << *(parray + i) << " ";
        sum += *(parray + i);
    }
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        if (*(parray + i) > 0)
        {
            positive++;
            sum_positive += *(parray + i);
        }
        else
        {
            negative++;
            sum_negative += *(parray + i);
        }
    }

    percent_positive = (double)(positive * 100) / size;
    percent_negative = (double)(negative * 100) / size;

    cout << "Number of positive numbers = " << positive << endl;
    cout << "number of negative numbers = " << negative << endl;
    cout << "The total amount = " << sum << endl;
    cout << "The amount of positive numbers = " << sum_positive << endl;
    cout << "The amount of negative numbers = " << sum_negative << endl;
    cout << "Percent of positive numbers = " << percent_positive << "%" << endl;
    cout << "Percent of negative numbers = " << percent_negative << "%" << endl;

    return 0;
}
