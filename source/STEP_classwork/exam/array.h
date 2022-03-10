#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <iostream>

template<class T>
class Array
{
private:
    T* data;
public:
    Array();
    Array(int size, initializer_list<T> l);
    Array(const Array<T>& arr);
    Array(Array<T>&& arr);
    ~Array();

    Array<T>& operator=(const Array<T>& arr);
    Array<T> operator=(Array<T>&& arr);
    Array<T> operator=(initializer_list<T> l);
    T &operator[](int pos);

    int size();
    void swap(Array<T> &arr);
};

#endif