#include <iostream>
using namespace std;
int main()
{
	const int work_time = 8;
	int sec, hour, time_left;

	cout << "Enter the time elapsed since the beginning of the working day in secunds: ";
	cin >> sec;

	hour = work_time - (sec / 60 / 60);
	cout << "Until the end of working day " << hour << " hour" << endl;
	return 0;
}
