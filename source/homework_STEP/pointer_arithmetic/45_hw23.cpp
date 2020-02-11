#include <iostream>
#include <time.h>
using namespace std;

void initArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
    }
}

void showArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    int M, N, count = 0, size, k = 0;
    bool check = true;
    cout << "Enter size for first array: ";
    cin >> M;
    cout << "Enter size for second array: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];
    
    initArray(A, M);
    initArray(B, N);
    showArray(A, M);
    showArray(B, N);

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (A[i] == B[j])
            {
                count += 2;
            }
        }
    }

    size = M + N - count;

    int* C = new int[size];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
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

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
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

    showArray(C, size);

    delete[]A;
    delete[]B;
    delete[]C;

    return 0;
}
