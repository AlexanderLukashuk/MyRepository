#define _CRT_SECURE_NO_WARNINGS
#define DEBUGING
#ifdef _WIN32
#define cls() system("cls")
#else
#define cls() system("clear")
#endif
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

class Abonent
{
private:
    char* name;
    int age;
    char* phone;

public:
    Abonent() : name(nullptr), age(0), phone(nullptr) {}
    Abonent(const char* name, int age, const char* phone)
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

    void input(const char* name, int age, const char* phone)
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

    void setName(const char* name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void setAge(int age)
    {
        this->age = age;
    }

    void setPhone(const char* phone)
    {
        this->phone = new char[strlen(phone) + 1];
        strcpy(this->phone, phone);
    }

    char* getName()
    {
        return name;
    }
    
    char* getPhone()
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
    vector<Abonent> abonents;

public:
    PhoneBook() : abonents() {}
    /*~PhoneBook()
        {
            abonents.clear();
        }*/

    void add(const Abonent obj)
    {
        abonents.push_back(obj);
    }

    void remove(const char* name)
    {
        /*for (auto i = abonents.begin(); i != abonents.end(); ++i)
        {
            if (strcmp((*i).getName(), name) == 0)
            {
                abonents.erase(i);
            }
        }*/

    	for (int i = 0; i < abonents.size(); i++)
    	{
    		if (strcmp(abonents[i].getName(), name) == 0)
    		{
                abonents.erase(abonents.begin() + i);
    		}
    	}
    }

    PhoneBook find(const char* name)
    {
        //vector<Abonent> mas;
        PhoneBook result;
        for (auto i = abonents.begin(); i != abonents.end(); ++i)
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
    }

    string toString()
    {
        stringstream ss;
        ss << "Name\tPhone\tAge" << endl;
        for (auto i = abonents.begin(); i != abonents.end(); ++i)
        {
            ss << (*i).toString() << endl;
            //cout << ss.str() << endl;
        }
        return ss.str();
    }

    vector<Abonent> getAll() const
    {
        return abonents;
    }
};

class FileManager
{
public:
    static bool WriteToFile(const char* fileName, PhoneBook book)
    {
        ofstream fWrite;
        if (fileName != nullptr)
        {
            fWrite.open(fileName, ios::out);
            if (fWrite.is_open())
            {
                fWrite << book.toString();
				fWrite.close();
                return true;
            }
        }
        return false;
    }

    static PhoneBook ReadFile(const char* fileName)
    {
        PhoneBook book;
        ifstream fRead;
        if (fileName != nullptr)
        {
            fRead.open(fileName);
            if (fRead.is_open())
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

                while (fRead >> strName >> strAge >> strPhone)
                {
                    Abonent temp(strName, atoi(strAge), strPhone);
                    book.add(temp);
                }
            }
        }
        fRead.close();
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
    m.push_back("1) Add");
    m.push_back("2) Remove");
    m.push_back("3) Find");
    m.push_back("4) Show all");
    m.push_back("5) Save to file");
    m.push_back("6) Download from file");
    m.push_back("7) Exit");

    return m;
}

Abonent createAbonent()
{
    char* name = new char[100];
    char* phone = new char[100];
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
#ifndef DEBUGING 
    PhoneBook book;
#else
    PhoneBook book = SeedData();
#endif
    vector<string> m = initMenu();

    while (true)
    {
        switch (menu(m))
        {
        case 1:
        {
            book.add(createAbonent());
            cls();
            break;
        }
        case 2:
        {
            char* name = new char[100];
            cout << "Enter name: ";
            cin.getline(name, 100);
            book.remove(name);
            cls();
            break;
        }
        case 3:
        {
            char* name = new char[100];
            cout << "Enter name to search: ";
            cin.getline(name, 100);
            PhoneBook found = book.find(name);
            cout << found.toString() << endl;
        		//vector l = book.find();
        		//for (auto abon : l) { cout << abon.ToString() << endl;
        		//
        		//PhoneBook found = book.find();
        		//cout << found.toString();

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
            cin.getline(fileName, 100);
            FileManager::WriteToFile(fileName, book);

            if (fileName != nullptr)
            {
                delete[]fileName;
            }
            cls();
            cout << "Successfully!" << endl;
            //cin.get();

            break;
        }
        case 6:
        {
            char* fileName = new char[100];
            cout << "Enter file name: ";
            cin.getline(fileName, 100);
            book = FileManager::ReadFile(fileName);

            if (fileName != nullptr)
            {
                delete[]fileName;
            }
            cls();
            cout << "Successfully!" << endl;
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
    system("chcp 1251 > nul");
    PhoneBook book = SeedData();
    //book.SeedData();
    app();

    return 0;
}