#include <iostream>
using namespace std;

void perfectNum(int array[], int num, int& count)
{
    int num1 = 0;
    for (int i = 1, j = 0; i < num; i++)
    {
        if (num % i == 0)
        {
            array[j] = i;
            count++;
            j++;
            num1 += i;
        }
    }

    if (num1 == num)
    {
        for (int i = 0; i < count; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "this is not a perfect number" << endl;
    }
}

int main()
{
    int num, count = 0;

    cout << "Enter a number: ";
    cin >> num;
    
    int array[count];

    perfectNum(array, num, count);

    return 0;
}
