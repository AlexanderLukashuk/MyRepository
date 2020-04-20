#include <sstream>
#include "../include/copy.hpp"

Book::Book() : name(nullptr), author(nullptr), pages(0) {}

Book::Book(const char* name, const char* author, int pages)
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

    if (pages > 0)
    {
        this->pages = pages;
    }
}

Book::Book(const Book& obj)
{
    if (obj.name != nullptr)
    {
        this->name = new char[strlen(obj.name) + 1];
        strcpy(this->name, obj.name);
    }

    if (obj.author != nullptr)
    {
        this->author = new char[strlen(obj.author) + 1];
        strcpy(this->author, obj.author);
    }

    this->pages = pages;
}

Book::~Book()
{
    if (this->name != nullptr)
    {
        delete[]name;
    }

    if (this->author != nullptr)
    {
        delete[]author;
    }
}

void Book::setName(const char* name)
{
    if (name != nullptr)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
}

void Book::setAuthor(const char* author)
{
    if (author != nullptr)
    {
        this->author = new char[strlen(author) + 1];
        strcpy(this->author, author);
    }
}

void Book::setPages(int pages)
{
    this->pages = pages;
}

char* Book::getName()
{
    return name;
}

char* Book::getAuthor()
{
    return author;
}

int Book::getPages()
{
    return pages;
}

std::string Book::toString() const
{
    using std::endl;
    std::stringstream ss;
    ss << "Name: " << name << endl;
    ss << "Author: " << author << endl;
    ss << "Pages: " << pages << endl;
    return ss.str();
}