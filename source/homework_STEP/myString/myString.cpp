#include <iostream>
using namespace std;

class MyString {
	char* data;
	friend ostream& operator<<(ostream& out, const MyString& obj);
	friend istream& operator>>(istream& in, MyString& obj);
public:
	MyString() {}
	MyString(const char * str) {}
	MyString(const MyString& obj) {}
	MyString(MyString&& obj) {}
	~MyString() {}
	// Методы
	int size() {}
	//Перегрузки операторов
	//=
	void operator=(const char* str) {
		delete[] data;
		data = nullptr;

		if (str != nullptr) {
			data = new char[strlen(str) + 1];
			strcpy(data, str);
		}
	}
	void operator=(const MyString& obj) {}
	void operator=(MyString&& obj) {}
	//+
	MyString operator+(const char* str) {}
	MyString operator+(const MyString& obj) {}
	void operator+=(const char* str) {}
	void operator+=(const MyString& obj) {}
	//[]
	char& operator[](int pos) {}
	// == != > >= < <= на два типа: const char* str | const MyString& obj
};

istream& operator>>(istream& in, MyString& obj) {
	delete[] obj.data;
	obj.data = nullptr;

	char* buff = new char[1000];
	in.getline(buff, 1000);
	obj.data = new char[strlen(buff) + 1];
	strcpy(obj.data, buff);
	delete[] buff;
	return in;
}

int main() {
	MyString str1;
	MyString str2("Hello");

	str1 = "Goodbay";
	cout << str1 << endl; //Goodbay

	str1 = str2;
	cout << str1 << endl;//Hello

	str1[0] = '!';

	MyString str3;
	str3 = str1 + str2; // r-value "!eloyHeloy"
	cout << str3 << endl; //!eloyHeloy

	str1 += str2;// str1 = "!eloyHeloy"
	cout << str1 << endl; //!eloyHeloy

	MyString str4("World");
	str4 += " !!!";
	cout << str4 << endl; //World

	MyString str5;
	cin >> str5;
	cout << str5;

	// == !=  проверка на полную идентичность (c "asdasd" и с Mystring)
	// > >= < <= проверка на длину!
	// метод size
	cout << str5.size() << endl;
	cin.get();
}