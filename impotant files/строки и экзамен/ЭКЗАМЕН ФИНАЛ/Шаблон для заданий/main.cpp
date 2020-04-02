#include <iostream>
#include "win10h.h"
#include "functions.h"
using namespace std;

int main() {
	start(50, 100);
	SetPos(50, 10);
	SetColor(SetConsoleColor(0xA, 0x4));
	cout << "Text";
	CursorHide();
	cin.get();
}