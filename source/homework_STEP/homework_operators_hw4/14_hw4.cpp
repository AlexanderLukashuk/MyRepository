#include <iostream>
using namespace std;
int main ()
{
    const double size_disk = 650;
    double GB, diskette, size;
    
    cout << "Enter size of film: ";
    cin >> GB;

    size = GB * 1024;
    diskette = size / size_disk;
    if ((int)diskette < diskette)
    {
        cout << "Need " << (int)diskette++ << " diskette" << endl;
    }
    else
    {
        cout << "Need " << (int)diskette << " diskette" << endl;
    }
    return 0;
}
