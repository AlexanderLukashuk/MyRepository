#include <iostream>
#include <string>
#include <vector>
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
    Book() : price(0) {}
    Book(const string &name, const string &author, const string &description, const string &publisher, double price)
        : name(name), author(author), description(description), publisher(publisher)
    {
        /*if (name.empty() != true)
        {
            this->name = name;
        }

        if (author.empty() != true)
        {
            this->author = author;
        }

        if (description.empty() != true)
        {
            this->description = description;
        }

        if (publisher.empty() != true)
        {
            this->publisher = publisher;
        }*/

        if (price >= 0.0)
        {
            this->price = price;
        }
    }

    Book(const char *name, const char *author, const char *description, const char *publisher, double price) : price(0)
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
};

ostream &operator<<(ostream &out, const Book &obj)
{
    out << "Book: " << obj.name << endl;
    out << "Author: " << obj.author << endl;
    out << "Publisher: " << obj.publisher << endl;
    out << "Description: " << obj.description << endl;
    out << "Price: " << obj.price << endl;
    
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

    return in;
}

#pragma endregion

class Warehouse
{
private:
    vector<Book> books;
    friend ostream &operator<<(ostream &out, const Warehouse &obj);
    void operator=(initializer_list<Book> list) {}
public:
    Warehouse() {}
    Warehouse(initializer_list<Book> list) 
    {
        cout << "CONSTR" << endl;
    }

    //void addBook() {}

    void addBook(const Book& b) {}
    const Book& findBooksByName(string name) {}
    const Book& findBooksByAuthor(string author) {}
    void removeBook(string name, int count) {}


    
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


int main()
{
    Book book{"dsad", "asfa", "asfa", "asfa", 124};
    
    // cin >> book;
    // cout << book;

    // Book book1("asd", "asd", "asd", "asd", 120);
    // cout << endl << book1;

    // Warehouse wh (initializer_list<Book>( 
	// 	{"M&M1","Bulgakov","Good book","ECSMO", 1000},
	// 	{"M&M2","Bulgakov","Good book","ECSMO", 1000},
	// 	{"M&M3","Bulgakov","Good book","ECSMO", 1000} ));

    // cout << wh << endl;

    /*string str;

    getline(cin, str);
    cout << str << endl;

    string str1 = str.substr(5, 3);
    cout << str1 << endl;*/
}