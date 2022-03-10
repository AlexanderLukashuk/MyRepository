#include <iostream>
using namespace std;
#ifdef _WIN32
#define cls() system("cls")
#else
#define cls() system("clear")
#endif
#ifdef _WIN32
#define pause() system("pause");
#else
#define pause() cout << "Press enter to continue..."; cin.get();
#endif

/*template<class T>
class check
{
private:
    T num;
public:
    check() 
    {
        if (typeid(T) == typeid(double))
        {
            throw 1;
        }
    }
};*/

//template<class T, typename Enable = void> class TEST;

template <class T>
class TEST
/*class TEST<T, 
    typename std::enable_if<
        is_same<T, int>::value
        || is_same<T, double>::value
    >::type >*/
{
private:
    //static_assert(is_same<T, int>::value || is_same<T, double>::value, "");
public:
    TEST()
    {
        if (!(typeid(T) == typeid(int) || typeid(T) == typeid(double)))
        {
            throw 1;
        }
    }
    void show()
    {
        cout << "int / double\n";
    }

    /*void show()
    {
        //size = 10; нельзя так сделать только доступ на чтение
        cout << &size << endl;
        cout << size << " " << isOk << endl;
    }*/
};

/*template<>
void TEST<char>::show()
{
    cout << "char\n";
}

template<>
class TEST<bool>
{
public:
    void print()
    {
        cout << "bool\n";
    }
};*/

int main()
{
    //TEST<int> test1;
    TEST<int> test1;
    TEST<double> test2;
    //TEST<char> test3;
    //TEST<bool> test4;

    //test1.show();
    //test2.show();
    //test3.show();
    //test4.print();

    //int num1 = 1;
    //int num2 = 2;

    //static_assert(2 == 2 && 1 == 2, "asdasd");

    static_assert(true, "asdasd");
    //static_assert(is_same<int, double>::value, "asdasd");
    //static_assert(false, "asdasd"); // не работает с false

    pause();
    //test1.show();
}