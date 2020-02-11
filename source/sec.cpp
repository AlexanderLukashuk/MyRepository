#include <iostream>
using namespace std;
int main ()
{
	const int SecondPerMinute = 60;
	const int MinutePerHour = 60;
	const int HourPerDay = 24;
	long sec;
	int day, hour, minute, secNorm;
	
	cout << "Enter the number of seconds: ";
	cin >> sec;
	
	day = (sec / HourPerDay) / (MinutePerHour * SecondPerMinute);
	hour = (sec - (day * HourPerDay * MinutePerHour * SecondPerMinute)) / (MinutePerHour * SecondPerMinute);
	minute = ((sec - (day * HourPerDay * MinutePerHour * SecondPerMinute)) - (hour * MinutePerHour * SecondPerMinute)) / SecondPerMinute;
	secNorm = (sec - (day * HourPerDay * MinutePerHour * SecondPerMinute)) - (hour * MinutePerHour * SecondPerMinute ) - (minute * SecondPerMinute);

	cout << sec << " seconds = " << day << " days, " << hour << " hours, " << minute << " minutes, " << secNorm << " seconds\n";
	return 0;
}
