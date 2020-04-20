#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    /*string other = "World!";

    //string str("Hello");
    //string str = "Hello";
    //str = other;

    string str;
    str.reserve(100);
    str = "Hello";
    //str = "Bye";
    cout << "empty? - " << str.empty() << endl;
    cout << "size = " << str.size() << endl;
    cout << "lenght = " << str.length() << endl;
    cout << str << endl;*/

//------------------------------------------
    /*string str;
    str.resize(100);
    cout << "empty? - " << str.empty() << endl;
    cout << "size = " << str.size() << endl;
    cout << "lenght = " << str.length() << endl;
    //cout << str << endl;

    str[0] = 'H';
    str[1] = 'H';
    str[2] = 'H';
    cout << str << endl;

    str.at(0) = 'W';
    cout << str << endl;*/

//-------------------------------------------------

    /*string str1 = "Hello ";
    string str2 = "World!";
    string str3;
    cout << str1 + str2 << endl;
    cout << str1 << endl;
    str3 = str1 + str2;
    cout << str3 << endl;*/

//------------------------------------------------

    /*string str1 = "Hello ";
    string str2 = "World!";
    str1 += str2;
    str1 += "!!!!!!!!!!!";
    str1.append("$$$$$$$");
    cout << str1 << endl;*/

//-------------------------------------------------

    /*string str;
    cin.get();
    str.reserve(1000);
    cout << str.capacity() << endl;
    str = "wqeqeqeqeqeqeq";
    cout << str.capacity() << endl;
    //str.clear();

    string str1;
    str1.reserve(10);
    cout << str1.capacity() << endl;
    str1 = "wqeqeqafsdsgdgfdhsgdhdfgfdgdheqeqeqeq";
    cout << str1.capacity() << endl;

    string str2 = "afjsdngdnsgndfngsng";
    str2.reserve(10);
    cout << str2.capacity() << endl;

    str2.resize(10);
    cout << str2 << endl;
    cout << str2.capacity() << endl;*/

    /*string str3 = "fdsnsngsbfhkbajs,gjdhjdsjfndskhgksabcbdbasfhmdbsfbsyf";
    cout << str3.capacity() << endl;
    str3 = "12";
    cout << str3.capacity() << endl;*/

    //NEVER DON'T DO IT
    /*char* ptr = const_cast<char*>(str3.c_str());
    for (int i = 0; i < 1000; i++)
    {
        ptr[i] = '1';
    }*/

//-------------------------------------------------

    //cout << str.capacity() << endl;
    //str = "asd";
    //cout << str.capacity() << endl;
    //str.shrink_to_fit();
    //cout << str.capacity() << endl;

    /*string other = "asdfrtgy";
    string str = "asdfetgy";
    cout << str.compare(3, 3, other, 0, 3) << endl;*/

    //str.c_str();

    /*string str = "123456789";
    //str.replace(2, 4, "abcdefg", 2, 3);
    //cout << str << endl;
    str.erase(3, 3);
    cout << str << endl;*/

//--------------------------------------------------

    /*string str = "AsDaSdAsD";
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << str << endl;*/

//------------------------------------------------

    /*string str = "12341444444123";
    cout << str.find("41") << endl;
    cout << str.find("41", 4) << endl;
    cout << str.rfind("41") << endl;

    cout << str.find_first_not_of("123") << endl;
    cout << str.find_last_not_of("123") << endl;
    
    string str1 = "111asd111";
    cout << str1.find_first_of("dsa") << endl;
    cout << str1.find_last_of("asd") << endl;

    char strC[100];
    str1.copy(strC, 3, 0);
    cout << str1 << endl;
    cout << strC << endl;*/

//-------------------------------------------------------

    

}