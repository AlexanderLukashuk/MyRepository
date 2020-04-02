#include <iostream>
#include <vector>
using namespace std;

struct User {
    char* name;
    char* number;

    User(char* name, char* number)
    {
        this->name = name;
        this->number = number;
    }
};

int user_sort(User a, User b)
{
    return strcmp(a.name, b.name);
}

void print(vector<User*> users)
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i]->name << "\t\t\t" << users[i]->number << endl; 
    }
}
int menu()
{
    int index;
    cout << "1) Добавить" << endl;
    cout << "2) Удалить" << endl;
    cout << "3) Просмотр" << endl;
    cout << "4) Сортировка и просмотр" << endl;
    cout << "5) Выход" << endl;
    cin >> index;
    cin.get();
    return index;
}

int main()
{
    vector<User*> users;
    while (true) {
    switch(menu())
    {
        case 1:
        char name[100], num[100];
        cout << "Введите имя:" << endl;
        cin.getline(name, 100);
        cout << "Введите номер:" << endl;
        cin.getline(num, 100);
        users.push_back(new User(name, num));

        break;
        case 2:
        int index;
        cout << "Введите индекс(от 0): " << endl;
        cin >> index;
        users.erase(users.begin() + index);
        break;
        case 3:
        print(users);
        break;
        case 4:
        //sort(users.begin(), users.end());
        print(users);
        break;
        case 5:
            exit(0);
    }    
    }
}
