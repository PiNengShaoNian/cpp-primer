#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item result, book;

    while (std::cin >> book)
    {
        result += book;
    }

    std::cout << result << std::endl;

    return 0;
}