#include <iostream>
#include <vector>
using namespace std;
#ifdef _WIN32
#define cls() system("cls")
#else
#define cls() system("clear")
#endif
#ifdef _WIN32
#define pause() system("pause");
#else
#define pause()                           \
    cout << "Press enter to continue..."; \
    cin.get();
#endif

template <class T>
class Vector
{
private:
    T *data;
    int _size;

public:
    Vector() : data(nullptr), _size() {}
    Vector(int _size) : data(nullptr), _size()
    {
        if (_size > 0)
        {
            for (int i = 0; i < _size; i++)
            {
                data[i] = 0;
            }

            this->_size = _size;
        }
    }

    Vector(const Vector &vec)
    {
        if (vec.data != nullptr)
        {
            data = new T[vec._size];
            for (int i = 0; i < vec._size; i++)
            {
                data[i] = vec.data[i];
            }

            this->_size = vec._size;
        }
    }
    Vector(Vector &&vec)
    {
        data = vec.data;
        vec.data = nullptr;

        this->_size = vec._size;
    }

    ~Vector()
    {
        if (data != nullptr)
        {
            while (_size)
            {
                pop();
            }
        }
    }

    void push_back(const T &value)
    {
        _size++;
        if (data != nullptr)
        {
            T *newData = new T[this->_size];
            for (int i = 0; i < _size - 1; i++)
            {
                newData[i] = data[i];
            }

            newData[_size - 1] = value;

            delete[] data;
            data = newData;
        }
        else
        {
            data = new T[_size];
            data[0] = value;
        }
    }
    void push_front(const T &value)
    {
        _size++;
        if (data != nullptr)
        {
            T *newData = new T[this->_size];
            newData[0] = value;
            for (int i = 0, j = 1; i < _size - 1; i++)
            {
                newData[j] = data[i];
                j++;
            }

            delete[] data;
            data = newData;
        }
        else
        {
            data = new T[_size];
            data[0] = value;
        }
    }

