#include <iostream>
int main ()
{
    using namespace std;
    int arr_sz;
    int temp;
    int * array;

    cout << "Enter array size: ";
    cin >> arr_sz;

    array = new int[arr_sz];

    for (int i = 0; i < arr_sz; i++)
    {
        cout << "Enter " << i << " value: ";
        cin >> array[i];
        cout << "array[" << i << "] = " << array[i] << endl;
    }

    cout << endl;
    cout << endl;

    for (int j = 0; j < arr_sz/2; j++)
    {
        temp = array[arr_sz - 1 - j];
        array[arr_sz - 1 - j] = array[0 + j];
        array[0 + j] = temp;
    }
    
    for (int m = 0; m < arr_sz; m++)
        cout << "array[" << m << "] = " << array[m] << endl;

    delete [] array;
    return 0;
}
