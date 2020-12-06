#include <iostream>

int main()
{
    int result = 0, value = 0;

    while (std::cin >> value)
    {
        result += value;
        /* code */
    }

    std::cout << "result is " << result;

    return 0;
}