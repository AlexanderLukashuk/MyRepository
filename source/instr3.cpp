#include <iostream>
int main ()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	
	cout << "Enter your name:\n";
	cin.get(name, ArSize).get();
	cout << "Enter your favovorite dessert:\n";
	cin.get(dessert, ArSize).get();
	cout << "I have some delisious " << dessert;
	cout << " for you, " << name << ".\n";
	return 0;
}
