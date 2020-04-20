#ifdef _WIN32
#define cls() system("cls")
#else
#define cls() system("clear")
#endif
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <initializer_list>
using namespace std;

#pragma region BookRegion

class Book
{
private:
    string name;
    string author;
    string description;
    string publisher;
    double price;
    int count;
    friend ostream &operator<<(ostream &out, const Book &obj);
    friend istream &operator>>(istream &in, Book &obj);

public:
    Book() : price(0), count(0) {}
    Book(const string &name, const string &author, const string &description, const string &publisher, double price, int count)
        : name(name), author(author), description(description), publisher(publisher)
    {
        if (price >= 0.0)
        {
            this->price = price;
        }

        if (count > 0)
        {
            this->count = count;
        }
    }

    Book(const char *name, const char *author, const char *description, const char *publisher, double price, int count) : price(0), count(0)
    {
        if (name != nullptr)
        {
            this->name = name;
        }

        if (author != nullptr)
        {
            this->author = author;
        }

        if (description != nullptr)
        {
            this->description = description;
        }

        if (publisher != nullptr)
        {
            this->publisher = publisher;
        }

        if (price >= 0.0)
        {
            this->price = price;
        }

        if (count > 0)
        {
            this->count = count;
        }
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setAuthor(string author)
    {
        this->author = author;
    }

    void setDescription(string description)
    {
        this->description = description;
    }

    void setPublisher(string publisher)
    {
        this->publisher = publisher;
    }

    void setName(const char *name)
    {
        if (name != nullptr)
        {
            this->name = name;
        }
    }

    void setAuthor(const char *author)
    {
        if (author != nullptr)
        {
            this->author = author;
        }
    }

    void setDescription(const char *description)
    {
        if (description != nullptr)
        {
            this->description = description;
        }
    }

    void setPublisher(const char *publisher)
    {
        if (publisher != nullptr)
        {
            this->publisher = publisher;
        }
    }

    void setPrice(double price)
    {
        if (price >= 0.0)
        {
            this->price = price;
        }
    }

    void setCount(int count)
    {
        if (count > 0)
        {
            this->count = count;
        }
    }

    string getName() const
    {
        return name;
    }

    string getAuthor() const
    {
        return author;
    }

    string getPublisher() const
    {
        return publisher;
    }

    string getDescription() const
    {
        return description;
    }

    double getPrice() const
    {
        return price;
    }

    int getCount() const
    {
        return count;
    }

    string toString() const
    {
        stringstream ss;
        ss << "Name: " << name << endl;
        ss << "Author: " << author << endl;
        ss << "Description: " << description << endl;
        ss << "Publisher: " << publisher << endl;
        ss << "Price: " << price << endl;
        ss << "Count: " << count << endl;

        return ss.str();
    }
};

ostream &operator<<(ostream &out, const Book &obj)
{
    out << "Book: " << obj.name << endl;
    out << "Author: " << obj.author << endl;
    out << "Publisher: " << obj.publisher << endl;
    out << "Description: " << obj.description << endl;
    out << "Price: " << obj.price << endl;
    out << "Count of books: " << obj.count << endl;
    
    return out;
}

istream &operator>>(istream &in, Book &obj)
{
    cout << "Enter name of book: ";
    getline(in, obj.name);
    cout << "Enter author: ";
    getline(in, obj.author);
    cout << "Enter description: ";
    getline(in, obj.description);
    cout << "Enter publicsher: ";
    getline(in, obj.publisher);
    cout << "Enter price: ";
    in >> obj.price;
    cin.get();
    cout << "Enter count of books: ";
    in >> obj.count;

    return in;
}

#pragma endregion

class Warehouse
{
private:
    vector<Book> books;
    friend ostream &operator<<(ostream &out, const Warehouse &obj);
public:
    Warehouse() : books() {}

    void addBook(const Book& b) 
    {
        books.push_back(b);
    }

    Warehouse findBooksByName(string name) 
    {
        Warehouse result;

        for (auto i = books.begin(); i != books.end(); ++i)
        {
            string bookName = (*i).getName();
            size_t found = bookName.find(name);
            if (found != string::npos)
            {
                result.addBook(*i);
            }
        }
        
        return result;
    }

    Warehouse findBooksByAuthor(string author)
    {
        Warehouse result;

        for (auto i = books.begin(); i != books.end(); ++i)
        {
            string bookAuthor = (*i).getAuthor();
            size_t found = bookAuthor.find(author);
            if (found != string::npos)
            {
                result.addBook(*i);
            }
        }
        
        return result;
    }
    
    void removeBook(string name, int count) 
    {
        for (int i = 0, j = 1; i < books.size(); i++)
        {
            if (name == books[i].getName() && (books[i].getCount() - count) == 0)
            {
                books.erase(books.begin() + i);
            }
            else if (name == books[i].getName() && books[i].getCount() == 1)
            {
                books.erase(books.begin() + i);
            }
            else if ((books[i].getCount() - count) < 1)
            {
                return;
            }
            else if (name == books[i].getName() && count > 1)
            {
                books[i].setCount(books[i].getCount() - count);
            }
        }
    }

    string toString() const
    {
        stringstream ss;
        for (auto i = books.begin(); i != books.end(); ++i)
        {
            ss << (*i).toString() << endl;
            //cout << ss.str() << endl;
        }
        return ss.str();
    }
};

ostream &operator<<(ostream &out, const Warehouse &obj)
{
    cout << "Warehouse: \n\n";
    for (auto el : obj.books)
    {
        out << el << endl;
    }
    return out;
}

int menu(const vector<string> menuTitles)
{
    int result = -1;

    cout << "Choose option: " << endl;
    for (auto s : menuTitles)
    {
        cout << s << endl;
    }
    cin >> result;
    cin.get();

    return result;
}

vector<string> initMenu()
{
    vector<string> m;
    m.push_back("1) Add");
    m.push_back("2) Remove");
    m.push_back("3) Find by name of book");
    m.push_back("4) Find by author");
    m.push_back("5) Show all");
    m.push_back("6) Exit");

    return m;
}

Book createBook()
{
    Book book;
    cin >> book;

    return book;
}

void app()
{
    Warehouse wh;
    vector<string> m = initMenu();
    while (true)
    {
        switch (menu(m))
        {
            case 1:
            {
                wh.addBook(createBook());
                cls();
                break;
            }
            case 2:
            {
                string name;
                int count;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter how many books you want to delete: ";
                cin >> count;
                cin.get();
                wh.removeBook(name, count);
                cls();
                break;
            }
            case 3:
            {
                string name;
                cout << "Enter name to search: ";
                getline(cin, name);
                Warehouse found = wh.findBooksByName(name);
                cout << found.toString() << endl;
                break;
            }
            case 4:
            {
                string author;
                cout << "Enter author to search: ";
                getline(cin, author);
                Warehouse found = wh.findBooksByAuthor(author);
                cout << found.toString() << endl;
                break;
            }
            case 5:
            {
                cout << wh.toString() << endl;
                cout << "Press enter to continue...";
                cin.get();
                cls();
                break;
            }
            case 6:
            {
                cout << "Good job\nBye\n";
                return;
                break;
            }
        }
    }
}


int main()
{
    app();

    return 0;
}