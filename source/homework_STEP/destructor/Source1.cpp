#define _CRT_SECURE_NO_WARNINGS
#define DEBUGING
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

enum Command
{
	ADD = 1,
	REMOVE = 2,
	EXIT = 3
};
class Menu
{
public:
	static int PrintMenu(vector<string> menuTitles)
	{
		int res;
		for (auto s : menuTitles)
		{
			cout << s << endl;
		}
		cin >> res;

		return res;
	}
};


int main()
{
	system("chcp 1251 > nul");
	vector<string> m;
	m.push_back("1) ��������");
	m.push_back("2) �������");
	m.push_back("3) �����");
	while (true)
	{
		switch (Menu::PrintMenu(m))
		{
		case Command::ADD: {
			cout << "����������" << endl;
			break;
		}case Command::REMOVE: {
			cout << "��������" << endl;
			break;
		}case Command::EXIT: {
			cout << "�����" << endl;
			return 0;
			break;
		}
		}
	}

    return 0;
}
