#include <iostream>
using namespace std;

template <class T>
class Element
{
public:
    T data;
    Element<T> *next;
    Element() : next(nullptr), data() {}
    Element(const T &data) : next(nullptr), data(data) {}
};

template <class T>
class ForwardList
{
private:
    Element<T> *head;
    Element<T> *tail;
    int _size;

public:
    ForwardList() : head(nullptr), tail(nullptr), _size() {}
    ForwardList(const ForwardList<T> &obj)
    {
        if (obj.head != nullptr)
        {
            Element<T> *tmp = obj.head;
            while (tmp != nullptr)
            {
                push(tmp->data);
                tmp = tmp->next;
            }
        }
    }

    ForwardList(const ForwardList<T> &&obj)
    {
        head = obj.head;
        obj.head = nullptr;

        tail = obj.tail;
        obj.tail = nullptr;

        _size = obj._size;
    }

    ~ForwardList()
    {
        /*Element<T>* tmp = head;
        while(tmp != nullptr)
        {
            tmp = tmp->next;
            delete head;
            head = tmp;
        }*/

        while (_size)
        {
            pop();
        }
    }

    void operator=(const ForwardList<T> &obj)
    {
        clear();

        if (obj.head != nullptr)
        {
            Element<T> *tmp = obj.head;
            while (tmp != nullptr)
            {
                push(tmp->data);
                tmp = tmp->next;
            }
        }
    }

    void operator=(const ForwardList<T> &&obj)
    {
        clear();

        head = obj.head;
        obj.head = nullptr;

        tail = obj.tail;
        obj.tail = nullptr;

        _size = obj._size;
    }

    T &operator[](int pos)
    {
        Element<T> *tmp = head;

        for (int i = 0; i < _size; i++)
        {
            if (i == pos)
            {
                return tmp->data;
            }
            tmp = tmp->next;
        }
    }

    bool empty() const
    {
        return head = nullptr;
    }

    int size() const
    {
        return _size;
    }

    void push(const T &val)
    {
        _size++;
        if (head != nullptr)
        {
            tail->next = new Element<T>(val);
            tail = tail->next;
        }
        else
        {
            head = new Element<T>(val);
            tail = head;
        }
    }

    const T &front() const
    {
        return head->data;
    }

    const T &back() const
    {
        return tail->data;
    }

    void insert(int pos, const T &val)
    {
        if (pos == 0 && head == nullptr)
        {
            head = new Element<T>(val);
            tail = head;
        }
        else if (pos == 0 && head != nullptr)
        {
            Element<T> *tmp = head;
            head = new Element<T>(val);
            head->next = tmp;
        }
        else if (pos > 0 && pos < _size)
        {
            Element<T> *tmp = head;

            for (int i = 0; i < pos; i++)
            {
                tmp = tmp->next;
                if (i == pos)
                {
                    Element<T> *tmp2 = new Element<T>(val);
                    tmp2 = tmp->next;
                    tmp->next = tmp2;
                }
            }
        }
    }

    void pop()
    {
        if (_size > 1)
        {
            Element<T> *element = head;
            while (element->next != tail)
            {
                element = element->next;
            }

            delete tail;
            tail = element;
            tail->next = nullptr;
            _size--;
        }
        else if (_size == 1)
        {
            delete head;
            head = tail = nullptr;
            _size = 0;
        }
    }

    void erase(int pos)
    {
        if (pos == 0 && _size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            _size = 0;
        }
        else if (pos == _size - 1)
        {
            auto tmp = head;

            for (int i = 0; i < pos - 1; i++)
            {
                tmp = tmp->next;
            }
            delete tail;
            tmp->next = nullptr;
            tail = tmp;
            _size--;
        }
        else if (pos >= 0 && pos < _size)
        {
            auto tmp = head;

            for (int i = 0; i < pos - 1; i++)
            {
                tmp = tmp->next;
            }
            tmp->next = tmp->next->next;
            _size--;
        }
    }

    void erase(int from, int to)
    {
        if (from >= 0 && to < _size)
        {
            auto tmp1 = head;
            auto tmp2 = head;

            for (int i = 0; i < from - 1; i++)
            {
                tmp1 = tmp1->next;
            }
            for (int i = 0; i < to - 1; i++)
            {
                tmp2 = tmp2->next;
            }
            tmp1->next = tmp2;

            _size = _size - (to - from + 1);
        }
    }

    void clear()
    {
        Element<T> *tmp = head;
        while (tmp != nullptr)
        {
            tmp = tmp->next;
            delete head;
            head = tmp;
        }
        _size = 0;
        head = nullptr;
        tail = nullptr;
    }

    void setSize(int _size)
    {
        this->_size = _size;
    }
};

int main()
{
    ForwardList<int> fl;

    fl.push(8);
    fl.push(3);
    fl.push(15);
    fl.push(1);
    fl.push(64);

    cout << fl[0] << " " << fl[1] << " " << fl[2] << endl;
    //cout << fl[1] << endl;

    //fl.erase(2);
    //fl.erase(4);
    fl.erase(2, 4);

    //cout << fl.size() << endl;

    for (int i = 0; i < fl.size(); i++)
    {
        cout << fl[i] << " ";
    }
    cout << endl;

    //cout << fl.size() << endl;

    fl.setSize(3);

    for (int i = 0; i < fl.size(); i++)
    {
        cout << fl[i] << " ";
    }
    cout << endl;

    /*fl.push(10);
    fl.push(15);
    fl.push(20);
    fl.pop();
    fl.pop();
    fl.pop();
    cout << fl.front() << " " << fl.back() << endl;*/

    /*cout << fl.empty() << endl;
    cout << fl.size() << endl;

    fl.push(13);
    fl.push(15);
    fl.push(8);

    cout << fl.front() << endl;
    cout << fl.back() << endl;

    cout << fl[0] << " " << fl[1] << " " << fl[2] << endl;
    fl[2] = 17;

    fl.insert(2, 100);

    cout << fl[0] << " " << fl[1] << " " << fl[2] << fl[3] << endl;

    fl.push(43);
    fl.push(1);
    fl.push(123);

    fl.pop();
    fl.erase(1);
    fl.erase(1, 3);

    fl.clear();*/
}