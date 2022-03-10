#include <iostream>
#include <string>
#include <sstream>
#include "pen.h"

Pen::Pen() : weight() {}
Pen::Pen(std::string name, std::string manafacturer, std::string color, double weight)
    : name(name), manafacturer(manafacturer), color(color), weight(weight)
{
    if (weight < 0)
    {
        throw "Weight is negaative";
    }
    this->weight = weight;
}

void Pen::setName(const std::string name)
{
    if (name.empty() != true)
    {
        this->name = name;
    }
}

void Pen::setManafacturer(const std::string manafacturer)
{
    if (manafacturer.empty() != true)
    {
        this->manafacturer = manafacturer;
    }
}

void Pen::setColor(const std::string color)
{
    if (color.empty() != true)
    {
        this->color = color;
    }
}

void Pen::setWeight(double weight)
{
    if (weight < 0)
    {
        throw "Weight is negaative";
    }
    this->weight = weight;

    /*if (weight > 0.0)
        {
            this->weight = weight;
        }*/
}

const std::string& Pen::getName() const
{
    return name;
}

const std::string& Pen::getManafacturer() const
{
    return manafacturer;
}

const std::string& Pen::getColor() const
{
    return color;
}

double Pen::getWeight() const
{
    return weight;
}

std::string Pen::toString() const
{
    std::stringstream ss;
    using std::endl;
    ss << "Name: " << name << endl;
    ss << "Manafacturer: " << manafacturer << endl;
    ss << "Color: " << color << endl;
    ss << "Weight: " << weight << endl;
}



std::ostream& operator<<(std::ostream &out, const Pen &pen)
{
    using std::endl;
    out << "Name: " << pen.getName() << endl;
    out << "Manafacturer: " << pen.getManafacturer() << endl;
    out << "Color: " << pen.getColor() << endl;
    out << "Weight: " << pen.getWeight() << endl;

    return out;
}

std::istream& operator>>(std::istream &in, Pen &pen)
{
    double tmp;
    std::cout << "Enter name: ";
    getline(in, pen.name);

    std::cout << "Enter Manufacturer: ";
    getline(in, pen.manafacturer);

    std::cout << "Enter Color: ";
    getline(in, pen.color);

    std::cout << "Enter weight: ";
    in >> tmp;
    in.get();
    pen.setWeight(tmp);

    return in;
}