#include<iostream>
using namespace std;

template<typename T>
void input(T& data, const char * message = "") 
{

	while (!(cin >> data)) 
    {
		cout << message;

		// сброс флагов ошибок
		cin.clear();

		//пропуск указанного кол-ва символов потока, или если встретим '\n'
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() 
{
	double num1;
	input(num1, "Incorrect input, please repeat enter: ");
	cout << num1;

	cin.get();
	return 0;
}
