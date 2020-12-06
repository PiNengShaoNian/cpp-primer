#include <iostream>

int main()
{
    int curVal = 0, val = 0;
    if (std::cin >> curVal)
    {
        int count = 1;

        while (std::cin >> val)
        {
            if (val == curVal)
            {
                count++;
            }
            else
            {
                std::cout << "number " << curVal << " occurs " << count << " times" << std::endl;
                curVal = val;
                count = 1;
            }
        }

        std::cout << "number " << curVal << " occurs " << count << " times" << std::endl;
    }
    return 0;
}