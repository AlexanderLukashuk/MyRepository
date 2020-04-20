#include <iostream>
#include <sstream>
using namespace std;

class TEST
{
private:
    int** mas;
    int size;
public:
    TEST()
    {
        size = 10;
        mas = new int*[size];
        for (int i = 0; i < size; i++)
        {
            mas[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                mas[i][j] = rand() % 10;
            }
        }
    }

    ~TEST()
    {
        for (int i = 0; i < size; i++)
        {
            delete[]mas[i];
        }
        delete[]mas;
    }

    string toString() const
    {
        stringstream ss;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                ss << mas[i][j] << endl;

            }
        }

        return ss.str();
    }

    /*int* operator[](int index)
    {
        return mas[index];
    }*/

    int*& operator[](int index)
    {
        return mas[index];
    }
};

int main()
{
    TEST test;
    cout << test.toString();
    cout << endl;

    //cout << test[0][0] << endl;
    test[5][6] = 99999;

    cout << test.toString();
}