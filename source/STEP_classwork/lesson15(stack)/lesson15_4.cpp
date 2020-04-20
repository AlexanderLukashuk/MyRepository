#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Element
{
public:
    T data;
    Element<T> *next;
    Element() : data(), next(nullptr) {}
};

template <class T>
class Stack
{
private:
    Element<T> *head;
    int count;

public:
    Stack() : head(nullptr), count(0) {}
    Stack(const Stack<T> &obj)
    {
        if (obj.count != 0)
        {
            count = obj.count;
            Element<T>* el = obj.head;
            Element<T>* tail;
            Element<T>* tmp;
            
            head = new Element<T>;
            head->data = el->data;

            tail = head;
            el = el->next;

            while (el != nullptr)
            {
                tmp = new Element<T>;
                tmp->data = el->data;
                tail->next = tmp;
                tail = tmp;
                el = el->next;   
            }
        }
    }
    Stack(Stack<T> &&obj)
    {
        count = obj.count;
        head = obj.head;
        obj.head = nullptr;
    }

    ~Stack()
    {
        while (count)
        {
            pop();
        }
    }

    void operator=(const Stack<T> &obj)
    {
    }

    void operator=(Stack<T> &&obj) {}

    bool empty()
    {
        //return count == 0;
        if (count == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size()
    {
        return count;
    }

    void push(const T &val)
    {
        /*if (count == 0)
        {
            head = new Element<T>;
            head->data = val;
            count++;
        }
        else
        {
            Element<T> *tmp = new Element<T>;
            tmp->data = val;
            tmp->next = head;
            head = tmp;
            count++;
        }*/

        Element<T> *tmp = new Element<T>;
        tmp->data = val;
        tmp->next = head;
        head = tmp;
        count++;
    }

    void pop()
    {
        if (count != 0)
        {
            Element<T> *tmp = head->next;
            delete head;
            head = tmp;
            count--;
        }
    }

    T &top()
    {
        return head->data;
    }

    void swap(Stack<T> &st)
    {
        Stack<T> tmp = st;
        st = *this;
        *this = tmp;
        /*Element<T> *tmp;
        tmp = head;
        int tmpCount;
        this->head = st.head;
        st.head = tmp;
        this->count = st.count;
        st.count = tmpCount;*/
    }
};

void show(Stack<int> st)
{
    while (st.size())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    Stack<int> st;
    st.push(100);
    st.push(200);
    show(st);
    cout << st.top() << endl;
    /*Stack<int> st;

    cout << st.empty() << " " << st.size() << endl;

    st.push(100);
    cout << st.top() << endl;
    st.push(200);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();

    cout << st.empty() << " " << st.size() << endl;*/
}