#include <string>

class Pen
{
private:
    std::string name;
    std::string manafacturer;
    std::string color;
    double weight;
    friend std::ostream &operator<<(std::ostream &out, const Pen &pen);
    friend std::istream &operator>>(std::istream &in, Pen &pen);
public:
    Pen();
    Pen(std::string name, std::string manafacturer, std::string color, double weight);

    void setName(const std::string name);

    void setManafacturer(const std::string manafacturer);

    void setColor(const std::string color);

    void setWeight(double weight);

    const std::string& getName() const;

    const std::string& getManafacturer() const;

    const std::string& getColor() const;

    double getWeight() const;

    std::string toString() const;
};