#include <iostream>
using namespace std;
int main()
{
	const int HOUR = 23;
	const int MIN = 59;
	const int SEC = 60;
	int hour, min, sec, hour2, min2, sec2;
	cout << "Enter time from the beginning of the day in seconds: ";
	cin >> sec;
	hour = sec / 60 / 60;
	sec -= hour * 60 * 60;
	min = sec / 60;
	sec -= min * 60;
	cout << "Now: " << hour << ":" << min << ":" << sec << endl;
	sec2 = SEC - sec;
	min2 = MIN - min;
	hour2 = HOUR - hour;
	if (sec2 > 59)
	{
		min2++;
		sec2 = 0;
	}
	if (min2 > 59)
	{
		hour2++;
		min2 = 0;
	}

	cout << "until midnight: " << hour2 << ":" << min2 << ":" << sec2 << endl;
	return 0;
}
