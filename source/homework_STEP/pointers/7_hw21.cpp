#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    int size, prime_num = 0, sum = 0, count = 0;
    double percent_primeNum;

    cout << "Enter size of array: ";
    cin >> size;

    int array[size];
    int* parray = array;

    for (int i = 0; i < size; i++)
    {
        *(parray + i) = rand() % 40;
        cout << *(parray + i) << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 2; j <= *(parray + i); j++)
        {
            if (*(parray + i) % j == 0)
            {
                count++;
            }
        }
        if (count == 1)
        {
            prime_num++;
            sum += *(parray + i);
            count = 0;
        }
        else
        {
            count = 0;
        }
    }

    percent_primeNum = (double)(prime_num * 100) / size;

    cout << "Number of prime numbers = " << prime_num << endl;
    cout << "The amount of prime numbers = " << sum << endl;
    cout << "Percent of prime numbers = " << percent_primeNum << "%" << endl;

    return 0;
}
