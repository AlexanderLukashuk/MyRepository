#include <iostream>
using namespace std;

class Mas
{
    private:
        int size;
        int* data;
    public:
        Mas() : size(0), data(nullptr) {}

        ~Mas()
        {
            delete[] data;
        }

        void add(const int val)
        {
            if (data == nullptr)
            {
                size = 1;
                data = new int[size];
                data[0] = val;
            }
            else
            {
                size++;
                int* newData = new int[size];

                for (int i = 0; i < size - 1; i++)
                {
                    newData[i] = data[i];
                }
                newData[size - 1] = val;
                delete[]data;
                data = newData;
            }
        }

        void insert(const int val, const int pos)
        {
            if (data != nullptr && pos < size && pos > 0)
            {
                size++;
                int* newData = new int[size];

                for (int i = 0, j = 0; i < size; i++)
                {
                    if (i == pos)
                    {
                        newData[i] = val;
                    }
                    else
                    {
                        newData[i] = data[j];
                        j++;
                    }
                }

                delete[]data;
                data = newData;
            }
            else if (data == nullptr && pos == 0)
            {
                add(val);
            }
            else
            {
                return;
                //cout << "You entered wrong position" << endl;
            }
        }

        void remove()
        {
            if (data == nullptr)
            {
                return;
                //cout << "Array is empty" << endl;
            }
            else if (size == 1)
            {
                size--;
                delete[]data;
            }
            else
            {
                size--;
                int* newData = new int[size];

                for (int i = 0; i < size; i++)
                {
                    newData[i] = data[i];
                }

                delete[]data;
                data = newData;
            }
        }

        void removeAt(const int pos)
        {
            if (data == nullptr)
            {
                return;
                //cout << "Array is empty" << endl;
            }
            else if (size == 1 && pos < size && pos > 0)
            {
                size--;
                data = nullptr;
            }
            else if (size == 1 && pos == 0)
            {
                remove();
            }
            else if (pos < size && pos > 0)
            {
                size--;
                int* newData = new int[size];

                for (int i = 0, j = 0; i < size + 1; i++)
                {
                    if (i != pos)
                    {
                        newData[j] = data[i];
                        j++;
                    }
                }
            }
        }

        void show() const
        {
            if (data == nullptr)
            {
                return;
                //cout << "Array is empty" << endl;
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    cout << data[i] << " ";
                }
                cout << endl;
            }
        }

        int getSize() const
        {
            return size;
        }

        void showAdress()
        {
            cout << "size: " << &size << " | " << size << endl;
            cout << "data: " << &data << " | " << data << endl;
        }
};

void func(Mas m)
{
    cout << "Mas m: \n";
    m.showAdress();
    cout << endl;
}

int main()
{
    Mas mas;

    mas.add(1);
    mas.add(2);
    mas.add(3);

    cout << "Mas mas: \n";
    mas.showAdress();
    cout << endl;

    func(mas);
    // mas.show();
    // cout << endl;

    // func(mas);

    // mas.remove();
    // mas.show();
    // cout << endl;

    // mas.insert(2, 100);
    // mas.show();
    // cout << endl;

    // mas.insert(0, 1);
    // mas.show();
    // cout << endl;

    // mas.removeAt(0);
    // mas.show();
    // cout << endl;

    return 0;
}