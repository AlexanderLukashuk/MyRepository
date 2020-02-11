#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    int N, mark2 = 0, mark3 = 0, mark4 = 0, mark5 = 0;
    double percent2, percent3, percent4, percent5;

    cout << "Enter size of array: ";
    cin >> N;

    int array[N];
    int* parray = array;

    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 11 + 1;
        cout << array[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < N; i++)
    {
        switch(*(parray + i))
        {
            case 1:
            case 2:
            case 3:
                mark2++;
                break;
            case 4:
            case 5:
            case 6:
                mark3++;
                break;
            case 7:
            case 8:
            case 9:
                mark4++;
                break;
            case 10:
            case 11:
            case 12:
                mark5++;
                break;
        }
    }

    percent2 = (double)(mark2 * 100) / N;
    percent3 = (double)(mark3 * 100) / N;
    percent4 = (double)(mark4 * 100) / N;
    percent5 = (double)(mark5 * 100) / N;

    cout << "Percent of twos = " << percent2 << "%" << endl;
    cout << "Percent of triples = " << percent3 << "%" << endl;
    cout << "Percent of fours = " << percent4 << "%" << endl;
    cout << "Percent of fives = " << percent5 << "%" << endl;
    cout << "Number of twos = " << mark2 << endl;
    cout << "Number of triples = " << mark3 << endl;
    cout << "Number of fours = " << mark4 << endl;
    cout << "Number of fives = " << mark5 << endl;

    return 0;
}
