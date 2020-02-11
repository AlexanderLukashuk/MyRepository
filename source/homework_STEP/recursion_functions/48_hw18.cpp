#include <iostream>
using namespace std;

void func(int n)
{
    if (n == 1)
    {
        cout << "*";
    }
    else if (n > 1)
    {
        cout << "*";
        func(n - 1);
    }
}

int main()
{
    int N;

    cout << "Enter number of stars: ";
    cin >> N;

    func(N);
    cout << endl;

    return 0;
}
