#include <string>

using namespace std;

struct SalesData
{
    string bookNo;
    unsigned units_sold;
    double revnue;

    string isbn()
    {
        return bookNo;
    }

    SalesData &combine(SalesData &book)
    {
        units_sold += book.units_sold;
        revnue += book.revnue;
        return *this;
    }
    /* data */
};
