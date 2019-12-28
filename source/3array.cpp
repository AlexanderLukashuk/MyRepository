#include <iostream>
int main ()
{
    using namespace std;
    int arr_sz;
    int j, m;
    int countEven;
    int countOdd;
    int * evenArray;
    int * oddArray;
    int * array;

    cout << "Enter array size: ";
    cin >> arr_sz;

    array = new int[arr_sz];

    for (int i = 0; i < arr_sz; i++)
    {
        cout << "Enter " << i + 1 << " value: ";
        cin >> array[i];
        cout << "array[" << i << "] = " << array[i] << endl;
    }

    cout << endl;
    cout << endl;

    for (j = 0; j < arr_sz; j++)
    {
        if (array[j] % 2 == 0)
            countEven++;
        else
            countOdd++;
    }

    evenArray = new int[countEven];
    oddArray = new int[countOdd];

    for (int i = 0, m = 0, n= 0; i < arr_sz; i++)
    {
        if (array[i] % 2 == 0)
        {
            evenArray[m] = array[i];
            m++;
        }
        else 
        {
            oddArray[n] = array[i];
            n++;
        }
    }

    cout << endl;
    cout << endl;

    for (int i = 0; i < countEven; i++)
        cout << evenArray[i] << endl;

    cout << endl;
    cout << endl;

    for (int j = 0; j < countOdd; j++)
        cout << oddArray[j] << endl;
        

    delete [] evenArray;
    delete [] oddArray;
    delete [] array;
    return 0;
}
