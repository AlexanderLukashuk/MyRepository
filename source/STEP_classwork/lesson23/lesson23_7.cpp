#include <iostream>
using namespace std;

class Weapon
{
protected:
    string name;
    double damage;
    int range; // длина атаки
public:
    Weapon() : damage(), range() {}
    Weapon(string name, double damage, int range) : name(name), damage(damage), range(range) {}

    void attack(int distance)
    {
        if (range >= distance)
        {
            cout << "The attack was done by " << name << endl;
            cout << "Damage taken " << damage << endl;
        }
        else
        {
            cout << "Miss" << endl;
        }
    }
};

class Sword : public Weapon
{
protected:
    string material;

public:
    Sword() {}
    Sword(string material, double damage, int range)
        : material(material), Weapon("Sword", damage, range) {}

    void attack(int distance)
    {
        if (range >= distance)
        {
            cout << "The attack was done by " << material << " " << name << endl;
            cout << "Damage taken " << damage << endl;
        }
        else
        {
            cout << "Miss" << endl;
        }
    }
};

class Bow : public Weapon
{
protected:
    int maxDistance;

public:
    Bow() : maxDistance() {}
    Bow(int maxDistance, double damage, int range)
        : maxDistance(maxDistance), Weapon("Wooden dow", damage, range) {}

    void attack(int distance)
    {
        if (maxDistance >= distance)
        {
            cout << "The attack was done by " << name << endl;
            cout << "Damage taken " << damage << endl;
        }
        else
        {
            cout << "Miss" << endl;
        }
    }
    //int accuracy; //точность выстрела
};

class Ward : public Weapon
{
protected:
    string element;

public:
    Ward() {}
    Ward(string element, double damage, int range)
        : element(element), Weapon("Ward", damage, range) {}

    void attack()
    {
        cout << "The attack was done by " << name << " with element " << element << endl;
        cout << "Damage taken " << damage << endl;
    }
};

int main()
{
    Sword sw("Silver", 12.5, 1.5);
    sw.attack(1);
    sw.attack(2);

    Bow b(100, 5, 1);
    b.attack(90);
    b.attack(110);

    Ward w("Fire", 20, 1.5);
    w.attack();
    w.attack();
}