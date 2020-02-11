#include <iostream>
#include <time.h>
using namespace std;

const int SIZE = 10;

void showArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void swapArray(int* parray, int size)
{
	int* pparray = parray + size - 1;
	for (int i = 0; i < size / 2; i++)
	{
		int temp = *(parray + i);
		*(parray + i) = *(pparray - i);
		*(pparray - i) = temp;
	}
}

int main()
{
	srand(time(0));
	int array[SIZE];
	int* parray = array;

	for (int i = 0; i < SIZE; i++)
	{
		array[i] = rand() % 10;
	}

	showArray(array, SIZE);
	swapArray(parray, SIZE);
	showArray(array, SIZE);

	return 0;
}
