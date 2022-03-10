#include <iostream>
#include <list>
#include <string>
using namespace std;

class Planet
{
    string name;
    double weight;
    double radius;
    friend ostream &operator<<(ostream &out, const Planet pl);
    friend istream &operator>>(istream &in, Planet pl);

public:
    Planet() : weight(), radius() {}
    Planet(const string &name, const double weight, const double radius) : name(name), weight(), radius()
    {
        setWeight(weight);
        setRadius(radius);
    }

    void setWeight(const double weight)
    {
        if (weight < 0.0)
        {
            throw "Weight is negative\n";
        }
        this->weight = weight;
    }

    void setRadius(const double radius)
    {
        if (radius < 0.0)
        {
            throw "Radius is negative\n";
        }
        this->radius = radius;
    }

    void setName(const string &name)
    {
        this->name = name;
    }

    double getWeight() const
    {
        return weight;
    }

    double getRadius() const
    {
        return radius;
    }

    const string &getName() const
    {
        return name;
    }
};
bool operator==(const Planet &l, const Planet &r)
{
    return (l.getName() == r.getName() && l.getRadius() == r.getRadius() && l.getWeight() == r.getWeight());
}

ostream &operator<<(ostream &out, const Planet pl)
{
    out << "Name: " << pl.name << endl;
    out << "weight: " << pl.weight << "kg" << endl;
    out << "Radius: " << pl.radius << "km" << endl;

    return out;
}

istream &operator>>(istream &in, Planet pl)
{
    double tmpWeight;
    double tmpRadius;

    cout << "Enter name: ";
    getline(in, pl.name);

    cout << "Enter weight: ";
    in >> tmpWeight;
    pl.setWeight(tmpWeight);

    cout << "Enter radius: ";
    in >> tmpRadius;
    pl.setRadius(tmpRadius);
    in.get();

    return in;
}

class Galaxy
{
private:
    string name;
    list<Planet> planets;
    friend ostream &operator<<(ostream &out, const Galaxy &planet);

public:
    Galaxy() {}
    /*Galaxy(const string& name, list<Planet>& planets) : name(name)
    {
        for (auto& el : planets)
        {
            planets.push_back(el);
        }
    }*/

    Galaxy(const string &name, const list<Planet> &planets) : name(name), planets(planets) {}
    Galaxy(const string &name, list<Planet> &&planets) : name(name), planets(planets) {}

    void addPlanet(const Planet &planet)
    {
        planets.push_back(planet);
    }

    void deletePlanet(const Planet &planet)
    {
        for (auto i = planets.begin(); i != planets.end(); ++i)
        {
            if (i->getName() == planet.getName())
            {
                planets.erase(i);
                break;
            }
        }

        //for (auto el : planets)
        /*for (int i = 0; i < planets.size(); i++)
        {
            if (planet.getName() == 
            {

            }
            planets.remove(planet);
        }*/

        //planets.remove(planet);

        /*for (int i = 0; i < planets.size(); i++)
        {
            if (planet.getName() == planets[i].
        }*/
    }

    Planet &operator[](int pos)
    {
        try
        {

            for (auto &el : planets)
            {
                if (pos == 0)
                {
                    return el;
                }
                pos--;
            }
        }
        catch (...)
        {
        }
    }

    void setName(const string &name)
    {
        this->name = name;
    }

    const string &getName() const
    {
        return name;
    }
};

ostream &operator<<(ostream &out, const Galaxy &galaxy)
{
    out << "Galaxy: " << galaxy.name << endl;
    for (auto el : galaxy.planets)
    {
        out << el << endl;
        //out << "Name of planet: " << el.getName() << endl;
        //out << "Weight: " << el.getWeight() << endl;
        //out << "Radius: " << el.getRadius() << endl;
    }

    return out;
}

int main()
{
    //Planet p("Earth", 5972e24, 6400);
    //cout << p;

    list<Planet> planets;
    planets.push_back(Planet("Earth", 24, 54));
    planets.push_back(Planet("Saturn", 44, 64));

    Galaxy galaxy("AlphaBetaCentavra", planets);
    cout << galaxy << endl;

    galaxy.deletePlanet(Planet("Earth", 24, 54));
    galaxy.addPlanet(Planet("Jupiter", 66543, 14242));

    cout << galaxy << endl;
}