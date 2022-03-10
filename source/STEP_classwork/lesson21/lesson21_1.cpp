#include <iostream>
#include <map>
using namespace std;

int main()
{
    //map<int, string> m;
    //map<int, string> m;
    multimap<string, int> m;

    //m.insert(pair<int, string>(1, "Igor"));
    //m.insert(pair<int, string>(2, "Mariya"));
    //m.insert(pair<int, string>(3, "Ksenia"));
    
    m.insert(pair<string, int>("Ksenia", 19));
    m.insert(pair<string, int>("Danil", 24));
    m.insert(pair<string, int>("Ksenia", 21));

    //m.emplace(pair<string, int>("Ksenia", 23));

    for (auto el : m)
    {
        cout << el.first << " " << el.second << endl;
    }
}