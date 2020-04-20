#ifndef _COPY_H_
#define _COPY_H_
#include <sstream>

class Book
{
private:
    char* name;
    char* author;
    int pages;
public:
    Book();
    Book(const char* name, const char* author, int pages);
    Book(const Book& obj);
    ~Book();

    void setName(const char* name);
    void setAuthor(const char* author);
    void setPages(int pages);
    char* getName();
    char* getAuthor();
    int getPages();

    std::string toString() const;
};
#endif