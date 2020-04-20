#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <time.h>
#include <ctime>
using namespace std;

template<class T>
class A
{
private:
    T* data;
    int size;
public:
    void add(T value) 
    {
        T* tmp = new T[size + 1];
        delete[]tmp;
    }
};

class B
{
private:
    vector<int> vec;
public:
    B() {}
};

void func(B a)
{

}

int main()
{
    srand(time(0));
    A<int> obj;

    vector<vector<int> > vec;
    //vector<vector<int> > vec(10, vector<int>(5));
    vec.resize(10);

    for (auto& el : vec)
    {
        el.resize(5);
    }

    for (auto& el : vec)
    {
        for (auto& el1 : el)
        {
            el1 = rand() % 10;
        }
    }

    for (auto el : vec)
    {
        for (auto el1 : el)
        {
            cout << el1 << " ";
        }
        cout << endl;
    }



//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    /*vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    vector<int>::iterator it = vec.begin();

    /*cout << *it << endl;
    it++;
    cout << *it << endl;

    for (auto el : vec)
    {
        cout << el << " ";
    }
    cout << endl;*/

    //vector<int> vec1(100000000);

    //clock_t start = clock();
    /*for (auto& num : vec)
    {
        num = 1;
    }*/
    //cout << clock() - start;
    //cout << endl;

    /*while (it < vec.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;*/
    

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    /*vector<vector<int> > vec;
    vec.resize(10);
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].resize(5);
    }

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            vec[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j];
        }
        cout << endl;
    }*/

    /*vector<vector<int> > vec3;
    int row = 5;
    int col = 10;

    for (int i = 0; i < row; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < col; j++)
        {
            tmp.push_back(rand() % 10);
        }
        vec3.push_back(tmp);
    }*/

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    /*vector<int> vec;
    vector<int> vec2;
    vec2.resize(10);

    /*for (auto i = vec.begin(); i < vec.end(); ++i)
    {
        vec.push_back(rand() % 10);
        cout << *i << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        vec.push_back(rand() % 10);
        cout << vec[i] << " ";
    }
    cout << endl;
    cout << endl;

    for (int i = 0; i < vec2.size(); i++)
    {
        vec2[i] = rand() % 10;
        cout << vec2[i] << " ";
    }
    cout << endl;*/

    //B b;
    //func(b);

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    /*vector<int> vec;
    cout << vec.empty() << endl;
    cout << vec.size() << endl;
    cout << vec.max_size() << endl;

    //vec = { 1, 8, 4, 69, 420 };

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " " << endl;
    }

    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(8);
    vec.push_back(8);
    vec.push_back(8);
    cout << vec[0] << " " << vec[1] << endl;

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " " << endl;
    }
    cout << endl;

    vec.resize(3);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " " << endl;
    }
    cout << endl;

    vector<int> vec2;
    vec2 = vec;

    for (int i = 0; i < vec2.size(); i++)
    {
        cout << vec2[i] << " " << endl;
    }

    vec.begin();
    vec.end();

    cout << vec.at(0) << " " << vec.at(1) << endl;*/

//----------------------------------------------
    //array<char, 4> arr = {'B', 'Y', 'E', '\0' };
    /*array<int, 4> arr = { 123, 11, 122, 31 };
    //cout << arr.data() << endl;
    //cout << *arr.begin() << endl;
    //cout << *arr.end() << endl;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " " << endl;
    }
    cout << endl;*/


//-------------------------------------------
    /*array<int, 10> arr;
    
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 10;
        cout << arr[i] << " ";
    }
    cout << endl;

    array<int, 10> arr1;
    arr1 = arr;
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;*/

//-------------------------------------------
    //array<int, 5> arr1 = { 1, 2, 3, 4, 5 };
    //array<int, 5> arr2;

    //arr2 = arr1;
    //cout << arr2[0] << endl;

//------------------------------------------
    //array<int, 5> arr1{ 1, 2, 3, 4, 5 };
    //array<int, 5> arr2{ 11, 12, 13 };

    //arr1.swap(arr2);
    //cout << arr1[0] << endl;


//-------------------------------------------
    //array<int, 100> arr;
    //arr[0] = 11;
    //arr[99] = 12;

    //cout << arr[0] << " " << arr[99] << endl;

    //arr.at(1) = 100;

    //cout << arr[1] << endl;

    //cout << arr.size() << endl;
    
    //arr.swap();
}