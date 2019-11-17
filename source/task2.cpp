#include <iostream>
int main ()
{
	using namespace std;
	int mas[32];
	
	int * pm = mas;
	
	for (int i; i < 32; i++)
	{
		cout << "Enter number for mas[" << i << "]: " << endl;
		cin >> mas[i];
	} 

	for (int j; j < 32; j++)
	{
		cout << (mas[0] + j) << endl;
	}
	return 0;
}
