#include <iostream>
#include <list>
#include <time.h>
using namespace std;

class Starter
{
public:
    Starter()
    {
        srand(time(0));
    }
} starter;

class Entity
{
    static long long counter;

protected:
    long long Id;
    Entity()
    {
        //Id = static_cast<long long>(rand() * rand() * rand() * rand());
        Id = counter;
        counter++;
    }

public:
    virtual ~Entity() {}
    long long getId() const
    {
        return Id;
    }
};
long long Entity::counter = 0;

class AstronomicalObject : public Entity
{
protected:
    string name;
    double massa;
    double radius;
    AstronomicalObject() : massa(), radius() {}
    AstronomicalObject(const string &name, const double massa, const double radius) : name(name), massa(massa), radius(radius) {}

public:
    void setName(const string& name)
    {
        this->name = name;
    }

    void setMassa(const double massa)
    {
        this->massa = massa;
    }

    void setRadius(const double radius)
    {
        this->radius = radius;
    }

    const string &getName() const
    {
        return name;
    }

    double getMassa() const
    {
        return massa;
    }

    double getRadius() const
    {
        return radius;
    }
};

class Satellite : public AstronomicalObject
{
    friend ostream &operator<<(ostream &out, const Satellite &satellite);

public:
    Satellite() {}
    Satellite(const string &name, const double massa, const double radius) : AstronomicalObject(name, massa, radius) {}
};

ostream &operator<<(ostream &out, const Satellite &satellite)
{
    out << "ID: " << satellite.getId() << endl;
    out << "Name: " << satellite.name << endl;
    out << "Massa: " << satellite.massa << endl;
    out << "Radius: " << satellite.radius << endl;

    return out;
}

class Planet : public AstronomicalObject
{
    list<Satellite> satellites;
    friend ostream &operator<<(ostream &out, const Planet &satellite);

public:
    Planet() {}
    Planet(const string &name, const double massa, const double radius, const list<Satellite>& satellites) : AstronomicalObject(name, massa, radius), satellites(satellites) {}
    Planet(const string &name, const double massa, const double radius, list<Satellite>&& satellites) : AstronomicalObject(name, massa, radius), satellites(satellites) {}
    
    void addSatellite(const Satellite &s)
    {
        satellites.push_back(s);
    }

    void deleteSatellite(const Satellite &s)
    {
        for (auto it = satellites.begin(); it != satellites.end(); ++it)
        {
            if (it->getId() == s.getId())
            {
                satellites.erase(it);
                break;
            }
        }
    }

    Satellite &operator[](int pos)
    {
        for (auto &el : satellites)
        {
            if (pos == 0)
            {
                return el;
            }
            pos--;
        }
    }
};

ostream &operator<<(ostream &out, const Planet &planet)
{
    out << "ID: " << planet.getId() << endl;
    out << "Name: " << planet.name << endl;
    out << "Massa: " << planet.massa << endl;
    out << "Radius: " << planet.radius << endl;

    for (auto el : planet.satellites)
    {
        out << el << endl;
    }

    return out;
}


class IDataAccessService
{
public:
    virtual void addAstronomicalObject(const AstronomicalObject& obj) = 0;
    virtual void deleteAstronomicalObject(const AstronomicalObject& obj) = 0;
    virtual void editAstronomicalObject(const AstronomicalObject& obj) = 0;

};

class DataAccessService : public IDataAccessService
{
list<unique_ptr<AstronomicalObject>> astronomicalObjects;
public:
};

int main()
{
    unique_ptr<IDataAccessService> dataService = make_unique<DataAccessService>();


    /*list<Planet> l;
    for (int i = 0; i < 1000; i++)
    {
        l.push_back(Planet());
        cout << l.back().getId() << endl;
    }*/

    /*int count;
    for (auto el1 : l)
    {
        count = 0;
        for (auto el2 : l)
        {
            if (el1.getId() == el2.getId())
            {
                count++;
            }
        }

        if (count > 1)
        {
            cout << "OH NOOOOOO" << endl;
        }
        //cout << el.getId() << endl;
    }*/
    //AstronomicalObject a;
    //cout << a.getId() << endl;
}