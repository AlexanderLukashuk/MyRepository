#include <iostream>
using namespace std;
int main ()
{
	using namespace std;
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "Monsieur cuts a striking fiqure!" << endl;
	cout << "chest = " << chest << " (decimal for 42)" << endl;
	cout << hex;
	cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
	cout << oct;
	cout << "inseam = " << inseam << " (octal dor 42)" << endl;
	return 0;
}