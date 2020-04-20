#include <iostream>
#include <string>
#include <queue>
#include <time.h>
using namespace std;

class Abiturient
{
private:
    string name;
    int ENT;
    friend ostream& operator<<(ostream& out, const Abiturient& obj);
    //friend bool operator<(const Abiturient& l, const Abiturient& r);
public:
    Abiturient() : ENT() {}
    Abiturient(string name) : name(name)
    {
        this->ENT = rand() % 60 + 60;
    }

    const string& getName() const
    {
        return name;
    }

    int getENT() const
    {
        return ENT;
    }
};

ostream& operator<<(ostream& out, const Abiturient& obj)
{
    out << obj.name;
    return out;
}

bool operator<(const Abiturient& l, const Abiturient& r)
{
    return l.getENT() < r.getENT();
}

bool operator>=(const Abiturient& obj, int score)
{
    return obj.getENT() >= score;
}

bool operator<=(const Abiturient& obj, int score)
{
    return obj.getENT() <= score;
}

int main()
{
    srand(time(0));
    priority_queue<Abiturient> que;
    int grant = rand() % 5;
    int max_size = 10;
    int passingScore = 70;
    string buff;

    que.push(Abiturient("Bob"));
    que.push(Abiturient("Alex"));
    que.push(Abiturient("Jack"));
    que.push(Abiturient("John"));
    que.push(Abiturient("Dima"));
    que.push(Abiturient("Bogdan"));
    que.push(Abiturient("Danil"));
    que.push(Abiturient("June"));
    que.push(Abiturient("Jill"));
    que.push(Abiturient("Chloe"));

    cout << "Numbe of grant: " << grant << endl;
    cout << endl;

    /*while (max_size--)
    {
        getline(cin, buff);
        que.push(Abiturient(buff));
    }*/

    while (!que.empty())
    {
        if (que.top() >= passingScore && grant > 0)
        {
            cout << que.top().getName() << " passed to a grant" << endl;
            cout << que.top() << " has " << que.top().getENT() << " points for ENT" << endl;
            grant--;
        }
        else if (que.top() >= passingScore && grant == 0)
        {
            cout << que.top().getName() << " passed to a paid tuition" << endl;
            cout << que.top() << " has " << que.top().getENT() << " points for ENT" << endl;
        }
        else if (que.top() <= passingScore)
        {
            cout << que.top().getName() << " failed exam" << endl;
            cout << que.top() << " has " << que.top().getENT() << " points for ENT" << endl;
        }
        que.pop();
    }
}