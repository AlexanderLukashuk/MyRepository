#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class Abonent
{
private:
    char *name;
    int age;
    char *phone;

public:
    Abonent() : name(nullptr), age(0), phone(nullptr) {}
    Abonent(const char *name, int age, const char *phone)
    {
        if (name != nullptr)
        {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }

        if (age > 0)
        {
            this->age = age;
        }

        if (phone != nullptr)
        {
            this->phone = new char[strlen(phone) + 1];
            strcpy(this->phone, phone);
        }
    }

    ~Abonent()
    {
        if (!name)
        {
            delete[] name;
        }

        if (!phone)
        {
            delete[] phone;
        }
    }

    void input(const char *name, int age, const char *phone)
    {
        if (this->name != nullptr)
        {
            delete[] this->name;
            this->name = nullptr;
        }

        if (this->phone != nullptr)
        {
            delete[] this->phone;
            this->phone = nullptr;
        }

        if (name != nullptr)
        {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }

        if (phone != nullptr)
        {
            this->phone = new char[strlen(phone) + 1];
            strcpy(this->phone, phone);
        }

        if (age > 0)
        {
            this->age = age;
        }
    }

    string toString() const
    {
        stringstream ss;
        ss << name << " " << phone << " " << age;
        return ss.str();
    }

    void setName(const char *name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setPhone(const char *phone)
    {
        this->phone = new char[strlen(phone) + 1];
        strcpy(this->phone, phone);
    }

    char *getName()
    {
        return name;
    }

    char *getPhone()
    {
        return phone;
    }

    int getAge()
    {
        return age;
    }
};

class PhoneBook
{
private:
    vector<Abonent> abonent;

public:
    PhoneBook() : abonent() {}
    /*~PhoneBook()
        {
            abonent.clear();
        }*/

    void add(const Abonent obj)
    {
        abonent.push_back(obj);
    }

    void remove(const char *name)
    {
        for (auto i = abonent.begin(); i != abonent.end(); ++i)
        {
            if (strcmp((*i).getName(), name) == 0)
            {
                abonent.erase(i);
            }
        }
    }

    PhoneBook find(const char* name)
    {
        //vector<Abonent> mas;
        PhoneBook result;
        for (auto i = abonent.begin(); i != abonent.end(); ++i)
        { //todo
            string abonentName = (*i).getName();
            size_t found = abonentName.find(name);
            if (found != string::npos)
            {
                //mas.push_back((*i));
                result.add((*i));
            }
        }
        return result;
        //return mas;
    }

    string toString()
    {
        stringstream ss;
        for (auto i = abonent.begin(); i != abonent.end(); ++i)
        {
            ss << (*i).toString() << endl;
            //cout << ss.str() << endl;
        }
        return ss.str();
    }

    vector<Abonent> getAll()
    {
        return abonent;
    }
};

class Ofstream
{
public:
    static void WriteToFile(const char *fileName, PhoneBook book)
    {
        ofstream fo;
        if (fileName != nullptr)
        {
            fo.open(fileName, ios::out);
            if (fo.is_open())
            {
                fo << book.toString();
            }
        }
        fo.close();
    }

    static PhoneBook ReadFile(const char *fileName)
    {
        PhoneBook book;
        ifstream fi;
        if (fileName != nullptr)
        {
            fi.open(fileName);
            if (fi.is_open())
            {
                char strName[100];
                char strPhone[100];
                char strAge[100];
                // while(!fi.eof())
                // {
                //     fi >> strName >> strAge >> strPhone;
                //     temp.setName(strName);
                //     temp.setAge(atoi(strAge));
                //     temp.setPhone(strPhone);
                //     book.add(temp);
                // }

                while (fi >> strName >> strAge >> strPhone)
                {
                    Abonent temp(strName, atoi(strAge), strPhone);
                    book.add(temp);
                }
            }
        }
        fi.close();
        return book;
    }
};

int menu(const vector<string> menuTitles)
{
    int result = -1;

    //for (auto s = menuTitles.begin(); s != menuTitles.end(); ++i);
    for (auto s : menuTitles)
    {
        cout << s << endl;
    }
    cin >> result;
    cin.get();

    return result;
}

PhoneBook SeedData()
{
    PhoneBook result;
    result.add(Abonent("Alex", 24, "+8532512"));
    result.add(Abonent("Oleg", 31, "+85573234"));
    result.add(Abonent("John", 19, "+868237882"));

    return result;
}

vector<string> initMenu()
{
    vector<string> m;
    m.push_back("1) Добавить");
    m.push_back("2) Удалить");
    m.push_back("3) Искать");
    m.push_back("4) Показать всех");
    m.push_back("5) Сохранить в файл");
    m.push_back("6) Загрузить из файла");
    m.push_back("7) Выход");

    return m;
}

Abonent createAbonent()
{
    char *name = new char[100];
    char *phone = new char[100];
    int age;
    cout << "Enter name: ";
    cin.getline(name, 100);
    cout << "Enter phone nuber: ";
    cin.getline(phone, 100);
    cout << "Enter age: ";
    cin >> age;
    cin.get();
    Abonent abon(name, age, phone);

    if (name != nullptr)
    {
        delete[] name;
    }

    if (phone != nullptr)
    {
        delete[] phone;
    }

    return abon;
}

void app()
{
    PhoneBook book;
    vector<string> m = initMenu();
    /*m.push_back("1) Добавить");
    m.push_back("2) Удалить");
    m.push_back("3) Искать");
    m.push_back("4) Показать всех");
    m.push_back("5) Сохранить в файл");
    m.push_back("6) Загрузить из файла");
    m.push_back("7) Удалить всех");
    m.push_back("8) Выход");*/

    while (true)
    {
        switch (menu(m))
        {
        case 1:
        {
            book.add(createAbonent());
            break;
        }
        case 2:
        {
            char* name = new char[100];
            cout << "Enter name: ";
            cin.getline(name, 100);
            book.remove(name);
            break;
        }
        case 3:
        {
            char* name = new char[100];
            cout << "Enter name to search: ";
            cin.getline(name, 100);
            book.find(name);

            if (name != nullptr)
            {
                delete[]name;
            }

            break;
        }
        case 4:
        {
            cout << book.toString() << endl;
            break;
        }
        case 5:
        {
            char* fileName = new char[100];
            cout << "Enter file name: ";
            Ofstream::WriteToFile(fileName, book);

            if (fileName != nullptr)
            {
                delete[]fileName;
            } 

            break;
        }
        case 6:
        {
            char* fileName = new char[100];
            cout << "Enter file name: ";
            Ofstream::ReadFile(fileName);

            if (fileName != nullptr)
            {
                delete[]fileName;
            }

            break;
        }
        case 7:
        {
            cout << "Bye" << endl;
            return;
            break;
        }
        }
    }
}

int main()
{
    PhoneBook book = SeedData();
    //book.SeedData();
    app();

    return 0;
}