    void pop()
    {
        _size--;
        if (_size + 1 > 1)
        {
            T *newData = new T[_size];
            for (int i = 0; i < _size; i++)
            {
                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
        }
        else if (_size + 1 == 1)
        {
            delete[] data;
            data = nullptr;
        }
    }

    const T &top()
    {
        return data[0];
    }

    T &operator[](int pos)
    {
        return data[pos];
    }

    void clear()
    {
        while (_size)
        {
            pop();
        }
    }

    int size()
    {
        return _size;
    }

    bool empty()
    {
        return _size == 0;
    }

    void show()
    {
        for (int i = 0; i < _size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    } // 1 2 3 4 2 3 5 8
};

template <>
void Vector<bool>::show() // true true false flase true
{
    for (int i = 0; i < _size; i++)
    {
        if (data[i] == true)
        {
            cout << "1"
                 << " ";
        }
        else if (data[i] == false)
        {
            cout << "0"
                 << " ";
        }
    }
    cout << endl;
}

template <>
class Vector<char>
{
private:
    char *data;
    int lenght;

public:
    Vector() : data(nullptr), lenght() {}
    Vector(const char *str) : data(nullptr), lenght()
    {
        if (str != nullptr)
        {
            lenght = strlen(str) + 1;
            data = new char[lenght + 1];
            strcpy(data, str);
        }
    }

    Vector(const Vector &vec)
    {
        if (vec.data != nullptr)
        {
            lenght = vec.lenght;
            data = new char[lenght];
            for (int i = 0; i < lenght; i++)
            {
                data[i] = vec.data[i];
                //strcpy(this->data, vec.data);
            }
        }
    }

    Vector(Vector &&vec)
    {
        if (vec.data != nullptr)
        {
            this->data = vec.data;
            vec.data = nullptr;

            this->lenght = vec.lenght;
        }
    }

    ~Vector()
    {
        if (data != nullptr)
        {
            while (lenght)
            {
                lenght--;
                if (lenght + 1 > 1)
                {
                    char *newData = new char[lenght];
                    for (int i = 0; i < lenght; i++)
                    {
                        newData[i] = data[i];
                    }

                    delete[] data;
                    data = newData;
                }
                else if (lenght + 1 == 1)
                {
                    delete[] data;
                    data = nullptr;
                }
            }
        }
    }

    void operator=(const Vector<char> &vec)
    {
        if (vec.data != nullptr)
        {
            this->lenght = vec.lenght;
            data = new char[lenght];
            for (int i = 0; i < lenght; i++)
            {
                data[i] = vec.data[i];
                //strcpy(this->data, vec.data);
            }
        }
    }

    void operator=(const char *str)
    {
        if (str != nullptr)
        {
            this->lenght = strlen(str) + 1;
            data = new char[lenght];
            strcpy(data, str);
        }
    }

    //const Vector<char>& operator+(const Vector<char> vec) {}
    //const Vector<char>& operator+(const char* str) {}

    const Vector<char> &operator+=(const Vector<char> vec)
    {
        if (vec.data != nullptr)
        {
            char *tmp = new char[lenght];
            for (int i = 0; i < lenght; i++)
            {
                tmp[i] = data[i];
            }
            strcat(tmp, vec.data);

            this->lenght = lenght + vec.lenght;
            data = new char[lenght];
            for (int i = 0; i < lenght; i++)
            {
                data[i] = tmp[i];
            }

            delete[] tmp;

            return *this;
        }
    }

    const Vector<char> &operator+=(const char *str)
    {
        if (str != nullptr)
        {
            char *tmp = new char[lenght];
            for (int i = 0; i < lenght; i++)
            {
                tmp[i] = data[i];
            }
            strcat(tmp, str);

            this->lenght = lenght + strlen(str) + 1;
            data = new char[lenght];
            for (int i = 0; i < lenght; i++)
            {
                data[i] = tmp[i];
            }

            delete[] tmp;

            return *this;
        }
    }

    bool operator==(const Vector<char> vec)
    {
        if (vec.data != nullptr)
        {
            if (this->lenght != vec.lenght)
            {
                return false;
            }
            else
            {
                for (int i = 0; i < lenght; i++)
                {
                    if (data[i] != vec.data[i])
                    {
                        return false;
                    }
                }
                return true;
            }
        }
    }

    bool operator==(const char *str)
    {
        if (str != nullptr)
        {
            if (this->lenght != (strlen(str) + 1))
            {
                return false;
            }
            else
            {
                for (int i = 0; i < lenght; i++)
                {
                    if (data[i] != str[i])
                    {
                        return false;
                    }
                }
                return true;
            }
        }
    }

    const char const *getStr()
    {
        return data;
    }
};

int main()
{
    Vector<char> vec("Hello");
    Vector<char> vec2;
    vec2 = vec;

    cout << "Vec: " << vec.getStr() << endl;
    cout << "Vec 2: " << vec2.getStr() << endl;

    vec2 = "Good morning";

    cout << "Vec 2: " << vec2.getStr() << endl;

    vec2 += vec;

    cout << "Vec: " << vec.getStr() << endl;
    cout << "Vec 2: " << vec2.getStr() << endl;

    vec2 += " Bad day";

    cout << "Vec 2: " << vec2.getStr() << endl;

    cout << (vec2 == vec) << endl;

    Vector<char> vec3("Night");
    Vector<char> vec4("Night");

    cout << (vec3 == vec4) << endl;

    cout << endl;
    cout << (vec3 == "Day") << endl;
    cout << (vec3 == "Night") << endl;
    cout << (vec3 == "Naght") << endl;



    /*Vector<bool> vec;

    vec.push_back(true);
    vec.push_back(true);
    vec.push_back(false);
    vec.push_back(true);
    vec.push_back(false);

    vec.show();*/

    /*Vector<int> vec;
    
    cout << "Empty? " << vec.empty() << endl;
    cout << "Size = " << vec.size() << endl;

    vec.push_back(8);
    vec.push_back(45);
    vec.push_back(415);
    vec.push_back(3);

    vec.show();

    cout << "Empty? " << vec.empty() << endl;
    cout << "Size = " << vec.size() << endl;

    vec.push_front(75);
    vec.push_front(21);
    vec.push_front(17);
    vec.push_front(67);

    vec.show();

    vec.pop();
    vec.pop();
    vec.pop();
    vec.pop();
    vec.pop();

    vec.show();

    cout << "Empty? " << vec.empty() << endl;
    cout << "Size = " << vec.size() << endl;

    cout << "Top = " << vec.top() << endl;

    vec.push_back(43);
    vec.push_back(65);
    vec.push_front(40);
    vec.push_front(27);

    cout << "Top = " << vec.top() << endl;

    vec.show();

    vec[0] = 888;
    cout << "vec[5] = " << vec[5] << endl;

    vec.show();

    cout << "Top = " << vec.top() << endl;

    vec.clear();

    cout << "Empty? " << vec.empty() << endl;
    cout << "Size = " << vec.size() << endl;

    pause();*/
}