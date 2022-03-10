#include <iostream>
#include <queue>
using namespace std;

template <class T>
class Element
{
public:
    T data;
    Element<T> *next;
    Element() : data(), next(nullptr) {}
    Element(const T &data) : data(data), next(nullptr) {}
};

template <class T>
class Queue
{
private:
    Element<T> *_front;
    Element<T> *_back;
    int _size;

public:
    Queue() : _front(nullptr), _back(nullptr), _size() {}
    Queue(const Queue<T> &obj) : _front(nullptr), _back(nullptr), _size()
    {
        if (obj._front != nullptr)
        {
            auto tmp = obj._front;

            while (tmp)
            {
                push(tmp->data);
                tmp->next;
            }
        }
    }

    Queue(const Queue<T> &&obj)
    {
        _front = obj._front;
        obj._front = nullptr;

        _back = obj._back;
        obj._back = nullptr;

        _size = obj._size;
    }

    ~Queue()
    {
        while (_size)
        {
            pop();
        }
    }

    void operator=(const Queue<T> &obj)
    {
        Element<T> *tmp = _front;
        while (tmp != nullptr)
        {
            tmp = tmp->next;
            delete _front;
            _front = tmp;
        }
        _size = 0;
        _front = nullptr;
        _back = nullptr;

        if (obj._front != nullptr)
        {
            auto tmp = obj._front;

            while (tmp)
            {
                push(tmp->data);
                tmp->next;
            }
        }
    }
    void operator=(const Queue<T> &&obj)
    {
        Element<T> *tmp = _front;
        while (tmp != nullptr)
        {
            tmp = tmp->next;
            delete _front;
            _front = tmp;
        }
        _size = 0;
        _front = nullptr;
        _back = nullptr;

        _front = obj._front;
        obj._front = nullptr;

        _back = obj._back;
        obj._back = nullptr;

        _size = obj._size;
    }

    bool empty() const
    {
        return _size == 0;
    }

    int size() const
    {
        return _size;
    }

    void push(const T &val)
    {
        if (_front == nullptr)
        {
            _front = new Element<T>(val);
            _back = _front;
        }
        else
        {
            _back->next = new Element<T>(val);
            _back = _back->next;
        }
        _size++;
    }

    void pop()
    {
        if (_size != 0)
        {
            Element<T> *tmp = _front->next;
            delete _front;
            _front = tmp;
            _size--;
        }
    }

    const T &front()
    {
        return _front->data;
    }

    const T &back()
    {
        return _back->data;
    }

    void swap(Queue<T> &obj)
    {
        if (this->_size == obj._size)
        {
            auto tmpObj = obj._front;
            auto tmpThis = this->_front;

            int objNum, thisNum;

            for (int i = 0; i < _size; i++)
            {
                objNum = tmpObj->data;
                thisNum = tmpThis->data;

                tmpObj->data = thisNum;
                tmpThis->data = objNum;
                tmpObj = tmpObj->next;
                tmpThis = tmpThis->next;
            }
        }
    }
};

int main()
{
    Queue<int> q;
    q.push(12);
    q.push(123);
    q.push(321);

    cout << q.front() << endl;
    cout << q.back() << endl;

    cout << endl;

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    /*cout << endl;

    cout << q.empty() << endl;
    cout << q.size() << endl;

    Queue<int> que1;
    Queue<int> que2;

    que1.push(4);
    que1.push(83);
    que1.push(26);
    que1.push(17);

    que2.push(6);
    que2.push(91);
    que2.push(43);
    que2.push(29);

    que1.swap(que2);

    while (!que1.empty())
    {
        cout << que1.front() << " ";
        que1.pop();
    }
    cout << endl;
    cout << endl;

    while (!que2.empty())
    {
        cout << que2.front() << " ";
        que2.pop();
    }
    cout << endl;*/
}