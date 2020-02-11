#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 5;

int main()
{
    srand(time(0));
    int array[SIZE][SIZE];
    int A, B, sum = 0;

    cout << "Enter first number: ";
    cin >> A;
    cout << "Enter second number: ";
    cin >> B;

    if (B > A)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                array[i][j] = A + (rand() % 10);
                while (array[i][j] > B)
                {
                    array[i][j] = A + (rand() % 10);
                }
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                array[i][j] = B + (rand() % 10);
                while (array[i][j] > A)
                {
                    array[i][j] = B + (rand() % 10);
                }
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        sum += array[i][0 + i];
    }

    for (int i = SIZE; i > 0; i--)
    {
        sum += array[i - 1][SIZE - i];
    }
    cout << "Sum = " << sum << endl;

    return 0;
}
