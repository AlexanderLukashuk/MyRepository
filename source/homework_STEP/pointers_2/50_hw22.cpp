#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    int N = rand() % 20 + 10;
    cout << "N = " << N << endl;

    int* array = new int[N];

    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 20;
        cout << array[i] << " ";
    }
    cout << endl;

    delete[]array;

    return 0;
}
