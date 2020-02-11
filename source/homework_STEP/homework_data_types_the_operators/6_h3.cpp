#include <iostream>
using namespace std;
int main()
{
	double gas_per_100, money, gas1, gas2, gas3, S1, S2, S3;

	cout << "Enter amount of your money in hryvnias: ";
	cin >> money;
	cout << "Enter gas consumption per 100 km: ";
	cin >> gas_per_100;
	cout << "Enter cost of AI-93: ";
	cin >> gas1;
	cout << "Enter cost of AI-80: ";
	cin >> gas2;
	cout << "Enter cost of AI-98: ";
	cin >> gas3;

	S1 = money / (gas_per_100 * gas1);
	S2 = money / (gas_per_100 * gas2);
	S3 = money / (gas_per_100 * gas3);

	cout << "you can leave for " << S1 << " using AI-93" << endl;
	cout << "you can leave for " << S2 << " using AI-80" << endl;
	cout << "you can leave for " << S3 << " using AI-98" << endl;

	return 0;
}
