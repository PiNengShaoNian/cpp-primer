#include <iostream>
#include "SalesData.h"

using std::cerr;
using std::cin;
using std::cout;

int main()
{
    SalesData book1, book2;
    int price = 0;

    cin >> book1.bookNo >> book1.unitsSold >> price;
    book1.revenue = price * book1.unitsSold;
    cin >>
        book2.bookNo >> book2.unitsSold >> price;

    book2.revenue = price * book2.unitsSold;

    if (book1.bookNo == book2.bookNo)
    {
        cout << book2.bookNo << " " << book1.unitsSold + book2.unitsSold << " " << book1.revenue + book2.revenue << std::endl;
    }
    else
    {
        cerr << "bookNo must equal";
    }

    return 0;
}
