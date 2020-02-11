#include <iostream>
#include <time.h>
using namespace std;

const int ROW = 12;
const int COL = 12;

int main()
{
    srand(time(0));
    int array[ROW][COL];
    int count_0 = 0, count_1 = 0;
    int single_island = 0;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            array[i][j] = rand() % 2;
            if (array[i][j] == 0)
                count_0++;
            else
                count_1++;
        }
    }

    while (count_1 != count_0 / 3)
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (count_1 > count_0 && array[i][j] == 1)
                {
                    array[i][j] = rand() % 2;
                    count_0++;
                    count_1--;
                }
                else if (count_1 > count_0 / 3 && array[i][j] == 1)
                {
                    array[i][j] = rand() % 2;
                    count_0++;
                    count_1--;
                }
            }
        }
    }
    cout << "count_0 = " << count_0 << endl;
    cout << "count_1 = " << count_1 << endl;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (array[i][j] == 1)
            {
                if (j == 0 && i == 0)
                {
                    if (array[i + 1][j] != 1 &&
                        array[i][j + 1] != 1 &&
                        array[i + 1][j + 1] != 1)
                    {
                        single_island++;
                    }
                }
                else if (j == 0 && i == ROW - 1)
                {
                    if (array[i - 1][j] != 1     &&
                        array[i - 1][j + 1] != 1 &&
                        array[i][j + 1] != 1)
                    {
                        single_island++;
                    }
                }
                else if (j == COL - 1 && i == 0)
                {
                    if (array[i][j - 1] != 1 &&
                        array[i + 1][j] != 1 &&
                        array[i + 1][j - 1] != 1)
                    {
                        single_island++;
                    }
                }
                else if (j == COL - 1 && i == ROW - 1)
                {
                    if (array[i - 1][j - 1] != 1 &&
                        array[i - 1][j] != 1     &&
                        array[i][j - 1] != 1)
                    {
                        single_island++;
                    }
                }
                else if (j == 0)
                {
                    if (array[i - 1][j + 1] != 1 &&
                        array[i - 1][j] != 1     &&
                        array[i][j + 1] != 1     &&
                        array[i + 1][j + 1] != 1 &&
                        array[i + 1][j] != 1)
                    {
                        single_island++;
                    }
                }
                else if (j == COL - 1)
                {
                    if (array[i - 1][j - 1] != 1 &&
                        array[i - 1][j] != 1     &&
                        array[i][j - 1] != 1     &&
                        array[i + 1][j - 1] != 1 &&
                        array[i + 1][j] != 1)
                    {
                        single_island++;
                    }
                }
                else if (i == 0)
                {
                    if (array[i][j - 1] != 1     &&
                        array[i][j + 1] != 1     &&
                        array[i + 1][j - 1] != 1 &&
                        array[i + 1][j] != 1     &&
                        array[i + 1][j + 1] != 1)
                    {
                        single_island++;
                    }
                }
                else if (i == ROW - 1)
                {
                    if (array[i][j - 1] != 1     &&
                        array[i - 1][j - 1] != 1 &&
                        array[i - 1][j] != 1     &&
                        array[i - 1][j + 1] != 1 &&
                        array[i][j + 1] != 1)
                    {
                        single_island++;
                    }
                }
                else if (array[i - 1][j - 1] != 1 &&
                         array[i - 1][j] != 1     &&
                         array[i - 1][j + 1] != 1 &&
                         array[i][j - 1] != 1     &&
                         array[i][j + 1] != 1     &&
                         array[i + 1][j - 1] != 1 &&
                         array[i + 1][j] != 1     &&
                         array[i + 1][j + 1] != 1)
                {
                    single_island++;
                }
            }
        }
    }
    cout << "Number of single island = " << single_island << endl;

    return 0;
}
