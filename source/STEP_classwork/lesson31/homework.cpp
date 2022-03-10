#include <iostream>
#include <string>
#include <list>
using namespace std;

class Planet
{
    string name;
    double weight;
    double radius;
    friend ostream &operator<<(ostream &out, const Planet &planet);

public:
    Planet() : weight{}, radius{} {}
    Planet(const string &name, const double weight, const double radius)
        : name{name}, weight{}, radius{}
    {
        SetWeight(weight);
        SetRadius(radius);
    }

    void SetName(const string &name)
    {
        this->name = name;
    }
    void SetWeight(const double weight)
    {
        if (weight < 0)
            throw "Weight is negative";
        this->weight = weight;
    }
    void SetRadius(const double radius)
    {
        if (radius < 0)
            throw "Radius is negative";
        this->radius = radius;
    }
    const string &GetName() const
    {
        return name;
    }
    double GetWeight() const
    {
        return weight;
    }
    double GetRadius() const
    {
        return radius;
    }
};

bool operator==(const Planet &l, const Planet &r)
{
    return (l.GetName() == r.GetName() && l.GetRadius() == r.GetRadius() && l.GetWeight() == r.GetWeight());
}

ostream &operator<<(ostream &out, const Planet &planet)
{
    out << "Name: " << planet.name << endl;
    out << "Weight: " << planet.weight << " kg." << endl;
    out << "Radius: " << planet.radius << " km." << endl;
    return out;
}

class Galaxy
{
    string name;
    list<Planet> planets;
    friend ostream &operator<<(ostream &out, const Galaxy &galaxy);

public:
    Galaxy() {}
    Galaxy(const string &name, const list<Planet> &planets) : name(name), planets(planets) {}
    Galaxy(const string &name, list<Planet> &&planets) : name(name), planets(planets) {}

    void AddPlanet(const Planet &planet)
    {
        planets.push_back(planet);
    }
    void DeletePlanet(const Planet &planet)
    {
        //planets.remove(planet);
        for (auto i = planets.begin(); i != planets.end(); i++)
        {
            if (i->GetName() == planet.GetName())
            {
                planets.erase(i);
                break;
            }
        }
    }

    Planet &operator[](int pos)
    {
        try
        {
            for (auto &el : planets)
            {
                if (pos == 0)
                    return el;
                pos--;
            }
        }
        catch (...)
        {
            //TODO жобавть логирование
        }
    }
    void SetName(const string &name)
    {
        this->name = name;
    }
    const string &GetName() const
    {
        return name;
    }
};

ostream &operator<<(ostream &out, const Galaxy &galaxy)
{
    out << "Galaxy: " << galaxy.name << endl
        << endl;
    for (auto el : galaxy.planets)
        out << el << endl;
    return out;
}

// Реализовать класс Universe
class Universe
{
    string name;
    list<Galaxy> galaxies;
    friend ostream &operator<<(ostream &out, const Universe &universe);

public:
    Universe() {}
    Universe(const string &name, const list<Galaxy> &galaxies) : name(name), galaxies(galaxies) {}
    Universe(const string &name, list<Galaxy> &&galaxies) : name(name), galaxies(galaxies) {}
    // методы по аналогии с Галактикой

    void AddGalaxy(const Galaxy &galaxy)
    {
        galaxies.push_back(galaxy);
    }
    void DeletePlanet(const Galaxy &galaxy)
    {
        //planets.remove(planet);
        for (auto i = galaxies.begin(); i != galaxies.end(); i++)
        {
            if (i->GetName() == galaxy.GetName())
            {
                galaxies.erase(i);
                break;
            }
        }
    }

    Galaxy &operator[](int pos)
    {
        for (auto &el : galaxies)
        {
            if (pos == 0)
                return el;
            pos--;
        }
    }

    void SetName(const string &name)
    {
        this->name = name;
    }

    const string &GetName() const
    {
        return name;
    }
};

ostream &operator<<(ostream &out, const Universe &universe)
{
    out << "Universe: " << universe.name << endl
        << endl;
    for (auto el : universe.galaxies)
    {
        out << el << endl;

    }
    return out;
}

void main()
{
    //Planet p("Earth", 5.972e24, 6400);
    //cout << p;

    //list<Planet> planets{ Planet("a", 1, 1), Planet("b", 2, 2) };
    //Galaxy galaxy2("AlphaBetaCentavra", move(planets));

    Galaxy galaxy("AlphaBetaCentavra", list<Planet>{Planet("Earth", 1, 1), Planet("Venera", 2, 2)});
    galaxy.DeletePlanet(Planet("Earth", 1, 1));
    galaxy.AddPlanet(Planet("Saturn", 32, 23));
    cout << galaxy;

    cin.get();
}