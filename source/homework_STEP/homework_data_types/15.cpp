#include <iostream>
using namespace std;
int main ()
{
    const long long x = 1024;
    const long long x2 = 8;
    int Gb;
    long long V, bit, hour, min, sec, t;

    cout << "Enter size of film in Gb: ";
    cin >> Gb;
    cout << "Enter speed in bit per second: ";
    cin >> V;

    bit = (Gb * x * x * x * x2);
    t = bit / V;
    hour = (t/60/60);
    min = ((t-(hour*60*60))/60);
    sec = (t - (hour * 60 * 60) - (min * 60));
    cout << "Your film downloaded: " << hour << ":" << min << ":" << sec << endl;
    return 0;
}
