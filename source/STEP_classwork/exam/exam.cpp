#include <iostream>
#include <array>
using namespace std;

template <class T, int _size>
class Array
{
private:
    T *data;

public:
    Array()
    {
        //data = new T[_size]{};
        data = new T[_size];

        for (int i = 0; i < _size; i++)
        {
            data[i] = T();
        }
    }

    Array(initializer_list<T> list)
    {
        //data = new T[_size]{};
        data = new T[_size];

        for (int i = 0; i < _size; i++)
        {
            data[i] = T();
        }

        int tmp = 0;
        for (auto el : list)
        {
            data[tmp] = el;
            tmp++;
        }
    }

    Array(const Array<T, _size> &arr)
    {
        if (arr.data != nullptr)
        {
            data = new T[arr.size()]{};
            for (int i = 0; i < arr.size(); i++)
            {
                data[i] = arr.data[i];
            }
        }
    }

    Array(Array<T, _size> &&arr)
    {
        if (arr.data != nullptr)
        {
            data = new T[arr.size()]{};
            for (int i = 0; i < arr.size(); i++)
            {
                data[i] = arr.data[i];
            }
            delete[] arr;
            arr = nullptr;
        }
    }

    ~Array()
    {
        if (data != nullptr)
        {
            delete[] data;
        }
    }

    T &operator[](int pos)
    {
        return data[pos];
    }

    Array<T, _size> &operator=(const Array<T, _size> &arr)
    {
        if (arr.data != nullptr)
        {
            if (this->data != nullptr)
            {
                delete[] data;
                data = nullptr;
            }

            this->data = new T[arr.size()]{};
            for (int i = 0; i < arr.size(); i++)
            {
                data[i] = arr.data[i];
            }
        }

        return *this;
    }

    Array<T, _size> operator=(Array<T, _size> &&arr)
    {
        if (arr.data != nullptr)
        {
            if (this->data != nullptr)
            {
                delete[] data;
                data = nullptr;
            }

            data = new T[arr.size()]{};
            for (int i = 0; i < arr.size(); i++)
            {
                data[i] = arr.data[i];
            }
            delete[] arr;
            arr = nullptr;
        }

        return *this;
    }

    Array<T, _size> operator=(initializer_list<T> list)
    {
        int tmp = 0;
        for (auto el : list)
        {
            data[tmp] = el;
            tmp++;
        }

        return *this;
    }

    int size() const
    {
        return _size;
    }

    void swap(Array<T, _size> &arr)
    {
        for (int i = 0; i < _size; i++)
        {
            auto tmp = arr.data[i];
            arr.data[i] = this->data[i];
            this->data[i] = tmp;
        }
    }
};

int main()
{
    Array<int, 8> arr = {8, 5, 3, 10};
    Array<int, 8> arr2;
    cout << arr[0] << " " << arr[1] << endl;
    cout << arr.size() << endl;

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr2 = arr;

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    arr2 = {8, 54, 671, 584};

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << arr2.size() << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    arr.swap(arr2);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;


    //array<int, 4> arr;
}