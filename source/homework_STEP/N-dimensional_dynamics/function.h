#include <iostream>
using namespace std;

void initRand(int* mas, int size)
{
    for (int i = 0; i < size; i++)
    {
        mas[i] = rand() % 100;
    }
}

void addRowAt(int**& mas, int& row, int col, int pos)
{
    if (mas != nullptr && pos >= 0 && pos < row)
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
            
            for (int i = 0, j = 0; i < row; i++)
            {
                if (i != pos)
                {
                    newMas[i] = mas[j];
                    j++;
                }
                else
                {
                    newMas[i] = new int[col];
                    initRand(newMas[i], col);
                }
            }

            delete[]mas;
            mas = newMas;
        }

    }
    else
    {
        cout << "ERROR" << endl;
        return;
    }
}

void addColAt(int**& mas, int row, int& col, int pos) 
{
	if (mas != nullptr && pos >= 0 && pos < col) 
    {
        if (mas != nullptr)
        {
		    col++;

		    for (int i = 0; i < row; i++) 
            {
			    int* newMas = new int[col];

			    for (int j = 0, k = 0; j < col; j++) 
                {
                    if (j != pos)
                    {
				        newMas[j] = mas[i][k];
                        k++;
                    }
                    else
                    {
                        newMas[j] = rand() % 100;
                    }
			    }
                
                if (col - 1 != 0) 
                {
				    delete[] mas[i];
			    }

                mas[i] = newMas;
		    }
        }
	}
    else
    {
        cout << "ERROR" << endl;
        return;
    }
}

void removeRow(int**& mas, int& row, int col)
{
    if (row == 1)
    {
        delete[]mas;
        return;
    }
    else if (mas != nullptr)
    {
        row--;
        int** newMas = new int*[row];

        for (int i = 0; i < row; i++)
        {
            newMas[i] = mas[i];
        }

        delete[]mas;
        mas = newMas;
    }
}

void removeCol(int**& mas, int row, int& col)
{
    if (col == 1)
    {
        int** newMas = new int*[row];

        for (int i = 0; i < row - 1; i++)
        {
            newMas[i] = mas[i];
        }

        delete[]mas;
        mas = newMas;
    }
    else
    {
        col--;

        for (int i = 0; i < row; i++)
        {
            int* newMas = new int[col];

            for (int j = 0; j < col; j++)
            {
			    newMas[j] = mas[i][j];

            }

			delete[]mas[i];
			mas[i] = newMas;
        }
    }
}

void removeRowAt(int**& mas, int& row, int col, int pos)
{
    if (row == 1 && pos == 0)
    {
        delete[]mas;
    }
    else if (mas != nullptr && pos >= 0 && pos < row)
    {
        row--;
        int** newMas = new int*[row];

        for (int i = 0, j = 0; i < row + 1; i++)
        {
            if (i != pos)
            {
                newMas[j] = mas[i];
                j++;
            }
        }

        delete[]mas;
        mas = newMas;
    }
    else
    {
        cout << "ERROR" << endl;
        return;
    }

}

void removeColAt(int**& mas, int row, int& col, int pos)
{
    if (col == 1)
    {
        int** newMas = new int*[row];

        for (int i = 0; i < row - 1; i++)
        {
            newMas[i] = mas[i];
        }

        delete[]mas;
        mas = newMas;
    }
    else if (col > 1 && pos >= 0 && pos < col)
    {
        col--;

        for (int i = 0; i < row; i++)
        {
            int* newMas = new int[col];

            for (int j = 0, k = 0; j < col + 1; j++)
            {
                if (j != pos)
                {
                    newMas[k] = mas[i][j];
                    k++;
                }
            }

            delete[]mas[i];
            mas[i] = newMas;
        }
    }
    else
    {
        cout << "ERROR >:[" << endl;
        return;
    }
}
