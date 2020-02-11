#include <iostream>
using namespace std;

void func(int n, int& temp, int array[])
{
    if (n > 1)
    {
        array[temp] = n % 2;
        temp++;
        func(n / 2, temp, array);
    }
    else if (n % 2 == 1)
    {
        array[temp] = 1;
        temp++;
    }
    else if (n % 2 == 0)
    {
        array[temp] = 0;
        temp++;
    }
}

int main()
{
    int num, k = 0;
    int array[k];

    cout << "Enter a number: ";
    cin >> num;

    func(num, k, array);

    for (int i = k - 1; i >= 0; i--)
    {
        cout << array[i];
    }
    cout << endl;

    return 0;
}
