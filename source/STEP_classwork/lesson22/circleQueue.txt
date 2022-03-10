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
class CircleQueue
{
private:
    Element<T> *head;
    Element<T> *tail;
    int _size;

public:
    CircleQueue() : head(nullptr), tail(nullptr), _size() {}

    CircleQueue(const CircleQueue<T> &obj) : head(nullptr), tail(nullptr), _size()
    {
        auto tmp = obj.head;
        if (obj.head != nullptr)
        {
            for (int i = 0; i < obj._size; i++)
            {
                push(tmp->data);
                tmp = tmp->next;
            }
        }
    }

    CircleQueue(CircleQueue<T> &&obj)
    {
        head = obj.head;
        obj.head = nullptr;

        tail = obj.tail;
        obj.tail = nullptr;

        _size = obj._size;
    }

    ~CircleQueue()
    {
        clear();
    }

    void operator=(const CircleQueue<T> &obj)
    {
        clear();
        auto tmp = obj.head;
        if (obj.head != nullptr)
        {
            for (int i = 0; i < obj._size; i++)
            {
                push(tmp->data);
                tmp = tmp->next;
            }
        }
    }

    void operator=(CircleQueue<T> &&obj)
    {
        clear();

        head = obj.head;
        obj.head = nullptr;

        tail = obj.tail;
        obj.tail = nullptr;

        _size = obj._size;
    }

    void push(const T &value)
    {
        if (head != nullptr)
        {
            tail->next = new Element<T>(value);
            tail = tail->next;
        }
        else
        {
            head = new Element<T>(value);
            tail = head;
        }
        _size++;
    }

    void pop()
    {
        if (_size > 1)
        {
            push(head->data);
            head = head->next;
            _size--;
        }
    }

    T &front()
    {
        return head->data;
    }

    T &back()
    {
        return tail->data;
    }

    bool empty()
    {
        return _size == 0;
    }

    int size()
    {
        return _size;
    }

    void clear()
    {
        auto tmp = head;

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
};

int main()
{
    CircleQueue<int> cq;

    /*cout << cq.empty() << endl;
    cout << cq.size() << endl;

    cq.push(8);
    cq.push(19);
    cq.push(5);
    cq.push(27);
    cq.push(69);
    cq.push(13);

    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();

    cout << cq.front() << endl;
    cout << cq.back() << endl;

    cout << cq.empty() << endl;
    cout << cq.size() << endl;

    cq.clear();

    cout << cq.empty() << endl;
    cout << cq.size() << endl;*/

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);
    // 1 2 3 4 5

    cq.pop();
    // 2 3 4 5 1
    cout << cq.front() << endl;
    cout << cq.back() << endl;
    cout << endl;
    cin.get();

    cq.pop();
    // 3 4 5 1 2
    cout << cq.front() << endl;
    cout << cq.back() << endl;
    cout << endl;
    cin.get();

    cq.push(6);
    // 3 4 5 1 2 6
    cout << cq.front() << endl;
    cout << cq.back() << endl;
    cout << endl;
    cin.get();

    cq.pop();
    // 4 5 1 2 6 3
    cout << cq.front() << endl;
    cout << cq.back() << endl;
    cout << endl;
    cin.get();

    cout << cq.front() << endl; // 4
    cout << cq.back() << endl;  // 3
    cout << endl;
    cin.get();

    cout << cq.size() << endl;  // 6
    cout << cq.empty() << endl; // 0
    cout << endl;
    cin.get();

    //В цикле вывести на экран кольцевую очередь целиком

    for (int i = 0; i < cq.size(); i++)
    {
        cout << cq.front() << " ";
        cq.pop();
    }
    cout << endl;
}