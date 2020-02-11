#include <iostream>
using namespace std;

int OddEven(int num)
{
    if (num % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << OddEven(num) << endl;

    return 0;
}
