#include <iostream>
#include <list>
using namespace std;

template <class T>
class Element
{
public:
    T data;
    Element<T> *next;
    Element<T> *prev;

    Element() : next(nullptr), prev(nullptr), data() {}
    Element(const T &data) : next(nullptr), prev(nullptr), data(data) {}
};

template <class T>
class List
{
private:
    Element<T> *head;
    Element<T> *tail;
    int _size;

public:
    List() : head(nullptr), _size() {}

    List(int _size, const T &val)
    {
        for (int i = 0; i < _size; i++)
        {
            push_back(val);
        }
        this->_size = _size;
    }

    List(int _size)
    {
        T obj;
        for (int i = 0; i < _size; i++)
        {
            push_back(obj);
        }
        this->_size = _size;
    }

    List(const List<T> &_list)
    {
        Element<T> *elem = _list.head;
        if (_list.head != nullptr)
        {
            for (int i = 0; i < _list.size; i++)
            {
                push_back(elem->data);
                elem = elem->next;
            }
        }
    }

    List(List<T> &&_list)
    {
        head = _list.head;
        _list.head = nullptr;

        tail = _list.tail;
        _list.tail = nullptr;

        _size = _list._size;
    }

    ~List()
    {
        while (_size)
        {
            pop_back();
        }
    }

    void operator=(const List<T> &_list)
    {
        clear();
        auto tmp = _list.head;

        for (int i = 0; i < _list.size(); i++)
        {
            push_back(tmp->data);
            tmp = tmp->next;
        }
    }

    void operator=(List<T> &&_list)
    {
        clear();

        head = _list.head;
        _list.head = nullptr;

        tail = _list.tail;
        _list.tail = nullptr;

        _size = _list._size;
    }

    bool operator!=(const List<T> &_list)
    {
        if (_size != _list._size)
            return true;
        Element<T> *elem1 = head;
        ;
        Element<T> *elem2 = _list.head;
        for (int i = 0; i < _size; i++)
        {
            if (elem1->data != elem2->data)
            {
                return true;
            }
            elem1 = elem1->next;
            elem2 = elem2->next;
        }
        return false;
    }

    bool operator==(const List<T> &_list)
    {
        if (_size != _list._size)
        {
            return false;
        }

        Element<T> *elem1 = head;
        Element<T> *elem2 = _list.head;
        for (int i = 0; i < _size; i++)
        {
            if (elem1->data != elem2->data)
            {
                return false;
            }
            elem1 = elem1->next;
            elem2 = elem2->next;
        }

        return true;
    }

    T &operator[](int index)
    {
        Element<T> *elem = head;
        /*switch (index < _size / 2)
        {
        case true:
        {
            elem = head;

            while (index--)
            {
                elem = elem->next;
            }
            break;
        }
        case false:
        {
            elem = tail;
            for(int i = index; i < _size; i++)
            {
                elem = elem->prev;
            }
            break;
        }
        }*/

        for (int i = 0; i < index; i++)
        {
            elem = elem->next;
        }

        return elem->data;
    }

    bool empty() const
    {
        return _size == 0;
    }

    int size() const
    {
        return _size;
    }

    void push_front(const T &val)
    {
        _size++;
        if (head != nullptr)
        {
            auto tmp = new Element<T>;
            tmp->data = head->data;
            //head = nullptr;
            //head = new Element<T>(val);
            head->data = val;
            tmp->next = head->next;
            tmp->prev = head;
            head->next = tmp;
            head->prev = nullptr;
        }
        else
        {
            head = new Element<T>(val);
            head->next = nullptr;
            head->prev = nullptr;
            tail->next = nullptr;
            tail->prev = nullptr;
        }
    }

    void push_back(const T &val)
    {
        _size++;
        if (head != nullptr)
        {
            /*auto tmp = new Element<T>(val);
            //tmp->data = head->data;
            //head = nullptr;
            //head = new Element<T>(val);
            //head->data = val;
            tmp->next = nullptr;
            tmp->prev = tail;
            tail = tmp;*/
            //tail->next = tmp;

            tail->next = new Element<T>(val);
            (tail->next)->prev = tail;
            tail = tail->next;

            /*Element<T> *predPosl = tail;
            Element<T> *poslednii = new Element<T>(val);
            predPosl->next = poslednii;
            poslednii->prev = predPosl;

            tail = poslednii;*/
        }
        else
        {
            head = new Element<T>(val);
            //head->next = nullptr;
            //head->prev = nullptr;
            //tail->next = nullptr;
            //tail->prev = nullptr;
            tail = head;
        }
    }

