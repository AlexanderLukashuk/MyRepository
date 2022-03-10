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

    bool operator<(const Element<T> &r)
    {
        return this->data < r.data;
    }
};

template <class T>
class PriorityQueue
{
private:
    Element<T> *_top;
    int _size;

public:
    PriorityQueue() : _top(nullptr), _size() {}
    PriorityQueue(const PriorityQueue<T> &obj) : _top(nullptr), _size()
    {
        if (obj._top != nullptr)
        {
            auto tmp = obj._top;

            while (tmp)
            {
                push(tmp->data);
                tmp = tmp->next;
            }
        }
    }

    PriorityQueue(const PriorityQueue<T> &&obj)
    {
        _top = obj._top;
        obj._top = nullptr;

        _size = obj._size;
    }

    ~PriorityQueue()
    {
        while (_size)
        {
            pop();
        }
    }

    void operator=(const PriorityQueue<T> &obj)
    {
        auto tmp = _top;

        while (tmp != nullptr)
        {
            tmp = tmp->next;
            delete _top;
            _top = tmp;
        }
        _size = 0;
        _top = nullptr;

        if (obj._top != nullptr)
        {
            auto tmp = obj._top;

            while (tmp)
            {
                push(tmp->data);
                tmp = tmp->next;
            }
        }
    }

    void operator=(const PriorityQueue<T> &&obj)
    {
        auto tmp = _top;

        while (tmp != nullptr)
        {
            tmp = tmp->next;
            delete _top;
            _top = tmp;
        }
        _size = 0;
        _top = nullptr;

        _top = obj._top;
        obj._top = nullptr;

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
        _size++;

        if (_top == nullptr)
        {
            _top = new Element<T>(val);
            return;
        }

        if (_top->data < val)
        {
            Element<T> *tmp = new Element<T>(val);
            tmp->next = _top;
            _top = tmp;
            return;
        }

        Element<T> *elem = _top;
        while (elem->next != nullptr)
        {
            if (elem->next->data < val)
            {
                Element<T> *tmp = new Element<T>(val);
                tmp->next = elem->next;
                elem->next = tmp;
                return;
            }
            elem = elem->next;
        }

        Element<T> *tmp = new Element<T>(val);
        elem->next = tmp;
    }

    void pop()
    {
        if (_size != 0)
        {
            Element<T> *tmp = _top->next;
            delete _top;
            _top = tmp;
            _size--;
        }
    }

    const T &top()
    {
        return _top->data;
    }

    void swap(PriorityQueue<T> &obj)
    {
        if (this->_size == obj._size)
        {
            auto tmpObj = obj._top;
            auto tmpThis = this->_top;

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

    void show()
    {
        Element<T> *elem = _top;
        while (elem)
        {
            cout << elem->data << " ";
            elem = elem->next;
        }
        cout << endl;
    }
};

int main()
{
    /*PriorityQueue<int> quet;
    //PriorityQueue<int> que;

    quet.push(10);
    quet.push(11);
    quet.push(12);
    cout << quet.top() << endl;
    cout << quet.empty() << endl;
    quet.pop();
    quet.pop();
    quet.pop();

    cout << quet.empty() << endl;*/

    PriorityQueue<int> pq;

    cout << pq.empty() << endl;
    cout << pq.size() << endl;

	pq.push(50);
	pq.push(100);
	pq.push(10);
	pq.push(75);
	pq.push(35);
	pq.show();

    /*cout << endl;
    cout << pq.empty() << endl;
    cout << pq.size() << endl;
    cout << endl;

    cout << pq.top() << endl;

    pq.pop();
    pq.pop();
    pq.pop();
    pq.show();

    PriorityQueue<int> pq1;
    PriorityQueue<int> pq2;

    pq1.push(35);
    pq1.push(88);
    pq1.push(3);
    pq1.push(26);
    pq1.push(74);

    pq2.push(64);
    pq2.push(0);
    pq2.push(156);
    pq2.push(45);
    pq2.push(37);

    pq1.swap(pq2);
    pq1.show();
    cout << endl;
    pq2.show();*/
}