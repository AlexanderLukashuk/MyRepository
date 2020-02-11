#include <iostream>
#include <time.h>
using namespace std;

const int SIZE1 = 4;
const int SIZE2 = 4;

int main()
{
    srand(time(0));
    int array[SIZE1][SIZE2];
    int sum_line = 0, sum_col = 0, sum_all_line = 0;

    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            array[i][j] = rand() % 10;
            sum_line += array[i][j];
            cout << array[i][j] << "  ";
        }
        sum_all_line += sum_line;
        cout << " | " << sum_line << endl;
        sum_line = 0;
    }
    cout << "-----------------" << endl;

    for (int i = 0; i < SIZE2; i++)
    {
        for (int j = 0; j < SIZE1; j++)
        {
            sum_col += array[j][i];
        }
        cout << sum_col << " ";
        sum_col = 0;
    }
    cout << " | " << sum_all_line << endl;

    return 0;
}
