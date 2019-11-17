#include <iostream>
using namespace std;
int main ()
{
	long long worldPopul, usaPopul;
	double percent;
	
	cout << "Enter the world's population: ";
	cin >> worldPopul;
	cout << "Enter the population of the US: ";
	cin >> usaPopul;
	
	percent =  worldPopul / (usaPopul * 100);
	
	cout << "The population of the US is " << percent;
	cout << " % of the worl population\n";
	return 0;
}
