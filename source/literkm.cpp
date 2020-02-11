#include <iostream>
using namespace std;
int main ()
{
	double liter, km;
	double literPerKm;
	
	cout << "Enter number of liters: ";
	cin >> liter;
	cout << "Enter number of kilometrs: ";
	cin >> km;
	
	literPerKm = (liter / km) * 100;
	
	cout << "Liters per 100 kilometrs = " << literPerKm << endl;
	return 0;
}
