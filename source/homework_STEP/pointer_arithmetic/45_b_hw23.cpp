#include <iostream>
#include <time.h>
using namespace std;

void initArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 20 + 1;
    }
}

template <typename T>
void showArray(T array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void delSpace(char str[], int& size)
{
    int count = 0, newSize;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }

    newSize = size - count;
    char newStr[newSize];

    for (int i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            newStr[j] = str[i];
            j++;
        }
    }

    for (int i = 0; i < newSize; i++)
    {
        str[i] = newStr[i];
    }
    str[newSize] = '\0';
    size = newSize;
}

template <typename T>
T* thirdArray(T A[], T B[], int size1, int size2)
{
    int size3, k = 0, count = 0;
    bool check = true;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (A[i] == B[j])
            {
                count += 2;
            }
        }
    }

    size3 = size1 + size2 - count;
    T* C = new T[size3];

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (A[i] == B[j])
            {
                check = false;
            }
        }

        if (check)
        {
            C[k] = A[i];
            k++;
        }
        check = true;
    }

    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size1; j++)
        {
            if (B[i] == A[j])
            {
                check = false;
            }
        }

        if (check)
        {
            C[k] = B[i];
            k++;
        }
        check = true;
    }

    showArray(C, size3);

    T* pC = C;

    return pC;

}

int main()
{
    srand(time(0));
    int M, N;

    cout << "Enter size of first array: ";
    cin >> M;
    cout << "Enter size of second array: ";
    cin >> N;

    int* arrayA = new int[M];
    int* arrayB = new int[N];
    char strA[100] = "you have come very fast";
    char strB[100] = "dad has come";
    int sizeM = strlen(strA), sizeN = strlen(strB);

    initArray(arrayA, M);
    initArray(arrayB, N);
    showArray(arrayA, M);
    showArray(arrayB, N);
    cout << thirdArray(arrayA, arrayB, M, N) << endl;
    cout << strA << endl;
    cout << strB << endl;
    delSpace(strA, sizeM);
    delSpace(strB, sizeN);
    cout << thirdArray(strA, strB, sizeM, sizeN) << endl;

    delete[]arrayA;
    delete[]arrayB;

    return 0;
}
