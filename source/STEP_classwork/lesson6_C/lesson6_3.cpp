#include<iostream>
using namespace std;

void func(const int size) {
	int mas[size];
}

int main() {
	const int c1 = 15; // конст времени компил€ции
	const int c2 = pow(2, 8); // константа времени выполнени€
	int mas[c1];
	//int mas[c2];
	//--------------------------------------------------------

	constexpr int size = 15; // €вна€ конст. времени компил.
	constexpr int size = pow(2, 8);

	cin.get();
	return 0;
}
