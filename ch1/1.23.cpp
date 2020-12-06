#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item cur, value;

    if (std::cin >> cur)
    {
        int count = 1;

        while (std::cin >> value)
        {
            if (value.isbn() == cur.isbn())
            {
                count++;
            }
            else
            {
                std::cout << cur.isbn() << " occurs " << count << " times" << std::endl;
                cur = value;
                count = 1;
            }
        }

        std::cout << cur.isbn() << " occurs " << count << " times" << std::endl;
    }
    else
    {
        std::cerr << "no data!" << std::endl;
    }
    return 0;
}