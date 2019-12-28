#include <iostream>
using namespace std;
int main ()
{
    int N, m;

    cout << "Enter number of mowers: ";
    cin >> N;
    cout << "Enter the time that 1 mower worked: ";
    cin >> m;

    m *= 60;
    for (int i = 1; i <= N; i++)
    {
        m = m + ((i * 10) / i);
    }
    m /= 60;
    cout << "All work lasted " << m << endl;
    return 0;
}
