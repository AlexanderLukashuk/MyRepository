#include <iostream>
#include <time.h>
using namespace std;

const int SIZE1 = 10;
const int SIZE2 = 10;

int main()
{
    srand(time(0));
    int array[SIZE1][SIZE2];
    int sum = 0, average, min, max;

    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            array[i][j] = rand() % 10;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    min = array[0][0];
    max = array[0][0];
    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            sum += array[i][j];
            if (array[i][j] < min)
                min = array[i][j];

            if (array[i][j] > max)
                    max = array[i][j];
        }
    }

    average = sum / (SIZE1 * SIZE2);

    cout << "The amount = " << sum << endl;
    cout << "The average = " << average << endl;
    cout << "minimum element = " << min << endl;
    cout << "maximum element = " << max << endl;

    return 0;
}
