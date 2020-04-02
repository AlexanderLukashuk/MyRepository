#include <iostream>
using namespace std;

class Book
{
    private:
        char* name;
        char* author;
        double price;
    public:
        Book() : name(nullptr), author(nullptr), price(0.0) {}
        Book(const char* name, const char* author, double price) : Book()
        {
            if (name != nullptr)
            {
                this->name = new char[strlen(name) + 1];
                strcpy(this->name, name);
            }

            if (author != nullptr)
            {
                this->author = new char[strlen(author) + 1];
                strcpy(this->author, author);
            }
            if (price >= 0.0)
            {
                this->price = price;
            }
        }
        Book(const Book& obj) : name(nullptr), author(nullptr),  price(obj.price)
        {
            cout << "CTOR COPY\n";
            if (obj.name != nullptr)
            {
                name = new char[strlen(obj.name) + 1];
                strcpy(name, obj.name);
            }

            if (obj.author != nullptr)
            {
                author = new char[strlen(obj.author) + 1];
                strcpy(author, obj.author);
            }
            
            //price = obj.price;
        }

        Book(Book&& obj)
        {
            cout << "CTOR PEREMEH\n";
            name = obj.name;
            obj.name = nullptr;
            author = obj.name;
            obj.author = nullptr;
            price = obj.price;
        }

        ~Book() 
        {
            delete[]name;
            delete[]author;
        }

        void input() 
        {
            delete[]name;
            delete[]author;

            char* str = new char[100];
            int pr;
            cout << "Enter name of book: ";
            cin.getline(str, 100);
            name = new char[strlen(str) + 1];
            strcpy(name, str);
            /*if (str == nullptr)
            {
                while (str == nullptr)
                {
                    cout << "Enter name of book again: ";
                    cin.getline(str, 100);
                }

                this->name = new char[strlen(str) + 1];
                strcpy(this->name, str);
            }
            else
            {
                this->name = new char[strlen(str) + 1];
                strcpy(this->name, str);
            }*/

            cout << "Enter author of book: ";
            cin.getline(str, 100);
            author = new char[strlen(str) + 1];
            strcpy(author, str);
            /*if (str == nullptr)
            {
                while (str == nullptr)
                {
                    cout << "Enter name of book again: ";
                    cin.getline(str, 100);
                }

                this->author = new char[strlen(str) + 1];
                strcpy(this->author, str);
            }
            else
            {
                this->author = new char[strlen(str) + 1];
                strcpy(this->author, str);
            }*/


            cout << "Enter price: ";
            while (!(cin >> price))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (price < 0)
            {
                price = 0;
            }
            

            /*if (price <= 0.0)
            {
                while (price <= 0.0)
                {
                    cout << "Enter price again: ";
                    cin >> pr;
                }

                this->price = pr;
            }
            else
            {
                this->price = pr;
            }*/

            delete[]str;
        }
        void show() const
        {
            cout << "Name of book: " << name << endl;
            cout << "Author: " << author << endl;
            cout << "Price: " << price << endl;
        }

        void operator=(const Book& obj)
        {
            if (name != nullptr)
            {
                delete[]name;
                name = nullptr;
            }

            if (author != nullptr)
            {
                delete[]author;
                author = nullptr;
            }

            if (obj.name != nullptr)
            {
                name = new char[strlen(obj.name) + 1];
                strcpy(name, obj.name);
            }

            if (obj.author != nullptr)
            {
                author = new char[strlen(obj.author) + 1];
                strcpy(author, obj.author);
            }

            price = obj.price;
        }

        void operator=(Book&& obj)
        {
            if (name != nullptr)
            {
                delete[]name;
                name = nullptr;
            }

            if (author != nullptr)
            {
                delete[]author;
                author = nullptr;
            }

            cout << "CTOR PEREMEH\n";
            name = obj.name;
            obj.name = nullptr;
            author = obj.name;
            obj.author = nullptr;
            price = obj.price;
        }

        void setName(const char* name)
        {
            if (this->name != nullptr)
            {
                delete[]name;
                name = nullptr;
            }

            if (name != nullptr)
            {
                this->name = new char[strlen(name) + 1];
                strcpy(this->name, name);
            }
        }

        void setAuthor(const char* author)
        {
            if (this->author != nullptr)
            {
                delete[]author;
                author = nullptr;
            }

            if (author != nullptr)
            {
                this->author = new char[strlen(author) + 1];
                strcpy(this->author, author);
            }
        }

        void setPrice(double price)
        {
            if (price >= 0)
            {
                this->price = price;
            }
        }

        const char* getName()
        {
            return name;
        }

        const char* getAuthor()
        {
            return author;
        }

        double getPrice()
        {
            return price;
        }


};

void func(Book b)
{

}

Book func1()
{
    Book res;
    return res;
}

int main()
{
    Book book(func1());
    //Book book;
    //func(book);
    // Book book("Shantaram", "G. D. Roberts", 4500);
    // Book book2;
    // // book1.input();
    // // book.show();
    // // book1.show();

    // book2 = book;

    
}