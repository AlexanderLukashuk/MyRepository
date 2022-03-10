#include <iostream>
#include <string>
#include <time.h>
#include <ctime>
#include <list>
using namespace std;
//using std::cout;
//using std::endl;
//using std::move;
//using std::string;

// семантика перемещения
class TEST {	
	int size;
	int* array;
public:	
	TEST(int size) : size(size) 
    {
		array = new int[size];
	}
	TEST(const TEST& obj)
    {
		cout << "COPY\n";
		size = obj.size;
		array = new int[size];
		for (int i = 0; i < size; i++) {
			array[i] = obj.array[i];
		}
	}
	TEST(TEST&& obj)
    {
		cout << "PEREMESH\n";
		size = obj.size;
		array = obj.array;
		obj.array = nullptr;
	}
	~TEST()
    {
		delete[] array;
	}

    void showAdress()
    {
        if (array != nullptr)
        {
            cout << array << endl;
        }
        else
        {
            cout << "nullptr" << endl;
        }
    }
};

template<class T>
T&& Move(T& t)
{
    return static_cast<TEST&&>(t);
}

int main()
{
    srand(time(0));

    /*list<TEST> list1;
    for (int i = 0; i < 250; i++)
    {
        list1.push_back(TEST(1000000));
    }

    //TEST t(100000000);
    cout << "Object is created" << endl;
    cin.get();

    int start = clock();
    //TEST t1(move(t1));
    list<TEST> list2(move(list1));
    cout << clock() - start << "ms" << endl;*/

    TEST t(10000);

    TEST t1(Move(t));

    t.showAdress();
    t1.showAdress();
}
