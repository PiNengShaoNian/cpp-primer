#include <iostream>

int main()
{
    int result = 0, i = 50;

    while (i <= 100)
    {
        result += i;
        i++;
    }

    std::cout << result << std::endl;

    return 0;
}