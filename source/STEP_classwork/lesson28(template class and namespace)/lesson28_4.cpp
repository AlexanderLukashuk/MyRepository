#include<iostream>
using namespace std;
//Напишите программу, использующую единственный файл, содержащий
//пространства имен X, У и Z, так, чтобы функция main(), приведенная
//ниже, работала правильно.

namespace X
{
    int var;
    int print()
    {
        cout << "var X = " << var << endl;
    }
}

namespace Y
{
    int var;
    int print()
    {
        cout << "var Y = " << var << endl;
    }
}

namespace Z
{
    int var;
    int print()
    {
        cout << "var Z = " << var << endl;
    }
}

int main()
{
	//setlocale(LC_ALL, "RUS");
	X::var = 7;
	X::print();		// Вывод var из пространства имен Х
	using namespace Y;
	var = 9;
	print();		// Вывод var из пространства имен Y
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();	// Вывод var из пространства имен Z
	}
	print();		// Вывод var из пространства имен Y
	X::print();		// Вывод var из пространства имен X
	//system("pause");
}

//Каждое пространство имен должно содержать определение переменной
//var и функции print().выводящей соответствующую переменную
//var в поток cout.