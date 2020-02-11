#include <iostream>
using namespace std;
int main ()
{
    const long long count = 1024;
    int KB, MB, GB, TB;
    long long bite;

    cout << "Enter amout of memory in bite: ";
    cin >> bite;

    TB = bite / count / count / count / count;
    GB = (bite - TB * count) / count / count / count;
    MB = ((bite - TB * count) - GB * count) / count / count;
    KB = (((bite - TB * count) - GB * count) - MB * count) / count;
    cout << "TB = " << TB << endl;
    cout << "GB = " << GB << endl;
    cout << "MB = " << MB << endl;
    cout << "KB = " << KB << endl;
    return 0;
}