    /*void push_back(const T& val) {
		if (_size != 0) {
			Element<T>* predPosl = tail;
			Element<T>* poslednii = new Element<T>(val);
			predPosl->next = poslednii;
			poslednii->prev = predPosl;
			
			tail = poslednii;
			
			tail->next = new Element<T>(val);
			(tail->next)->prev = tail;
			tail = tail->next;
		}
		else {
			head = new Element<T>(val);
			tail = head;
		}
		_size++;
	}*/

    T front()
    {
        return head->data;
    }

    T back()
    {
        return tail->data;
    }

    void pop_front()
    {
        if (_size > 1)
        {
            auto element = head->next;
            delete head;
            head = element;
            head->prev = nullptr;
            _size--;
        }
        else if (_size == 1)
        {
            delete head;
            head = tail = nullptr;
            _size = 0;
        }
    }

    void pop_back()
    {
        if (_size > 1)
        {
            auto element = tail->prev;
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

    void resize(int _size)
    {
        this->_size = _size;
    }

    void resize(int _size, T val)
    {
        clear();
        head = new Element<T>(val);
        tail = head;

        for (int i = 0; i < _size - 1; i++)
        {
            push_back(val);
        }

        this->_size = _size;
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

    int find_front(int val)
    {
        auto elem = head;

        for (int i = 0; i < _size; i++)
        {
            if (elem->data == val)
            {
                return i;
            }
            elem = elem->next;
        }

        return -1;
    }

    int find_back(int val)
    {
        auto elem = tail;

        for (int i = _size - 1; i >= 0; i--)
        {
            if (elem->data == val)
            {
                return i;
            }
            elem = elem->prev;
        }

        return -1;
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
            auto tmp = new Element<T>(val);
            head->prev = tmp;
            tmp->next = head;
            head = tmp;
        }
        else if (pos > 0 && pos < _size)
        {
            Element<T> *tmp = head;

            /*for (int i = 0; i < _size; i++)
            {
                if (i == pos)
                {
                    Element<T> *tmp2 = new Element<T>(val);
                    tmp2->next = tmp->next;
                    tmp->next = tmp2;
                    tmp2->prev = tmp;
                    return;
                }
                tmp = tmp->next;
            }*/

            for (int i = 0; i < pos; i++)
            {
                tmp = tmp->next;
            }

            Element<T> *tmp2 = new Element<T>(val);
            tmp2->next = tmp->next;
            tmp->next = tmp2;
            tmp2->prev = tmp;
        }
        _size++;
    }
};

bool even(int val)
{
    return val % 2 != 0;
}

int main()
{
    List<int> list2(5);
    List<int> list1;
    List<int> list3(10, 8);

    list1.push_back(8);
    list1.push_back(6);
    list1.push_back(45);
    list1.push_back(74);
    list1.push_back(432);
    list1.push_back(2);
    list1.push_back(74);
    list1.push_back(91);

    list2.insert(3, 222);

    for (int i = 0; i < list2.size(); i++)
    {
        cout << list2[i] << " ";
    }
    cout << endl;

    //list1 = list3;

    //cout << list1.find_front(74) << endl;
    //cout << list1.find_back(2) << endl;

    //cout << (list3 != list2) << endl;
    //cout << (list3 == list2) << endl;
    //cout << endl;
    //cout << endl;

    for (int i = 0; i < list3.size(); i++)
    {
        cout << list3[i] << " ";
    }
    cout << endl;

    //list1.resize(10, 3);
    //list1.clear();
    //cout << list1.empty() << endl;
    //cout << list1.size() << endl;

    for (int i = 0; i < list1.size(); i++)
    {
        cout << list1[i] << " ";
    }
    cout << endl;

    /*List<int> list1;
    List<int> list2(2);
    List<int> list3(6, 8);
    List<int> list5(list3);
    List<int> list6;

    list6 = list2;
    list6.swap(list3);

    cout << list1.empty() << endl;
    cout << list1.size() << endl;

    cout << (list3 != list5) << endl;
    cout << (list3 == list5) << endl;

    list1.push_back(123);
    list1.insert(3, 222);
    list1.push_front(321);
    cout << list1.front() << endl;
    cout << list1.back() << endl;
    cout << list[3] << endl;

    list1.remove(2);
    list1.remove_if(even);

    list1.clear();
    list1.resize(10);

    for (int i = 0; i < list1.size(); i++)
    {
        list1[i] = rand() % 100;
    }
    cout << endl;

    list1.pop_back();
    list1.pop_front();
    list1.erase(3);
    list1.erase(3, 7);

    for (int i = 0; i < list1.size(); i++)
    {
        cout << list1[i] << " ";
    }

    list1.resize(5, 888);

    cout << list1.find_front(123) << " ";
    cout << list1.find_back(123) << " ";*/
}