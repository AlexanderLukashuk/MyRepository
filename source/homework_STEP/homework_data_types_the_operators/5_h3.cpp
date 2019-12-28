#include <iostream>
using namespace std;
int main()
{
	int S, gas_per_100, gas1, gas2, gas3, cost1, cost2, cost3;

	cout << "Enter distance: ";
	cin >> S;
	cout << "Enter gas consumption per 100 km: ";
	cin >> gas_per_100;
	cout << "Enter cost of AI-93: ";
	cin >> gas1;
	cout << "Enter cost of AI-80: ";
	cin >> gas2;
	cout << "Enter cost of AI-98: ";
	cin >> gas3;

	cost1 = S / 100;
	cost1 *= gas_per_100;
	cost1 *= gas1;
	cost2 = S / 100 * gas_per_100 * gas2;
	cost3 = S / 100 * gas_per_100 * gas3;

	cout << "Cost of trip using AI-93 = " << cost1 << endl;
	cout << "Cost of trip using AI-80 = " << cost2 << endl;
	cout << "Cost of trip using AI-98 = " << cost3 << endl;
	return 0;
}
