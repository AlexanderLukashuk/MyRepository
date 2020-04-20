#include <iostream>
using namespace std;

class Element
{
public:
    int data;
    Element* next;
};

int main()
{
    Element* head;
    Element* tmp;

    head = new Element;
    head->data = 100;
    head->next = nullptr;

    tmp = new Element;
    tmp->data = 200;
    tmp->next = head;
    head = tmp;

    tmp = new Element;
    tmp->next = head;
    tmp->data = 300;
    head = tmp;

    tmp = new Element;
    tmp->next = head;
    tmp->data = 400;
    head = tmp;

    cout << head->data << endl;
    cout << head->next->data << endl;
    cout << head->next->next->data << endl;
    cout << head->next->next->next->data << endl;


}