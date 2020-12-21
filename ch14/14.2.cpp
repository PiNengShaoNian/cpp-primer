#include <string>
#include <iostream>

struct SalesData
{
    std::string sn;
    unsigned units_sold;
    double revenue;
    double price;
    friend std::istream &operator>>(std::istream &, SalesData &);
    friend std::ostream &operator<<(std::ostream &, SalesData &);
    friend SalesData operator+(SalesData &, SalesData &);

    SalesData &operator+=(SalesData &other)
    {
        if (other.sn == sn)
        {
            units_sold += other.units_sold;
            revenue = units_sold * price;
        }

        return *this;
    }
};

std::istream &operator>>(std::istream &in, SalesData &sd)
{
    in >> sd.sn >> sd.units_sold >> sd.price;

    if (in)
    {
        sd.revenue = sd.units_sold * sd.price;
        sd = SalesData();
    }

    return in;
}

std::ostream &operator<<(std::ostream &out, SalesData &sd)
{
    out << "sn: " << sd.sn << " units_sold: " << sd.units_sold << " price: " << sd.price << " revenue: " << sd.revenue;

    return out;
}

SalesData operator+(const SalesData &s1, const SalesData &s2)
{
    SalesData res(s1);

    if (s1.sn == s2.sn)
    {
        res.units_sold += s2.units_sold;
        res.revenue = res.units_sold * res.price;
    }

    return res;
}

int main()
{
    SalesData sd;
    while (std::cin >> sd)
    {
        std::cout << sd << std::endl;
    }
}
