#include <iostream>
using namespace std;

const int SIZE = 10;

int main ()
{
    int array[SIZE];
    int count_2 = 0, count_3 = 0, count_4 = 0, count_5 = 0;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter " << i + 1 << " your mark: ";
        cin >> array[i];
        while (array[i] < 2 || array[i] > 5)
        {
            cout << "You entered wrong mark\n";
            cout << "Pleas enter mark again: ";
            cin >> array[i];
        }
        switch (array[i])
        {
            case 2:
                count_2++;
                break;
            case 3:
                count_3++;
                break;
            case 4:
                count_4++;
                break;
            case 5:
                count_5++;
                break;
        }
    }

    cout << "number of 2 = " << count_2 << endl;
    cout << "number of 3 = " << count_3 << endl;
    cout << "number of 4 = " << count_4 << endl;
    cout << "number of 5 = " << count_5 << endl;

    return 0;
}
