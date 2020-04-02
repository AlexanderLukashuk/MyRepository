#ifndef __DATE_MANAGER_H_
#define __DATE_MANAGER_H_
#include <map>
#include "date.h"

class Date;

class DateManager
{
private:
    std::map<int, int> dictionary;
public:
    //bool check(int month, int day);
    //Date date();
    static std::map<int,int> InitMap()
    {
        std::map<int, int> dictionary;

        dictionary.insert(std::pair<int, int>(1, 31));
        dictionary.insert(std::pair<int, int>(2, 28));
        dictionary.insert(std::pair<int, int>(3, 31));
        dictionary.insert(std::pair<int, int>(4, 30));
        dictionary.insert(std::pair<int, int>(5, 31));
        dictionary.insert(std::pair<int, int>(6, 30));
        dictionary.insert(std::pair<int, int>(7, 31));
        dictionary.insert(std::pair<int, int>(8, 31));
        dictionary.insert(std::pair<int, int>(9, 30));
        dictionary.insert(std::pair<int, int>(10, 31));
        dictionary.insert(std::pair<int, int>(11, 30));
        dictionary.insert(std::pair<int, int>(12, 31));

        return dictionary;
    }
};
#endif