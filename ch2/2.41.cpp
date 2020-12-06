#include <iostream>
#include "SalesData.h"

int main()
{
    SalesData book1, book2;
    int price = 0;

    std::cin >> book1.bookNo >> book1.unitsSold >> price;
    book1.revenue = price * book1.unitsSold;
    std::cin >>
        book2.bookNo >> book2.unitsSold >> price;

    book2.revenue = price * book2.unitsSold;

    if (book1.bookNo == book2.bookNo)
    {
        std::cout << book2.bookNo << " " << book1.unitsSold + book2.unitsSold << " " << book1.revenue + book2.revenue << std::endl;
    }
    else
    {
        std::cerr << "bookNo must equal";
    }

    return 0;
}
