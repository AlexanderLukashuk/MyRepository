#include <iostream>
#include <queue>
using namespace std;

template<class T>
class Element
{
public:
    T data;
    Element<T>* next;
    Element() : data(), next(nullptr) {}
    Element(const T& data) : data(data), next(nullptr) {}

};

template<class T>
class Queue
{
private:
    Element<T>* _front;
    Element<T>* _back;
    int _size;
public:
    Queue() : _front(nullptr), _back(nullptr), size() {}
    Queue(const Queue<T>& obj)
    {
        Element<T>* tmp = obj._front;
        whilee(tmp)
        {
            push(tmp->data);
            tmp = tmp->next;
        }

        //_size = obj._size;
    }

    Queue(const Queue<T>&& obj)
    {
        _front = obj._front;
        obj._front = nullptr;

        _back = obj._back;
        obk._back = nullptr;
        
        _size = obj._size;
    }

    ~Queue()
    {
        Element<T>* tmp;
        while(_front)
        {
            tmp = _front->next;
            delete _front;
            _front = tmp;
        }
    }

    void operator=(const Queue<T>& obj) {}
    void operator=(const Queue<T>&& obj) {}

    bool empty() const
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size() const
    {
        return _size;
    }

    void push(const T& val)
    {
        if (_front != nullptr)
        {
            _back->next = new Element<T>(val);
            _back = _back->next;
            /*Element<T> *tmp = new Element<T>;
            tmp->data = val;
            tmp->next = _front;
            _back = tmp;*/
        }
        else
        {
            _front = new Element<T>(val);
            _back = _front;
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

    const T& front()
    {
        return _front->data;
    }

    const T& back()
    {
        return _back->data;
    }

    void swap(Queue<T>& obj) {}
};

int main()
{
    queue<int> que;

    que.push(10);
    que.push(11);
    que.push(12);
    cout << que.front() << endl;
    //cout << que.back() << endl;
    cout << que.empty() << endl;
    que.pop();
}