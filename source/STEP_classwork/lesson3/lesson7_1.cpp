#include <iostream>
#include <string>
using namespace std;

#define Get(name, type) type, Get_##name(){ return name; }

class Product
{
    private:
        //string name;
        char name[50];
        double cost;

        bool nameValidCheck(const char* str)
        {
            return true;
        }
    public:
        void setName(const char* _name)
        {
            if (nameValidCheck(_name))
            {
                strcpy(name, _name);
            }
        }

        void setCost(double _cost)
        {
            if (_cost >= 0)
            {
                cost = _cost;
            }
        }

        const char* getName()
        {
            return name;
        }

        double getCost() const
        {
            return cost;
        }
        
};

class CleverMas
{
    private:
        int* mas;
        int size;
    public:
};

class Man
{
    private:
        char name[50];
        int age;
        double weight;
    public:
        Man() : age(0), weight(0)
        {
            cout << "MAN" << endl;
            name[0] = '\0';
            //age = 0;
            //weight = 0;
        }

        /*Man(const char* NAME = "", int AGE = 0, double WEIGHT = 0)
        {
            cout << "MAN" << endl;
            age = 0;
            weight = 0;
            name[0] = '\0';
            //if (NameValidCheck
            setName(NAME);
            setAge(AGE);
            setWeight(WEIGHT);
        }*/

        void setName(const char* _name)
        {
            if (strlen(_name) < 50)
            {
                strcpy(name, _name);
            }
        }

        void setAge(const int old)
        {
            if (old >= 0)
            {
                age = old;
            }
        }

        void setWeight(const double wght)
        {
            if (wght >= 0)
            {
                weight = wght;
            }
        }

        /*const char * getName()
        {
            return name;
        }*/
        Get(name, char*);
        Get(age, int);
        Get(weight, double);

        const int getAge()
        {
            return age;
        }

        const double getWeight()
        {
            return weight;
        }
};

class Point
{
    private:
        int x;
        int y;
        int z;
    public:
        Point()
        {
            x = 0;
            y = 0;
            z = 0;
        }
        
        Point(int _x, int _y, int _z) : Point()
        {
            setX(_x);
            setY(_y);
            setZ(_z);
        }

        void setX(int _x_)
        {
            x = _x_;
        }

        void setY(int _y_)
        {
            y = _y_;
        }

        void setZ(int _z_)
        {
            z = _z_;
        }
};

int main()
{
    Man man;
    //Man man2;
    //Man man3;
    /*char str[50];
    int a;
    double w;
    cout << "Enter name: ";
    cin.getline(str, 50);
    cout << "Enter age: ";
    cin >> a;
    cin.get();
    cout << "Enter weight: ";
    cin >> w;

    man.setName(str);
    man.setAge(a);
    man.setWeight(w);

    cout << man.getName() << endl;
    cout << man.getAge() << endl;
    cout << man.getWeight() << endl;*/
    /*Product prd;
    prd.setName("Marlboro");
    prd.setCost(520);

    cout << prd.getName << endl;
    cout << prd.getCost << endl;*/

    //CleverMas cm;

}
