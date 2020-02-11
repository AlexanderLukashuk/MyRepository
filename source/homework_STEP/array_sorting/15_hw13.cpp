#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

int main()
{
	srand(time(0));
	double array[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		array[i] = (rand() % 10) * (i + 0.03);
		while (array[i] == 0)
		{
		if (array[i] == 0)
			array[i] = (rand() % 10) * (i + 0.03);
		}
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}
