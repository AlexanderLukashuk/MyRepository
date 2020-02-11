#include <iostream>
#include <time.h>
using namespace std;

void initArray(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % 5;
    }
}

void showArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int* subset(int* A, int* B, int size1, int size2)
{
    bool check;
    int x;
    for (int i = 0; i < size1; i++)
    {
        check = false;
        for (int j = 0; j < size2; j++)
        {
            if (*(B + j) == *(A + i))
            {
                for (int n = 0, m = i; n < size2; n++, m++)
                {
                    if (*(B + n) == *(A + m))
                    {
                        check = true;
                        x = i;
                    }
                    else
                    {
                        check = false;
                        x = 0;
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
        if (check)
        {
            break;
        }
    }

    if (check)
    {
        return (A + x);
    }
    else
    {
        return 0;
    }
}

int main()
{
    srand(time(0));
    int size1 = 6, size2 = 3;

    cout << "Enter size of first array: ";
    cin >> size1;
    cout << "Enter size of second array: ";
    cin >> size2;

    int* arrayA = new int[size1];
    int* arrayB = new int[size2];
    int* parrayA = arrayA;
    int* parrayB = arrayB;

    initArray(arrayA, size1);
    initArray(arrayB, size2);
    showArray(arrayA, size1);
    cout << endl;
    showArray(arrayB, size2);
    cout << endl;
    cout << subset(parrayA, parrayB, size1, size2) << endl;;

    delete[]arrayA;
    delete[]arrayB;

    return 0;
}
