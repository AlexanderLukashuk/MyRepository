#include <iostream>
#include <time.h>
#include "function.h"
using namespace std;

void initArray(int** mas, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			mas[i][j] = rand() % (48 - 25) + 25;
		}
	}
}

void showArray(int** mas, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void addRow(int**& mas, int& row, int col)
{
	if (row == 0)
	{
		row = 1;
		mas = new int* [row];
	}
	else
	{
		row++;
		int** newMas = new int* [row];

		for (int i = 0; i < row - 1; i++)
		{
			newMas[i] = mas[i];
		}
	
		newMas[row - 1] = new int[col];
		initRand(newMas[row - 1], col);
		delete[]mas;
		mas = newMas;
	}

}

void addCol(int**& mas, int row, int& col)
{
	if (mas != nullptr)
	{
		col++;

		for (int i = 0; i < row; i++)
		{
			int * tmp = new int[col];
			for (int j = 0; j < col - 1; j++)
			{
				tmp[j] = mas[i][j];
			}
			tmp[col - 1] = rand() % 100;
			if (col - 1 != 0)
			{
				delete[]mas[i];
			}
			mas[i] = tmp;
		}
	}

}

int main()
{
	srand(time(0));

	int row = 0;
	int col = 0;
    int option = 0, index;

	int** mas = nullptr;

    while (option != 10)
    {
        cout << "Choose option: " << endl;
        cout << "1)Show array" << endl;
        cout << "2)Add row" << endl;
        cout << "3)Add col" << endl;
        cout << "4)Add row at" << endl;
        cout << "5)Add col at" << endl;
        cout << "6)Remove row" << endl;
        cout << "7)Remove col" << endl;
        cout << "8)Remove row at" << endl;
        cout << "9)Remove col at" << endl;
        cout << "10)Exit" << endl;
        cin >> option;

        switch (option)
        {
            case 1:
                showArray(mas, row, col);
                break;
            case 2:
	            addRow(mas, row, col);
                break;
            case 3:
	            addCol(mas, row, col);
                break;
            case 4:
                cout << "Enter the position where you would like to add a row: ";
                cin >> index;
                index--;
                addRowAt(mas, row, col, index);
                break;
            case 5:
                cout << "Enter the position where you would like to add a col: ";
                cin >> index;
                index--;
                addColAt(mas, row, col, index);
                break;
            case 6:
                removeRow(mas, row, col);
                break;
            case 7:
                removeCol(mas, row, col);
                break;
            case 8:
                cout << "Enter the position of row which want delete: ";
                cin >> index;
                index--;
                removeRowAt(mas, row, col, index);
                break;
            case 9:
                cout << "Enter the position of col which you want delete: ";
                cin >> index;
                index--;
                removeColAt(mas, row, col, index);
                break;
            case 10:
                cout << "Bye" << endl;
                break;
            default:
                cout << "You chose wrong option" << endl;
                cout << "Try again" << endl;
                break;
        }
    }

	for (int i = 0; i < row; i++) 
	{
		delete[] mas[i];
	}
	delete[] mas;

    return 0;
}
