#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item book;

    while (std::cin >> book)
    {
        /* code */
        std::cout << book << std::endl;
    }
}