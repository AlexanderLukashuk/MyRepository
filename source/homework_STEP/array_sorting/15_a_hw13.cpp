#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

const int SIZE = 10;

int main()
{
	double array[SIZE];
	int sign;

	cout << "Enter the number of decimal places: ";
	cin >> sign;

	for (int i = 0; i < SIZE; i++)
	{
		array[i] = rand() % 10 * ((i + 0.1) * (pow(0.1, sign - 1)));
		while (array[i] == 0)
		{
			if (array[i] == 0)
				array[i] = rand() % 10 * ((i + 0.1) * (pow(0.1, sign - 1)));
		}
		cout << array[i] << " ";
	}
    cout << endl;

    return 0;
}
