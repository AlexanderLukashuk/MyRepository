#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int array[size];
    int* parray = array;
    int sum = 0, element = 0;
    double percent;

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 50 + 5;
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        if (*(parray + i) % 5 == 0)
        {
            element++;
            sum += *(parray + i);
        }
    }

    percent = (double)(element * 100) / size;

    cout << "Sum of elements that are multiples of 5 = " << sum << endl;
    cout << "Number of elements multiples of 5 = " << element << endl;
    cout << "Percentage 0f multiples of 5 = " << percent << "%" << endl;

    return 0;
}
