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
    PriorityQueue(const PriorityQueue<T> &obj)
    {
    }

    PriorityQueue(const PriorityQueue<T> &&obj)
    {
    }

    ~PriorityQueue()
    {
    }

    void operator=(const PriorityQueue<T> &obj) {}
    void operator=(const PriorityQueue<T> &&obj) {}

    bool empty() const
    {
        return _size = 0;
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

    void swap(PriorityQueue<T> &obj) {}

    /*void show() {
		Element<T>* elem = _front;
		while (elem) {
			cout << elem->data << ' ';
			elem = elem->next;
		}cout << endl;
	}*/
};

int main()
{
    PriorityQueue<int> quet;
    //PriorityQueue<int> que;

    quet.push(10);
    quet.push(11);
    quet.push(12);
    cout << quet.top() << endl;
    //cout << que.back() << endl;
    cout << quet.empty() << endl;
    quet.pop();
}