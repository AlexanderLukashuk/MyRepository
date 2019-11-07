#include <iostream>
#include <limits>
int main ()
{
	using namespace std;
	int maxInt = INT_MAX;
	int minInt = INT_MIN;
	long maxLong = LONG_MAX;
	long minLong = LONG_MIN;
	short maxShort = SHRT_MAX;
	short minShort = SHRT_MIN;
	char maxChar = (int)CHAR_MAX;
	char minChar = (int)CHAR_MIN;
	cout << "max int = " << maxInt << " and min int = " << minInt << endl;
	cout << "max long = " << maxLong << " and min long = " << minLong << endl;
	cout << "max short = " << maxShort << " and min short = " << minShort << endl;
	cout << "max char = " << maxChar << " and min char = " << minChar << endl;
	cout << "MAX = " << CHAR_MAX << endl;
	return 0;
}
