#include <iostream>
int main ()
{
    using namespace std;
    int arr_sz;
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

    for (int j = 0; j < arr_sz; j++)
    {
        if (array[j] % 2 != 0)
            cout << array[j] << endl;;
    }

    delete [] array;
    return 0;
}
